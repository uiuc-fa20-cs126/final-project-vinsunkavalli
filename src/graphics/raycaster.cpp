#include <graphics/raycaster.h>
#include <math.h>

Raycaster::Raycaster(glm::vec2 top_left_corner, size_t wall_height, double brush_width, size_t window_width)
  : top_left_corner_(top_left_corner),
    wall_height_(wall_height),
    brush_width_(brush_width),
    window_width_(window_width){
  //If necessary, initialize variables here
}

void Raycaster::Raycast(Room room, Player player){
  size_t x = 0;
  //std::vector<int> ray_distances();

  std::vector<std::vector<char>> room_map = room.getRoomMap();

  glm::vec2 playerDir = glm::vec2(-1, 0);

  //glm::vec2 planePos = glm::vec2(0, 0.33);

  while (x <= window_width_){
    //double cameraX = 2 * x/(brush_width_);

    double angle = ((float)x)/((float)window_width_);

    glm::vec2 rayPos = player.getPosition();
    glm::vec2 rayDir = glm::vec2((playerDir.x - (float) cos(1) + (float) cos(2*angle)), (playerDir.y - (float) sin(1) + (float) sin(2*angle)));
/*
    glm::vec2 mapPos = floor(rayPos);

    glm::vec2 deltaDist;// = glm::vec2(1 + pow(rayDir.y, 2)/pow(rayDir.x, 2), 1 + pow(rayDir.x, 2)/pow(rayDir.y, 2));

    deltaDist.x = (rayDir.y == 0) ? 0 : ((rayDir.x == 0) ? 1 : abs(1 / rayDir.x));
    deltaDist.y = (rayDir.x == 0) ? 0 : ((rayDir.y == 0) ? 1 : abs(1 / rayDir.y));
*/
    glm::vec2 step = 0.01f * rayDir;
/*
    step.x = (rayDir.x < 0) ? (-1.0f) : (1.0f);
    step.y = (rayDir.y < 0) ? (-1.0f) : (1.0f);

    glm::vec2 sideDist;

    sideDist.x = (rayDir.x < 0) ? ((rayPos.x - mapPos.x) * deltaDist.x) : ((mapPos.x + 1 - rayPos.x) * deltaDist.x);
    sideDist.y = (rayDir.y < 0) ? ((rayPos.y - mapPos.y) * deltaDist.y) : ((mapPos.y + 1 - rayPos.y) * deltaDist.y);

    bool horizHit;

    while(room_map[(int) mapPos.y][(int) mapPos.x] != '#') {
      if(sideDist.x < sideDist.y) {
        sideDist.x += deltaDist.x;
        mapPos.x += step.x;
        horizHit = true;
      }else {
        sideDist.y += deltaDist.y;
        mapPos.y += step.y;
        horizHit = false;
      }
    }

    //double perpDist = (horizHit) ? abs(((mapPos.x - rayPos.x) + (1 - step.x/2))/rayDir.x) : abs(((mapPos.y - rayPos.y) + (1 - step.y/2))/rayDir.y);
    double perpDist = glm::distance(rayPos, player.getPosition());
*/

    while(room_map[(int) rayPos.y][(int) rayPos.x] != '#') {
      rayPos += step;
    }

    double perpDist = glm::distance(rayPos, player.getPosition());

    double draw_height = wall_height_/(perpDist);
    double gap = (wall_height_ - draw_height)/2;

    ci::gl::color(ci::Color("blue"));

    ci::gl::drawSolidRect(ci::Rectf(glm::vec2((float) x, (gap)), glm::vec2(x + brush_width_, (draw_height + gap))));

    x += (int) brush_width_;
  }
}