#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <glm/glm.hpp>

class Room{
 private:
  std::vector<std::vector<int>> room_map_;

  glm::vec2 bounds;
 public:
  Room();
  Room(std::vector<std::vector<int>> map);

  std::vector<std::vector<int>> getRoomMap();

  void setRoomMap(std::vector<std::vector<int>> map);

  friend std::istream& operator>>(std::istream& in, Room& room);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_