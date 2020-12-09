#include <core/gameengine.h>

GameEngine::GameEngine() :
    player_(1.0f, 1.0f, 1.0f, 0.0f){
  room_ = Room();

  std::ifstream room_map("C:\\Users\\buddi\\Cinder\\my-projects\\final-project-vinsunkavalli\\resources\\testroom", std::ios::in);
  room_map >> room_;

  score = 0;
  gameOver = false;

  enemies_ = std::vector<Enemy>();

  //TODO Create enemies with randomized locations within room
  while(enemies_.size() < (unsigned) kEnemies) {
    Enemy enemy((rand() % 100)/100.0f * room_.getRoomBounds().x, (rand() % 100)/100.0f * room_.getRoomBounds().y);

    if(room_.getRoomMap()[(int) enemy.getPosition().y][(int) enemy.getPosition().x] != '#'){
      enemies_.push_back(enemy);
    }
  }
}

void GameEngine::update(int event) {
  switch(event){
    case ci::app::KeyEvent::KEY_a: {
      float angle = atan2(player_.getDirection().y, player_.getDirection().x);

      angle += kRotSpeed;

      glm::vec2 dir = glm::vec2(cos(angle), sin(angle));

      player_.setDirection(dir.x, dir.y);
      break;
    }
    case ci::app::KeyEvent::KEY_d: {
      float angle = atan2(player_.getDirection().y, player_.getDirection().x);

      angle -= kRotSpeed;

      glm::vec2 dir = glm::vec2(cos(angle), sin(angle));

      player_.setDirection(dir.x, dir.y);
      break;
    }
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
    case ci::app::KeyEvent::KEY_SPACE:
      //TODO Code attack animation to kill enemies
      for(auto i = enemies_.begin(); i != enemies_.end(); ++i) {
        Enemy enemy = *i;


        if(glm::distance(enemy.getPosition(), player_.getPosition()) < 1.5) {
          //TODO draw rectangle animation
          enemies_.erase(i);
          --i;
        }
      }

      break;
    case -1: {
      //TODO Make enemies move towards player
      for(size_t i = 0; i < enemies_.size(); ++i) {
        Enemy enemy = enemies_.at(i);

        glm::vec2 newPos = (player_.getPosition() - enemy.getPosition()) * kMvmtSpeed;

        enemy.setPosition(newPos.x, newPos.y);
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

