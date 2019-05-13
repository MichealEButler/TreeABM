#include "Tree.h"
#include "Chunk.h"

DrawFunctions * drawFunctionsTree = nullptr;

Tree::Tree(int _id, int x, int y, int species) : Agent(_id, x, y)
{
  // currently this runs everytime an individual is created, the initial recruits
  // need randomizing in a different way when constructing the starting stand
  int random = (rand() % 10) + 1;
  _DBH = float(random);

  x = _x;
  y = _y;
  _species= species;

  _cMortality = false;

  tf = new TreeFunctions();
  tf->setConstants(_species);
  tf->initAge(_DBH);
  _age = tf->getAge();

  //cout << "Tree Created! " << endl;
  //cout << "x = " << x << endl;
  //cout << "y = " << y << endl;
  _alive = true;
  setChunk();
}

Tree::~Tree()
{
  //cout << "Tree Destroyed! " << endl;
}

void Tree::update(float DBH, float tEffect, SDL_Renderer * renderer)
{
  _height = tf->getHeight(DBH);
  setDBH(tf->growth(DBH, tEffect));
  _radius = (tf->crownRadius(DBH));
  _biomass = (tf->biomass(DBH));
  tf->mortality();

  drawFunctionsTree = new DrawFunctions();

  drawFunctionsTree->fillCircle(renderer,_x,_y,(int)round(_radius),_species);
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

void Tree::setAge(int age, int ticks)
{
  age = age + ticks;
  _age = age;
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

void Tree::getNeighbors(vector<Tree*> cTrees)
{
  // ctrees is the reference to the chunk vector where the individual lies
  for(int i = 0; i < cTrees.size(); i++)
  {
    // radius of 5
    if((_x-5 <= cTrees[i]->getX()) && (_x+5 >= cTrees[i]->getX()) && (_y-5 <= cTrees[i]->getY()) && (_y+5 >= cTrees[i]->getY()))
    {
      //_nTrees.push_back(cTrees[i]);
      _idTrees.push_back(cTrees[i]->getID());

      //cout << "Tree " << getID() << " neighbor = ";
      //cout << cTrees[i]->getID() << endl;
    }
  }
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

void Tree::setTEffect(float DEGD)
{
  _tEffect = tf->tempEffect(DEGD);
  //cout << "Temp Effect = " << _tEffect << endl;
}

float Tree::getTEffect()
{
  return _tEffect;
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
  // if real is less than opt to calculate
  tf->getMortality();
}

void Tree::setCMortality()
{
  _cMortality = true;
}

bool Tree::crowdingMortality()
{
  return _cMortality;
}
