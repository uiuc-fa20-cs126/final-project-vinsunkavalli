#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_

#include "entity.h"
#include <vector>

class Player: public Entity{
 private:
  glm::vec2 velocity_;
  float direction_;//from 0 to 360

  std::vector<char> inventory_;
 public:
  Player(float posX, float posY, float direction=0.0f);

  glm::vec2 getVelocity();
  float getDirection();

  void setVelocity(float velX, float velY);
  void setDirection(float direction);

  void addItem(char item);
  char removeItem(char item);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
