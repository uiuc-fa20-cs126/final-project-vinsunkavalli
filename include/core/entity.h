#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_

class Entity{
 private:
  glm:vec2 position_;
 public:
  glm::vec2 getPosition();
  void setPosition(glm::vec2 newPos);

  void update(Room room);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ENTITY_H_
