#ifndef FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
#define FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_

 class Player: public Entity{
 private:
  glm::vec2 velocity;
  float direction;
 public:
  Player(float posX, float posY, float direction);

  glm::vec2 getVelocity();
  void setVelocity(float velX, float velY);
};

#endif //FINAL_PROJECT_VINSUNKAVALLI_ENGINE_INCLUDE_CORE_PLAYER_H_
