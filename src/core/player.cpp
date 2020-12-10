#include <core/player.h>

Player::Player(float posX, float posY, float dirX, float dirY){
  if(posX < 0 || posY < 0) {
    throw std::invalid_argument("Invalid Position");
  }

  Entity::setPosition(posX, posY);

  direction_ = glm::vec2(dirX, dirY);//made this configurable if necessary
}

glm::vec2 & Player::getDirection() {
  return direction_;
}

void Player::setDirection(float dirX, float dirY) {
  direction_ = glm::vec2(dirX, dirY);
}
