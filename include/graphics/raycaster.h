#ifndef FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_RAYCASTER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_RAYCASTER_H_

#include "cinder/gl/gl.h"
#include <core/room.h>
#include <core/player.h>
#include <core/enemy.h>

class Raycaster {
 public:
  /**
   * Raycaster is a helper class to draw objects with depth
   *
   * Raycasting is a pseudo-3D rendering method where the z-axis (height) is proportional to distance/depth
   *
   * @param top_left_corner - top left coordinate of the window
   * @param wall_height - height of the walls rendered
   * @param brush_width - width of brush used for rendering
   * @param window_width - width of the window
   */
  Raycaster(glm::vec2 top_left_corner, size_t wall_height, double brush_width, size_t window_width);

  /**
   * Renders walls of the room the player is in
   *
   * @param room - room object
   * @param player - player entity object
   */
  void Raycast(Room & room, Player & player);

  /**
   * Renders the enemies in the same room as the player
   *
   * @param player - player entity object
   * @param enemies - list of enemy entity objects
   */
  void RaycastEnemies(Player &player, std::vector<Enemy> &enemies);
 private:
  glm::vec2 top_left_corner_;

  size_t wall_height_;

  double brush_width_;
  size_t window_width_;

  size_t enemy_height_;//height of the enemy - coded as a function of wall height

  const float kEnemySize = 0.4f; //width of the enemy
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_RAYCASTER_H_
