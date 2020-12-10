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

  bool gameOver;
  int score;

  void update(int event);

  Room& getRoom();
  Player& getPlayer();
  std::vector<Enemy> &getEnemies();

 private:
  Room room_;
  Player player_;
  std::vector<Enemy> enemies_;

  const int kEnemies = 3;//number of enemies to spawn
  const float kMvmtSpeed = 0.1f;//player and enemy movement speed
  const float kRotSpeed = 0.1f;//player rotation speed

  const std::string kFilePath = "C:\\Users\\buddi\\Cinder\\my-projects\\final-project-vinsunkavalli\\resources\\testroom";
};

#endif //FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_
