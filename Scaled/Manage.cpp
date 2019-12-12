#include "Manage.h"

Manage::Manage()
{

}

Manage::~Manage()
{

}

void Manage::genRemoval()
{
  
}
void Manage::setTicks(int ticks)
{
  _ticks = ticks;
}

void Manage::setSpecies(int species)
{
  _species = species;
}

void Manage::setRSum(int rSum)
{
  _rSum = rSum;
}

int Manage::getTicks()
{
  return _ticks;
}

int Manage::getSpecies()
{
  return _species;
}

int Manage::getRSum()
{
  return _rSum;
}
