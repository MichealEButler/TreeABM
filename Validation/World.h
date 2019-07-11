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
  void loadHeight(const char* fileName);
  void loadSlope(const char* fileName);
  void loadSoil(const char* fileName);
  void renderHeight(SDL_Renderer* renderer);
  void renderSlope(SDL_Renderer* renderer);
  void renderSoil(SDL_Renderer* renderer);
  float getElevation(int x, int y);
  float getSlope(int x, int y);
  int getSoil(int x, int y);

  void setColor(int color);

  int getColor();
  float getLNumH();
  float getSmNumH();
  float getLNumS();
  float getSmNumS();
  float height[14][14];
  float slope[14][14];
  int soil[14][14];
  // function to update pixels in window to reference output from humpol (ui console)
  // function to update pixels to create a height map (ui console)

private:
  DrawFunctions* df;

  int _color;
  float _lNumH; // largest number within the world import array (i.e elevation, slope etc)
  float _smNumH; // smallest number
  float _lNumS; // largest number within the world import array (i.e elevation, slope etc)
  float _smNumS; // smallest number
};

#endif
