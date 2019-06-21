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

void Patch::setNeighbors()
{
  int origin = _id;
  int N, S, E, W, NE, NW, SE, SW;

  if((origin - 1) % 100 == 0)
  {
    N = -1;
    NE = -1;
    NW = -1;
  } else {
    N = origin - 1;
    NE = N + 100;
    NW = N - 100;
  }

  if(origin % 100 == 0)
  {
    S = -1;
    SE = -1;
    SW = -1;
  } else {
    S = origin + 1;
    SE = S + 100;
    SW = S - 100;
  }

  E = origin + 100;
  W = origin - 100;

  if(origin == 1)
  {
    SW = -1;
    W = -1;
    N = -1;
    NE = -1;
    NW = -1;
  }

  if(origin == 9901)
  {
    SE = -1;
    E = -1;
    N = -1;
    NE = -1;
    NW = -1;
  }

  if(origin == 10000)
  {
    NE = -1;
    E = -1;
    S = -1;
    SE = -1;
    SW = -1;
  }

  if(origin == 100)
  {
    NW = -1;
    W = -1;
    S = -1;
    SE = -1;
    SW = -1;
  }

  neighbors[0] = N;
  neighbors[1] = S;
  neighbors[2] = E;
  neighbors[3] = W;
  neighbors[4] = NE;
  neighbors[5] = NW;
  neighbors[6] = SE;
  neighbors[7] = SW;

  neighbors4[0] = N;
  neighbors4[1] = S;
  neighbors4[2] = E;
  neighbors4[3] = W;

}

void Patch::outNeighbors()
{
  for(int i = 0; i < 8; i++)
  {
    cout << neighbors[i] << " ";
  }
  cout << endl;
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
