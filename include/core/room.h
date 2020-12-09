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
 private:
  std::vector<std::vector<char>> room_map_;
  glm::vec2 bounds_;
 public:
  Room();
  Room(std::vector<std::vector<char>> map);

  std::vector<std::vector<char>> & getRoomMap();
  glm::vec2 & getRoomBounds();

  void setRoomMap(std::vector<std::vector<char>> map);
  void setRoomBounds(float boundX, float boundY);

  friend std::istream& operator>>(std::istream& in, Room& room);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_