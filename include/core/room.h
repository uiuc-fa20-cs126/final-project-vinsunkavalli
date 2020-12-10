#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>
#include "player.h"

class Room{
 public:
  /**
   * Room class is meant to create a vector representation of game map
   */
  Room();
  Room(std::vector<std::vector<char>> map);

  ///getter methods
  std::vector<std::vector<char>> & getRoomMap();
  glm::vec2 & getRoomBounds();

  ///setter methods
  void setRoomMap(std::vector<std::vector<char>> map);
  void setRoomBounds(float boundX, float boundY);

  ///operator overload
  friend std::istream& operator>>(std::istream& in, Room& room);
 private:
  std::vector<std::vector<char>> room_map_;
  glm::vec2 bounds_;
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_