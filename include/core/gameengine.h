#ifndef FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_
#define FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_

#include <core/entity.h>
#include <core/enemy.h>
#include <core/player.h>
#include <core/room.h>

#include <cinder/app/App.h>

class GameEngine{
 public:
  GameEngine();

  void update(int event);

  Room& getRoom();
  Player& getPlayer();
 private:
  Room room_;
  Player player_;
  std::vector<Enemy> enemies_;

  bool gameOver;
  int score;

  const int kEnemies = 3;//number of enemies to spawn
  const float kMvmtSpeed = 0.1f;//player and enemy movement speed
  const float kRotSpeed = 0.1f;//player rotation speed
};

#endif //FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_
