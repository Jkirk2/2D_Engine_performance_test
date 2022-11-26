



#include "ball.h"
#include "util.h"
#include <simple2d.h>
#include <random>
Ball::Ball(float x, float y)
{
      // v1 in the range 0 to 99
  

  this->x = x;
  this->y = y;
  this->xSpeed = ((rand() % 200) - 100) * .01;
  this->ySpeed = ((rand() % 200) - 100) * .01;
  this->radius = 1;
}
void Ball::update()
{
  this->x += xSpeed;
  this->y += ySpeed;
  if (x > screenWidth + radius)
  {
    
    xSpeed = -xSpeed;
  }
  else if (x < 0 - radius)
  {
    xSpeed = -xSpeed;
  }
  if (y > screenHeight + radius)
  {
    ySpeed = -ySpeed;
  }
  else if (y < 0 - radius)
  {
    ySpeed = -ySpeed;
  }
}

void Ball::render(){
  S2D_DrawCircle(x, y, radius, 5, 1, 0, 1, 1);
}

