#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_

class Room{
 private:
  std::vector<std::vector<int>> room_map_;
 public:
  std::vector<std::vector<int>> getCurrentRoomMap();
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_ROOM_H_