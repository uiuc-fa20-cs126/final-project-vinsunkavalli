#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <core/room.h>
#include <core/player.h>

std::string kTestRoomPath = "C:\\Users\\buddi\\Cinder\\my-projects\\final-project-vinsunkavalli\\resources\\testroom";

TEST_CASE("Loading Map") {
  SECTION("Creating an empty room") {
    Room map = Room();

    REQUIRE(map.getRoomMap().size() == 0);
  }

  SECTION("Creating a room from a vector map") {
    std::vector<std::vector<char>> room_map (1, std::vector<char> ('#'));
    Room map = Room(room_map);

    REQUIRE(map.getRoomMap().size() == 1);
  }

  SECTION("Creating a room w/ operator overloading") {
    Room map = Room();

    std::ifstream room_map(kTestRoomPath, std::ios::in);

    room_map >> map;

    REQUIRE(map.getRoomMap().size() == 10);
  }

  SECTION("Creating a room from an invalid file") {
    Room map = Room();

    std::ifstream room_map("not_a_real_file", std::ios::in);

    REQUIRE_THROWS_AS(room_map >> map, std::invalid_argument);//figure out how to do this

  }

  SECTION("Creating a room from an invalid vector") {
    std::vector<std::vector<char>> room_map = std::vector<std::vector<char>>();

    REQUIRE_THROWS_AS(Room(room_map), std::invalid_argument);//doesn't accept empty vector as that is what default constructor is for
  }
}


//TODO put this in the main test
TEST_CASE("Interacting with the Map") {
  std::ifstream room_map(kTestRoomPath, std::ios::in);
  //setting up game map
  Room map = Room();
  room_map >> map;

  //setting up player
  Player player = Player(1.5, 1.5, 1.0f, 1.0f);

  SECTION("Checking bounds of map") {
    REQUIRE(map.getRoomBounds() == glm::vec2(10, 10));
  }

}