#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_

class Room{
 private:
  std::vector<std::vector<int>> room_map_;

  glm::vec2 bounds;
 public:
  Room();
  Room(std::vector<std::vector<int>> map);

  friend std::istream& operator>>(std::istream& in, const Room& room);

  std::vector<std::vector<int>> getRoomMap();

  void setRoomMap(std::vector<std::vector<int>> map);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_