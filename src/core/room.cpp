#include <core/room.h>

Room::Room(std::vector<std::vector<int>> map) {
  room_map_ = map;
}

std::vector<std::vector<int>> Room::getRoomMap() {
  return room_map_;
}

void Room::setRoomMap(std::vector<std::vector<int>> map) {
  room_map_ = map;
}

