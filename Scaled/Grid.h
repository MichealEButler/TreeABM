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
  void storeTreeIDs(vector<int> trees);
  void setupGrid(int gridX, int gridY); // grids as ID's

  int getGridSize();

private:
  vector<int> treeIDs; // holds id's for each location of the grid
  int gridSize;

};

#endif
