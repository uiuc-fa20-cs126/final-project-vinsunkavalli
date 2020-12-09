#include <core/room.h>

Room::Room() {
  room_map_ = std::vector<std::vector<char>>();
  bounds_ = glm::vec2(0, 0);
}

Room::Room(std::vector<std::vector<char>> map) {
  setRoomMap(map);
}

std::vector<std::vector<char>> & Room::getRoomMap() {
  return room_map_;
}

glm::vec2 & Room::getRoomBounds() {
  return bounds_;
}

void Room::setRoomMap(std::vector<std::vector<char>> map) {
  if(map.size() == 0) {
    throw std::invalid_argument("map is invalid(empty)");
  }

  room_map_ = map;

  setRoomBounds((float) map.size(), (float) map[0].size());
}

void Room::setRoomBounds(float boundX, float boundY) {
  bounds_ = glm::vec2(boundX, boundY);
}

std::istream& operator>>(std::istream& in, Room& room) {
  std::string row_string;
  std::vector<std::vector<char> > new_map;
  float boundX, boundY;

  if(!in) {
    throw std::invalid_argument("invalid file");
  }

  //first two lines are always width then height
  std::getline(in, row_string);
  boundX = std::stof(row_string);
  std::getline(in, row_string);
  boundY = std::stof(row_string);

  //convert characters to different room info
  for(auto i = 0; i < boundY; ++i) {
    std::vector<char> map_row;
    std::getline(in, row_string);

    for(auto j = 0; j < boundX; ++j) {
      char roomTile = row_string.at(j);
      map_row.push_back(roomTile);
    }

    new_map.push_back(map_row);
  }

  room.setRoomMap(new_map);

  return in;
}
