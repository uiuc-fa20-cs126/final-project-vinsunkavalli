#include <graphics/game.h>

Game::Game()
  : raycaster_(glm::vec2(0, 0), 480, 1, 480),
    player_(4, 4, -1, 0){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

  //setup environment
  room_ = Room();

  std::ifstream room_map("C:\\Users\\buddi\\Cinder\\my-projects\\final-project-vinsunkavalli\\resources\\testroom", std::ios::in);
  room_map >> room_;


}

void Game::draw() {
  //render background
  ci::gl::color(ci::Color("black"));
  ci::gl::clear();

  //render map - call raycast
  raycaster_.Raycast(room_, player_);
  //TODO render player model and gui
  ci::gl::drawString("player position: " + std::to_string(player_.getPosition().x) + "," + std::to_string(player_.getPosition().y), glm::vec2(0,0));
  ci::gl::drawString("player direction: " + std::to_string(player_.getDirection().x) + "," + std::to_string(player_.getDirection().y), glm::vec2(0,10));
  ci::gl::drawString("player angle: " + std::to_string(atan2(player_.getDirection().y, player_.getDirection().x)), glm::vec2(0,20));
}

void Game::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_a: {
      float angle = atan2(player_.getDirection().y, player_.getDirection().x);

      angle += 0.1f;

      glm::vec2 dir = glm::vec2(cos(angle), sin(angle));

      player_.setDirection(dir.x, dir.y);
      break;
    }
    case ci::app::KeyEvent::KEY_d: {
      float angle = atan2(player_.getDirection().y, player_.getDirection().x);

      angle -= 0.1f;

      glm::vec2 dir = glm::vec2(cos(angle), sin(angle));

      player_.setDirection(dir.x, dir.y);
      break;
    }
    case ci::app::KeyEvent::KEY_w: {
      glm::vec2 pos = player_.getPosition();
      glm::vec2 dir = player_.getDirection();

      pos = glm::vec2(pos.x + dir.x * 0.1, pos.y + dir.y * 0.1);

      std::vector<std::vector<char>> map = room_.getRoomMap();

      if(map[(int) pos.y][(int) pos.x] != '#') {
        player_.setPosition(pos.x, pos.y);
      }

      break;
    }
    case ci::app::KeyEvent::KEY_s: {
      glm::vec2 pos = player_.getPosition();
      glm::vec2 dir = player_.getDirection();

      pos = glm::vec2(pos.x + dir.x * -0.1, pos.y + dir.y * -0.1);

      std::vector<std::vector<char>> map = room_.getRoomMap();

      if(map[(int) pos.y][(int) pos.x] != '#') {
        player_.setPosition(pos.x, pos.y);
      }

      break;
    }
  }
}