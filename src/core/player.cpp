#include <core/player.h>

Player::Player(float posX, float posY, float direction){
  Entity::setPosition(posX, posY);

  direction_ = direction;//made this configurable if necessary
}

float Player::getDirection() {
  return direction_;
}

void Player::setDirection(float direction) {
  direction_ = direction;
}
