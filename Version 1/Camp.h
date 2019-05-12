#ifndef CAMP_H
#define CAMP_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Object.h"
#include "DrawFunctions.h"

using namespace std;

class Camp : public Object
{
public:
  Camp();
  Camp(int _id, int cx, int cy, int width, int height);
  ~Camp();

  void drawCamp(SDL_Renderer* renderer);
  int getX();
  int getY();

private:
  int _cx;
  int _cy;
  int _width;
  int _height;
};

#endif
