#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_

#include <glm/glm.hpp>

class Entity{
 private:
  glm::vec2 position_;
 public:
  Entity();

  glm::vec2 getPosition();
  void setPosition(float posX, float posY);

  //virtual void update(Room room);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_
