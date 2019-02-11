#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <fstream>
#include <iostream>
#include "Display.h"

using namespace std;

class World
{
public:
  World();
  ~World();
  void loadWorld(const char* fileName);
  void renderWorld();
  // function to update pixels in window to reference output from humpol (ui console)
  // function to update pixels to create a height map (ui console)

private:
  float world[1000][1000];
};

#endif
