#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include "DrawFunctions.h"

using namespace std;

class World
{
public:
  World();
  ~World();
  void loadWorld(const char* fileName);
  void renderWorld(SDL_Renderer* renderer);

  void setColor(int color);

  int getColor();
  float world[100][100];
  // function to update pixels in window to reference output from humpol (ui console)
  // function to update pixels to create a height map (ui console)

private:
  DrawFunctions* df;

  int _color;
};

#endif
