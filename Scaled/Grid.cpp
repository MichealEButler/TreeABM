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

int Grid::getGridSize()
{
  return gridSize;
}
