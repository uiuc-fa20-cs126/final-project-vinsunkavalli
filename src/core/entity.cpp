#include <core/entity.h>

void Entity::setPosition(float posX, float posY){
  position_ = glm::vec2(posX, posY);
}

glm::vec2 Entity::getPosition(){
  return position_;
}