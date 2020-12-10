#ifndef FINAL_PROJECT_INCLUDE_CORE_ENEMY_H_
#define FINAL_PROJECT_INCLUDE_CORE_ENEMY_H_

#include <core/entity.h>

class Enemy : public Entity{
 public:
  /**
   * Enemy class is an entity - there are no modifications, but it's designed to be extensible should the need arise
   * @param posX - position x value
   * @param posY - position y value
   */
  Enemy(float posX, float posY);
};

#endif //FINAL_PROJECT_INCLUDE_CORE_ENEMY_H_
