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

void Manage::setRPer(float rPer) // percent 0 - 1
{
  _rPer = rPer;
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

float Manage::getRPer()
{
  return _rPer;
}
