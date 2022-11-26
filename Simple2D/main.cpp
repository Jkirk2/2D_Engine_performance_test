#include <simple2d.h>
#include <iostream>
#include <list>
#include <iterator>
#include <random>
#include "ball.h"
#include "util.h"
#include <fstream>
#include <time.h>
using namespace std;

S2D_Window *window;
vector<Ball> balls;
ofstream MyFile("performanceReport.txt");
time_t startTime;
float timePassed;
vector<int> avgFrames;
int frame = 0;
void init()
{
}
void render()
{
  for (vector<Ball>::iterator it = balls.begin(); it != balls.end(); ++it)
  {
    it->render();
  }
}
void update()
{
  
  timePassed = difftime(time(NULL), startTime);
  if (frame % 60 == 0)
  {
    MyFile << frame << "," << window->elapsed_ms << "," << balls.size() << "\n";
    for (int i = 0; i < 5000; i++)
    {
      Ball b = Ball(rand() % screenWidth, rand() % screenHeight);
      balls.push_back(b);
    }
    startTime = time(NULL);
    if (balls.size() > 100000)
    {
      S2D_FreeWindow(window);
      MyFile.close();
    }
  }

  for (vector<Ball>::iterator it = balls.begin(); it != balls.end(); ++it)
  {
    it->update();
  }
  frame++;
}

int main()
{

  window = S2D_CreateWindow(
      "Performance Test", 1400, 900, update, render, 0);

  screenWidth = window->viewport.width;
  screenHeight = window->viewport.height;
  S2D_Show(window);
  
  time(&startTime);
  
  return 0;
}
