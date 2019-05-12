#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class World
{
public:
  World();
  ~World();
  void loadWorld(const char* fileName);

  void setColor(int color);

  int getColor();
  float getLNum();
  float getSmNum();
  // function to update pixels in window to reference output from humpol (ui console)
  // function to update pixels to create a height map (ui console)

private:
  float world[1000][1000];
  int _color;
  float _lNum; // largest number within the world import array (i.e elevation, slope etc)
  float _smNum; // smallest number
};

#endif
