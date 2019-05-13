#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class World
{
public:
  World();
  ~World();
  void loadWorld();
  void renderWorld(SDL_Renderer* renderer);
  void fillRect(SDL_Renderer * renderer, int x, int y, int width, int height);

  void setColor(int color);

  int getColor();
  float world[20][20];

private:

  int _color;
};

#endif
