#include "Grid.h"

Grid::Grid()
{
  gridSize = 0;
}

Grid::~Grid()
{

}

void Grid::setupGrid(int gridX, int gridY)
{
  gridSize = gridX * gridY;
}

void Grid::storeTreeIDs(vector<int> patches)
{
  //stores ID's of all trees at each location

}

int Grid::getGridSize()
{
  return gridSize;
}
