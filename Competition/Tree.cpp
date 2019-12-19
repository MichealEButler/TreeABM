#include "Tree.h"

Tree::Tree()
{
  cout << "Tree Created! " << endl;
}

Tree::Tree(int id)
{
  cout << "Tree " << id << " created! " << endl;

  _id = id;
  _x = rand() % 15 + 2;
  _y = rand() % 15 + 2;

  _cradius = rand() % 3 + 1;

  if(_cradius == 1)
  {
    _height = rand() % 10 + 10;
  }

  if(_cradius == 2)
  {
    _height = rand() % 10 + 20;
  }

  if(_cradius == 3)
  {
    _height = rand() % 10 + 30;
  }

  _dominance = true;
  _canopyCover = 0.0f;

  cout << "x = " << _x << endl;
  cout << "y = " << _y << endl;
  cout << "Crown Radius = " << _cradius << endl;
  cout << "Height = " << _height << endl;
  cout << "-------------------" << endl;
}

Tree::Tree(int x, int y, float radius)
{
  _x = x;
  _y = y;

  _cradius = radius;
}

Tree::~Tree()
{

}

int Tree::getX()
{
  return _x;
}

int Tree::getY()
{
  return _y;
}

float Tree::getCRadius()
{
  return _cradius;
}

int Tree::getHeight()
{
  return _height;
}

bool Tree::getDominance()
{
  return _dominance;
}

int Tree::getID()
{
  return _id;
}

int Tree::getTCover()
{
  return _tCover;
}
int Tree::getMyPatches()
{
  return _myPatches;
}

void Tree::storePatches()
{
  patches.clear();

  int x = _x;
  int y = _y;
  int x0 = 0;
  int y0 = round(_cradius);
  int d = 3 - 2 * round(_cradius);
  if(!_cradius) return;

  while(y0 >= x0)
  {
    patches.push_back((20 * (x - x0)) + ((y - y0)));
    patches.push_back((20 * (x - y0)) + ((y - x0)));
    patches.push_back((20 * (x + y0)) + ((y - x0)));
    patches.push_back((20 * (x + x0)) + ((y - y0)));
    patches.push_back((20 * (x - x0)) + ((y + y0)));
    patches.push_back((20 * (x - y0)) + ((y + x0)));
    patches.push_back((20 * (x + y0)) + ((y + x0)));
    patches.push_back((20 * (x + x0)) + ((y + y0)));
    if(d < 0) d += 4 * x0++ + 6;
    else d+= 4 * (x0++ - y0--) + 10;
  }
}

void Tree::setDominance(vector<Tree*> nTrees)
{

}

void Tree::growCircle()
{
  _cradius = _cradius + 0.1f;
  cout << "Circle Radius = " << _cradius << endl;
}

float Tree::intersectArea(float Ax, float Ay, float Bx, float By, float Ar, float Br)
{
  //taken from https://www.xarg.org/2016/07/calculate-the-intersection-area-of-two-circles/

  float a, b, d, x, z, y;

  d = hypot(Bx - Ax, By - Ay);

  if(d < (Ar + Br))
  {
    a = Ar * Ar;
    b = Br * Br;

    x = (a - b + d * d) / (2 * d);
    z = x * x;
    y = sqrt(a - z);

    if(d < abs(Br - Ar))
    {
      return PI * min(a,b);
    }
    return a * asin(y / Ar) + b * asin(y / Br) - y * (x + sqrt(z + b - a));
  }
  return 0;
}

void Tree::setNeighbors(vector<Tree*> trees)
{
  _idTrees.clear();
  _canopyCover = 0.0f;

  for(int i = 0; i < trees.size(); i++)
  {

    if((_x - _cradius < trees[i]->getX()+trees[i]->getCRadius()) && (_x + _cradius > trees[i]->getX()-trees[i]->getCRadius()) && (_y - _cradius < trees[i]->getY()+trees[i]->getCRadius()) && (_y + _cradius > trees[i]->getY()-trees[i]->getCRadius()))
    {
      if(_x != trees[i]->getX() && _y != trees[i]->getY())
      {
        _idTrees.push_back(trees[i]->getID());

        if(trees[i]->getHeight() > _height)
        {
          _dominance = false;
          float cover = intersectArea((float)trees[i]->getX(), (float)trees[i]->getY(), (float)_x, (float)_y, (float)trees[i]->getCRadius(),(float)_cradius);
          _canopyCover = _canopyCover + cover;
        }
      }
    }
  }
}

void Tree::outData()
{
  cout << "Tree " << _id << " " << _dominance << endl;
  cout << " x = " << _x << ", " << "y = " << _y << endl;
  cout << "Crown Radius = " << _cradius << endl;
  cout << "Canopy Cover = " << _canopyCover << endl;
  cout << "Number of patches covered = " << _tCover << endl;
  cout << "Number of light patches = " << _myPatches << endl;

  for(int i = 0; i < _idTrees.size(); i++)
  {
    cout << _idTrees[i] << " ";
  }

  cout << endl << "-------------------" << endl;
}

void Tree::resetPatches()
{
  _tCover = 0; //total covered patches
  _myPatches = 0; //patches that this tree is the only one that is covering
}

void Tree::setTCover()
{
  _tCover++;
}

void Tree::referencePatches(int num)
{
  //first determine if this species is the dominant in its local, if tree receives full light
  //then ask all patches count number of covered pathces using crown radius, then ask these patches if cover = 1,
  //light = to percentage num with 1 / total covered

  if(num == 1)
  {
    _myPatches++;
  }
}
