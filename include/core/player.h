#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_

#include <core/entity.h>
#include <vector>

class Player: public Entity{
 private:
  float direction_;//from 0 to 360
 public:
  Player(float posX, float posY, float direction=0.0f);

  //no need to add position functions/variables as entity already contains them
  float getDirection();
  void setDirection(float direction);

  //void update(Room room) override;
  //haven't coded items yet so item functions for inventory haven't been coded
  //TODO Code Item functions
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
