#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_

#include <core/entity.h>
#include <vector>

class Player: public Entity{
 public:
  /**
   * Player class represents player entity - handled differently from other entities
   *
   * @param posX - position x value
   * @param posY - position y value
   * @param dirX - direction cos value
   * @param dirY - direction sin value
   */
  Player(float posX, float posY, float dirX, float dirY);

  //getter methods - no need to add position functions/variables as entity already contains them
  glm::vec2 & getDirection();
  void setDirection(float dirX, float dirY);
 private:
  glm::vec2 direction_;//direction of player in vector format
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
