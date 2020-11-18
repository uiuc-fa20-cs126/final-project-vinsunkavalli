#include <core/player.h>

Player::Player(float posX, float posY, float direction){
  setPosition(posX, posY);

  velocity_ = glm::vec2(0.0f, 0.0f);//don't want the character moving when the game starts
  direction_ = direction;//made this configurable if necessary
}

glm::vec2 Player::getVelocity() {
  return velocity_;
}

float Player::getDirection() {
  return direction_;
}

void Player::setVelocity(float velX, float velY) {
  velocity_ = glm::vec2(velX, velY);
}

void Player::setDirection(float direction) {
  direction_ = direction;
}

void Player::addItem(char item) {
  inventory_.push_back(item);
}

char Player::removeItem(char item) {
  auto itr = inventory_.begin();

  while (itr != inventory_.end()){
    if (*itr == item) {
      itr = inventory_.erase(itr);
    }
    else {
      itr++;
    }
  }
}