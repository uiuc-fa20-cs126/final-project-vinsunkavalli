#ifndef FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_RAYCASTER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_RAYCASTER_H_

#include "cinder/gl/gl.h"
#include <core/room.h>
#include <core/player.h>
#include <core/enemy.h>

class Raycaster {
 public:
  Raycaster(glm::vec2 top_left_corner, size_t wall_height, double brush_width, size_t window_width);
  void Raycast(Room & room, Player & player);
  void Raycast(Room &room, Player &player, std::vector<Enemy> &enemies);
  void RaycastEnemies(std::vector<Enemy> &enemies);
 private:
  glm::vec2 top_left_corner_;

  size_t wall_height_;

  double brush_width_;
  size_t window_width_;

};

#endif //FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_RAYCASTER_H_
