#include <graphics/game.h>

Game::Game()
  : raycaster_(glm::vec2(0, 0), 480, 1, 480),
    game_engine_(){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

}

void Game::draw() {
  //render background
  ci::gl::color(ci::Color("black"));
  ci::gl::clear();

  //render map - call raycast
  raycaster_.Raycast(game_engine_.getRoom(), game_engine_.getPlayer());
  //TODO render enemies

  //Debug Info - Remove for final project
/*  Player player_ = game_engine_.getPlayer();
  Room room_ = game_engine_.getRoom();
  ci::gl::drawString("player position: " + std::to_string(player_.getPosition().x) + "," + std::to_string(player_.getPosition().y), glm::vec2(0,0));
  ci::gl::drawString("player direction: " + std::to_string(player_.getDirection().x) + "," + std::to_string(player_.getDirection().y), glm::vec2(0,10));
  ci::gl::drawString("player angle: " + std::to_string(atan2(player_.getDirection().y, player_.getDirection().x)), glm::vec2(0,20));
*/
}

void Game::update() {
  //TODO update enemy locations
  game_engine_.update(-1);
}

void Game::keyDown(ci::app::KeyEvent event) {
  game_engine_.update(event.getCode());
}