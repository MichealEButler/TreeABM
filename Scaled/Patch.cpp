#include "Patch.h"

Patch::Patch()
{
  _x = _y = _id = _numCover = 0;
}

Patch::~Patch()
{
  // on destruction, the patches which had been covered by indivduals output the ID of those individuals along with the patch locations

}

void Patch::setID(int id)
{
  _id = id;
}

void Patch::setX(int x)
{
  _x = x;
}

void Patch::setY(int y)
{
  _y = y;
}

void Patch::setTreeCover(vector<Tree*> trees)
{
  _numCover = 0;

  int vectSize = trees.size();

  for(int i = 0; i < vectSize; i++)
  {
    if(_x < trees[i]->getX()+trees[i]->getRadius() && _x >= trees[i]->getX()-trees[i]->getRadius() && _y < trees[i]->getY()+trees[i]->getRadius() && _y >= trees[i]->getY()-trees[i]->getRadius())
    {
      _numCover++;
    }
  }
}

int Patch::getID()
{
  return _id;
}

int Patch::getX()
{
  return _x;
}

int Patch::getY()
{
  return _y;
}

int Patch::getNumCover()
{
  return _numCover;
}
