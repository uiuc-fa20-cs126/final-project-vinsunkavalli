#ifndef FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_
#define FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_

#include <core/entity.h>
#include <core/enemy.h>
#include <core/player.h>
#include <core/room.h>

#include <cinder/app/App.h>

class GameEngine{
 public:
  /**
   * Game Engine is a class meant to handle things necessary for gameplay (ie entities, player input, etc.)
   */
   GameEngine();

   /**
    * Updates state of the game depending on player input (or lack thereof)
    *
    * @param event - player input, -1 means that there is no input
    */
  void update(int event);

  //getter methods
  Room& getRoom();
  Player& getPlayer();
  std::vector<Enemy> &getEnemies();

  //these are made public in case a future class needs to alter them
  bool gameOver;//whether lose/win condition has been met
  int score;//player's score
 private:
  Room room_;//room obj
  Player player_;//player obj
  std::vector<Enemy> enemies_;//list of enemy objs

  const int kEnemies = 3;//number of enemies to spawn
  const float kMvmtSpeed = 0.1f;//player and enemy movement speed
  const float kRotSpeed = 0.1f;//player rotation speed

  const std::string kFilePath = "C:\\Users\\buddi\\Cinder\\my-projects\\final-project-vinsunkavalli\\resources\\testroom";//filepath for room
};

#endif //FINAL_PROJECT_INCLUDE_CORE_GAMEENGINE_H_
