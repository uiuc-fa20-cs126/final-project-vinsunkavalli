//
// Created by buddi on 12/8/2020.
//
#include <core/enemy.h>

Enemy::Enemy(float posX, float posY, float speed) {
  speed_ = speed;
  Entity::setPosition(posX,  posY);
}