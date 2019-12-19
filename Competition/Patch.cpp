#include "Patch.h"

Patch::Patch()
{
  _x = _y = _id = _numCover = 0;
}

Patch::~Patch()
{
  // on destruction, the patches which had been covered by indivduals output the ID of those individuals along with the patch locations
  if(treeCover.size() > 0)
  {
    cout << "Tree cover of patch " << _x << " " << _y << " = ";
    for(int i = 0; i < treeCover.size(); i++)
    {
      cout << treeCover[i] << " ";
    }
    cout << endl;
  }
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
  treeCover.clear();
  _numCover = 0;

  for(int i = 0; i < trees.size(); i++)
  {
    if(_x < trees[i]->getX()+trees[i]->getCRadius() && _x >= trees[i]->getX()-trees[i]->getCRadius() && _y < trees[i]->getY()+trees[i]->getCRadius() && _y >= trees[i]->getY()-trees[i]->getCRadius())
    {
      treeCover.push_back(trees[i]->getID());
      _numCover = _numCover + 1;
    }
  }
}

void Patch::setTreeCoverC(Tree* circle)
{
  circleCover.clear();
  _numCover = 0;


  if(_x <= circle->getX()+(circle->getCRadius()-1) && _x >= circle->getX()-circle->getCRadius() && _y <= circle->getY()+(circle->getCRadius()-1) && _y >= circle->getY()-circle->getCRadius())
  {
    circleCover.push_back(circle->getID());
    _numCover = _numCover + 1;
  }

}

void Patch::setPixelCoverC(Tree* circle)
{
  // if the location of the circle falls within the patch color the patch
  pixelCover.clear();
  _numCover = 0;
  int pixelW = 20;
  int pixelH = 20;

  int pixelX = circle->getX() * pixelW;
  int pixelY = circle->getX() * pixelH;
  int pixelR = circle->getCRadius() * pixelH;

  if((_x * 20) <= (pixelX+(pixelR-1)) && (_x * 20) >= (pixelX-pixelR) && (_y * 20) <= (pixelY+(pixelR-1)) && (_y * 20) >= (pixelY-pixelR));
  {
    pixelCover.push_back(circle->getID());
    _numCover = _numCover + 1;
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

vector<int> Patch::getTreeCover()
{
  return treeCover;
}

vector<int> Patch::getCCover()
{
  return circleCover;
}
