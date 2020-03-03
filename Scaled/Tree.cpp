#include "Tree.h"
#include "Chunk.h"

DrawFunctions * drawFunctionsTree = nullptr;

Tree::Tree(int _id, int x, int y, int species) : Agent(_id, x, y)
{
  // currently this runs everytime an individual is created, the initial recruits
  // need randomizing in a different way when constructing the starting stand
  _age = 0;
  _biomass = 0;
  _DBH = 1.0;
  x = _x;
  y = _y;
  _species = species;
  _npatches.clear();

  _cMortality = false;
  _aMortality = false;
  _dominance = true;
  _pDominace = false;
  _lEffect = 1.0;

  tf = new TreeFunctions();
  tf->setConstants(_species);
  _alive = true;
  setChunk();
  drawFunctionsTree = new DrawFunctions();
}

Tree::~Tree()
{
  //cout << "Tree Destroyed! " << endl;
}

void Tree::randomDBH()
{
  int maxDiameter = tf->getDMAX();
  _DBH = (rand() % maxDiameter) + 1;
}

void Tree::setStartDBH(float DBH)
{
  _DBH = DBH;
}

void Tree::update(float DBH, float tEffect, float lClimate)
{
  _height = tf->getHeight(DBH);
  setDBH(tf->growth(DBH, tEffect, lClimate));
  _radius = (tf->crownRadius(DBH));
  _biomass = (tf->biomass(DBH));
  tf->mortality();
  _age++;
}

void Tree::draw(SDL_Renderer * renderer)
{
  drawFunctionsTree->fillCircle(renderer,((_x*8)+4),((_y*8)+4),((int)round(_radius)*8),_species);
}

void Tree::setDBH(float DBH)
{
  _DBH = DBH;
}

void Tree::setHeight(float height)
{
  _height = height;
}

void Tree::setRadius(float radius)
{
  _radius = radius;
}

void Tree::setupAge()
{
  if(_DBH > 0)
  {
    float age = 1 / (tf->getDMAX() / _DBH);
    age = tf->getAgeMax() * age;
    _age = (int)age;
  }
}

void Tree::setAge(int ticks)
{
  _age = _age + ticks;
}

void Tree::setSpecies(int species)
{
  _species = species;
}

void Tree::setChunk()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if(_x >= (i * 100) && _x < ((i + 1) * 100) && _y >= (j * 100) && _y < ((j + 1) * 100))
      {
        _chunk = (10 * i) + (j+1);
      }
    }
  }
}

void Tree::setElevation(float worldElevation)
{
  _elevation = worldElevation;
}

void Tree::setSlope(float worldSlope)
{
  _slope = worldSlope;
}

void Tree::setPDominace()
{
  _pDominace = true;
}

void Tree::storePatches()
{
  // create a box around the crown area, and allocate patch id of each corner
  int orig, topR, topL, botR, botL;

  int castR = round(_radius);

  _npatches.clear();
  //cout << "Actual radius = " << _radius << endl;
  //cout << "Rounded radius = " << castR << endl;

  int crD = castR + castR;
  int sqr = castR * castR;
  int left = ((castR + 1) * 100);
  int right = ((castR - 1) * 100);

  orig = (_x * 100) + _y;
  topL = orig - (left + castR);
  topR = orig + (right - castR);
  botL = orig - (left - castR);
  botR = orig + (right + castR);

  if (castR == 0)
  {
    _npatches.push_back(orig);
  }

  for(int i = 0; i < (crD+1); i++)
  {
    for(int j = 0; j < crD; j++)
    {
      int value = (topL+(i*100))+j;

      if(value >= 0 && value < 10000)
      {
        _npatches.push_back(value);
      }
    }
  }

/*
  cout << "Tree at " << _x << " " << _y << endl;
  cout << "Patches = ";

  for (int i = 0; i < _npatches.size(); i++)
  {
    cout << _npatches[i] << " ";
  }

  cout << endl << endl;
*/

}

void Tree::setPProduction()
{
  // amount of pollen is the product of the crown diameter of tree and species specific productivity attribute
}

void Tree::getNeighbors(vector<Tree*> cTrees)
{
  // ctrees is the reference to the chunk vector where the individual lies
  /*
  for(int i = 0; i < cTrees.size(); i++)
  {
    if((_x - _radius <= cTrees[i]->getX()) && (_x + _radius >= cTrees[i]->getX()) && (_y - _radius <= cTrees[i]->getY()) && (_y + _radius >= cTrees[i]->getY()))
    {
      if(_x != cTrees[i]->getX() && _y != cTrees[i]->getY())
      {
        _idTrees.push_back(cTrees[i]->getID());

        if(cTrees[i]->getHeight() > _height)
        {
          _dominance = false;
        }
      }
    }
  }
*/
  // second function to iterate through neighbors whose crown is in range of trees[i] crown
  for(int i = 0; i < cTrees.size(); i++)
  {
    // change x - radius to called functions?
    // is my.x-radius <= n.x - radius
    // is my.x+radius >= n.x + radius
    // is my.y-radius <= n.y - radius
    // is my.y+radius >= n.y + radius

    if((_x - _radius < cTrees[i]->getX()+cTrees[i]->getRadius()) && (_x + _radius > cTrees[i]->getX()-cTrees[i]->getRadius()) && (_y - _radius < cTrees[i]->getY()+cTrees[i]->getRadius()) && (_y + _radius > cTrees[i]->getY()-cTrees[i]->getRadius()))
    {
      if(_x != cTrees[i]->getX() && _y != cTrees[i]->getY())
      {
        _idTrees.push_back(cTrees[i]->getID());

        if(cTrees[i]->getHeight() > _height)
        {
          _dominance = false;
        }
      }
    }
  }

}

void Tree::lightEffect()
{
  float percentEffect = (float)_myPatches / (float)_tCover;
  _lEffect = percentEffect;
}

float Tree::getDBH()
{
  return _DBH;
}

float Tree::getHeight()
{
  return _height;
}

float Tree::getRadius()
{
  return _radius;
}

int Tree::getAge()
{
  return _age;
}

bool Tree::getAlive()
{
  return _alive;
}

bool Tree::getDominance()
{
  return _dominance;
}

bool Tree::getPDominance()
{
  return _pDominace;
}

int Tree::getSpecies()
{
  return _species;
}

float Tree::getBiomass()
{
  return _biomass;
}

int Tree::getChunk()
{
  return _chunk;
}

float Tree::getElevation()
{
  return _elevation;
}

float Tree::getSlope()
{
  return _slope;
}

int Tree::getMyPatches()
{
  return _myPatches;
}

void Tree::setTEffect(float DEGD)
{
  _tEffect = tf->tempEffect(DEGD);
  //cout << "Temp Effect = " << _tEffect << endl;
}

float Tree::getTEffect()
{
  /*
  if(_dominance == true)
  {
    _tEffect = 1.0;
  }
  */
  return _tEffect;
}

float Tree::getLEffect()
{
  return _lEffect;
}

void Tree::isAlive(bool alive)
{
  int chance = rand() % 1000;

  if (chance <= 50)
  {
    alive = false;
    cout << "Tree " << getID() << " has died! " << endl;
  }
}

bool Tree::removeTree()
{
  //if real is less than opt to calculate
  tf->getMortality();
}

void Tree::setCMortality()
{
  _cMortality = true;
}

bool Tree::ageMortality()
{
  if(_age >= tf->getAgeMax())
  {
    _aMortality = true;
  }
  return _aMortality;
}

bool Tree::crowdingMortality()
{
  return _cMortality;
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
