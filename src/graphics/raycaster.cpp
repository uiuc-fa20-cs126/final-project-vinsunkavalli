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

  std::vector<std::vector<char>> room_map = room.getRoomMap();

  glm::vec2 playerDir = player.getDirection();


  while (x <= window_width_){

    double angle = ((float)x)/((float)window_width_);

    glm::vec2 rayPos = player.getPosition();
    glm::vec2 rayDir = glm::vec2((playerDir.x - (float) cos(0.5) + (float) cos(angle)), (playerDir.y - (float) sin(0.5) + (float) sin(angle)));

    glm::vec2 step = 0.01f * rayDir;

    while(room_map[(int) rayPos.y][(int) rayPos.x] != '#') {
      rayPos += step;
    }

    std::cout << rayPos.x << ', ' << rayPos.y << std::endl;

    float perpDist = glm::distance(rayPos, player.getPosition());

    float draw_height = 2.0f * ((float) wall_height_)/(perpDist);
    float gap = ((float) wall_height_ - draw_height)/2;

    ci::gl::color(0.0f, 0.0f, 1.0f, 1.0f/perpDist);

    ci::gl::drawSolidRect(ci::Rectf(glm::vec2((float) x, (gap)), glm::vec2(x + brush_width_, (draw_height + gap))));

    x += (int) brush_width_;
  }
}