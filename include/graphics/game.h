#ifndef FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_GAME_H_
#define FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_GAME_H_

#include <core/room.h>
#include <core/player.h>
#include <core/enemy.h>
#include <graphics/raycaster.h>

#include <cinder/app/App.h>
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <glm/gtx/io.hpp>

class Game : public ci::app::App {
 public:
  Game();

  void draw() override;
  //void update() override;

  //void mouseDown(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;
 private:
  Room room_;
  Player player_;
  Raycaster raycaster_;

  std::vector<Enemy> enemies_;
  int score;

  float kWindowSize = 480;
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_INCLUDE_GRAPHICS_GAME_H_
