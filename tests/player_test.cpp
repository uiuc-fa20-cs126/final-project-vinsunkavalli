#include <catch2/catch.hpp>
#include <core/player.h>

//originally had more tests but lost my test cases when creating a new checkout branch
TEST_CASE("Player Set Up") {
  SECTION("Create player") {
    REQUIRE_NOTHROW(Player(0, 0, 0, 1));
  }

  SECTION("Create player with invalid position") {
    REQUIRE_THROWS_AS(Player(-1, -1, 0, 1), std::invalid_argument);
  }
}