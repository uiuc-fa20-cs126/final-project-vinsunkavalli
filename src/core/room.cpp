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

std::istream& operator>>(std::istream& in, Room& room) {
  std::string row_string;
  std::vector<std::vector<int> > new_map;
  float boundX, boundY;

  //first two lines are always width then height
  std::getline(in, row_string);
  boundX = std::stof(row_string);
  std::getline(in, row_string);
  boundY = std::stof(row_string);

  for(auto i = 0; i < boundY; ++i) {
    std::vector<int> map_row;
    std::getline(in, row_string);
    for(auto j = 0; j < boundX; ++j) {
      std::string num = reinterpret_cast<const char *>(row_string.at(j));
      map_row.push_back(std::stoi(num));
    }

    new_map.push_back(map_row);
  }

  room.setRoomMap(new_map);

  return in;
}
