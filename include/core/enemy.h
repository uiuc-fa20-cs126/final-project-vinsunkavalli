#ifndef FINAL_PROJECT_INCLUDE_CORE_ENEMY_H_
#define FINAL_PROJECT_INCLUDE_CORE_ENEMY_H_

#include <core/entity.h>

class Enemy : public Entity{
 private:
  float speed_;
 public:
  Enemy(float posX, float posY, float speed);
};

#endif //FINAL_PROJECT_INCLUDE_CORE_ENEMY_H_
