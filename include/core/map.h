#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_MAP_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_MAP_H_

class Map{
 private:
  std::vector<Room> rooms_;
 public:
  Room getCurrentRoom();
  std::vector<std::vector<int>> getCurrentRoomMap();
  void changeCurrentRoom();
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_MAP_H_
