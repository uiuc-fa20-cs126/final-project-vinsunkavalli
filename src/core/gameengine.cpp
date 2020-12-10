#include <core/gameengine.h>

GameEngine::GameEngine() :
    player_(2.0f, 2.0f, 1.0f, 0.0f){
  room_ = Room();

  std::ifstream room_map(kFilePath, std::ios::in);
  room_map >> room_;

  score = 0;
  gameOver = false;

  enemies_ = std::vector<Enemy>();

  while(enemies_.size() < (unsigned) kEnemies) {
    Enemy enemy((rand() % 100)/100.0f * room_.getRoomBounds().x, (rand() % 100)/100.0f * room_.getRoomBounds().y);

    if(room_.getRoomMap()[(int) enemy.getPosition().y][(int) enemy.getPosition().x] != '#' && glm::distance(enemy.getPosition(), player_.getPosition()) > 1.5){
      enemies_.push_back(enemy);
    }
  }
}

void GameEngine::update(int event) {
  switch(event){
    //Turn left
    case ci::app::KeyEvent::KEY_a: {
      float angle = atan2(player_.getDirection().y, player_.getDirection().x);

      angle += kRotSpeed;

      glm::vec2 dir = glm::vec2(cos(angle), sin(angle));

      player_.setDirection(dir.x, dir.y);
      break;
    }
    //Turn right
    case ci::app::KeyEvent::KEY_d: {
      float angle = atan2(player_.getDirection().y, player_.getDirection().x);

      angle -= kRotSpeed;

      glm::vec2 dir = glm::vec2(cos(angle), sin(angle));

      player_.setDirection(dir.x, dir.y);
      break;
    }
    //Move forwards
    case ci::app::KeyEvent::KEY_w: {
      glm::vec2 pos = player_.getPosition();
      glm::vec2 dir = player_.getDirection();

      pos = pos + dir * kMvmtSpeed;

      std::vector<std::vector<char>> map = room_.getRoomMap();

      if(map[(int) pos.y][(int) pos.x] != '#') {
        player_.setPosition(pos.x, pos.y);
      }

      break;
    }
    //Move backwards
    case ci::app::KeyEvent::KEY_s: {
      glm::vec2 pos = player_.getPosition();
      glm::vec2 dir = player_.getDirection();

      pos = pos - dir * kMvmtSpeed;

      std::vector<std::vector<char>> map = room_.getRoomMap();

      if(map[(int) pos.y][(int) pos.x] != '#') {
        player_.setPosition(pos.x, pos.y);
      }

      break;
    }
    //Player attack
    case ci::app::KeyEvent::KEY_SPACE: {
      std::vector<Enemy> newEnemyList;

      for(size_t i = 0; i < enemies_.size(); ++i) {
        Enemy enemy = enemies_.at(i);

        if(glm::distance(enemy.getPosition(), player_.getPosition()) < 1.5) {
          bool replaced = false;

          while(!replaced) {
            glm::vec2 newPos((rand() % 100)/100.0f * room_.getRoomBounds().x, (rand() % 100)/100.0f * room_.getRoomBounds().y);

            if(room_.getRoomMap()[(int) newPos.y][(int) newPos.x] != '#' && glm::distance(newPos, player_.getPosition()) > 3){
              enemies_.at(i).setPosition(newPos.x, newPos.y);
              replaced = true;
            }
          }
        }

        score++;
      }

      break;
    }
    //Default case - used to update enemy behavior
    case -1: {
      for(size_t i = 0; i < enemies_.size(); ++i) {
        Enemy enemy = enemies_.at(i);
        glm::vec2 newPos = enemy.getPosition() + (player_.getPosition() - enemy.getPosition()) * kMvmtSpeed * 0.33f;

        enemies_.at(i).setPosition(newPos.x, newPos.y);

        if(glm::distance(newPos, player_.getPosition()) < 0.5) {
          gameOver = true;
        }
      }

      break;
    }
  }
}

Player & GameEngine::getPlayer() {
  return player_;
}

Room & GameEngine::getRoom() {
  return room_;
}

std::vector<Enemy> & GameEngine::getEnemies() {
  return enemies_;
}

