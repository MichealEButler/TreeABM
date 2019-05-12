#include "Camp.h"

Camp::Camp() : Object(-1)
{

}

Camp::Camp(int _id, int cx, int cy, int width, int height) : Object(_id)
{
  _cx = cx;
  _cy = cx;
  _width = width;
  _height = height;

  cout << "Camp created! " << endl;
  cout << "X = " << cx << ", Y = " << cy << endl;
}

Camp::~Camp()
{
  cout << "Camp destroyed! " << endl;
}

int Camp::getX()
{
  return _cx;
}

int Camp::getY()
{
  return _cy;
}