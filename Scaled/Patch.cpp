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
  int counter = 0;
  _numCover = 0;
  float height = 0;
  float height1 = 0;

  int vectSize = trees.size();

  for(int i = 0; i < vectSize; i++)
  {
    if(_x < trees[i]->getX()+trees[i]->getRadius() && _x >= trees[i]->getX()-trees[i]->getRadius() && _y < trees[i]->getY()+trees[i]->getRadius() && _y >= trees[i]->getY()-trees[i]->getRadius())
    {
      counter++;
      _numCover++;
      // also store id's of these trees in order to referecne which is the highest

      if(counter == 1)
      {
        height = trees[i]->getHeight();
        _hTree = trees[i]->getID();
      }

      if(counter > 1)
      {
        height1 = trees[i]->getHeight();

        if(height < height1)
        {
          height = height1;
          _hTree = trees[i]->getID();
        }
      }
    }
  }

  //cout << "Highest Tree = " << _hTree << endl;
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

int Patch::getHTree()
{
  return _hTree;
}
