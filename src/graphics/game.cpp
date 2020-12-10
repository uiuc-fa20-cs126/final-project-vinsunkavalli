#include <graphics/game.h>

Game::Game()
  : raycaster_(glm::vec2(0, 0), 512, 1, 512),
    game_engine_(){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

}

void Game::draw() {
  //render background
  ci::gl::color(ci::Color("black"));
  ci::gl::clear();

  if(!game_engine_.gameOver){
    //render map - call raycast
    raycaster_.Raycast(game_engine_.getRoom(), game_engine_.getPlayer());
    //TODO render enemies
    raycaster_.RaycastEnemies(game_engine_.getPlayer(), game_engine_.getEnemies());

    if(attack > 0) {
      ci::gl::color(ci::Color("red"));
      ci::gl::drawSolidRect(ci::Rectf(glm::vec2(0.0f, 246.0f), glm::vec2(512.0f, 266.0f)));

      attack--;
    }

    //Debug Info - Remove for final project
    Player player_ = game_engine_.getPlayer();
    Room room_ = game_engine_.getRoom();
    Enemy enemy1 = game_engine_.getEnemies()[0];
    ci::gl::drawString("player position: " + std::to_string(player_.getPosition().x) + "," + std::to_string(player_.getPosition().y), glm::vec2(0,0));
    ci::gl::drawString("player direction: " + std::to_string(player_.getDirection().x) + "," + std::to_string(player_.getDirection().y), glm::vec2(0,10));
    ci::gl::drawString("player angle: " + std::to_string(atan2(player_.getDirection().y, player_.getDirection().x)), glm::vec2(0,20));
    ci::gl::drawString("enemy location 1: " + std::to_string(enemy1.getPosition().x) + "," + std::to_string(enemy1.getPosition().y), glm::vec2(0,30));
  }else {
    ci::gl::drawStringCentered("Score: " + std::to_string(game_engine_.score), glm::vec2((float) kWindowSize/2, (float) kWindowSize/2));
  }
}

void Game::update() {
  if(!game_engine_.gameOver) {
    game_engine_.update(-1);
  }
}

void Game::keyDown(ci::app::KeyEvent event) {
  if(!game_engine_.gameOver) {
    game_engine_.update(event.getCode());
    switch(event.getCode()){
      case ci::app::KeyEvent::KEY_SPACE: {
        attack = 6;
        break;
      }
    }
  }
}