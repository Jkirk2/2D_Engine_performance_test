#ifndef ball_H
#define ball_H
class Ball
{
public:
  float x;
  float y;
  float xSpeed;
  float ySpeed;
  float radius;
  Ball(float, float);

  void update();
  void render();
};
#endif