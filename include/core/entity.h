#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_

#include <glm/glm.hpp>

class Entity{
 public:
  /**
   * Entity class is shell class for all game entities
   */
  Entity();

  //getter and setter for position
  glm::vec2 & getPosition();
  void setPosition(float posX, float posY);
 private:
  glm::vec2 position_;
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_
