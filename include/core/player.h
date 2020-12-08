#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_

#include <core/entity.h>
#include <vector>

class Player: public Entity{
 private:
  glm::vec2 direction_;
 public:
  Player(float posX, float posY, float dirX, float dirY);

  //no need to add position functions/variables as entity already contains them
  glm::vec2 getDirection();
  void setDirection(float dirX, float dirY);

  //void update(Room room) override;
  //haven't coded items yet so item functions for inventory haven't been coded
  //TODO Code Item functions
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
