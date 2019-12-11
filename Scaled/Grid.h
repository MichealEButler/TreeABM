#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Grid
{
public:
  Grid();
  ~Grid();
  void setupGrid(int gridX, int gridY); // grids as ID's

  int getGridSize();

private:
  int gridSize;

};

#endif
