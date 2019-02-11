#include "TreeFunctions.h"

TreeFunctions::TreeFunctions()
{
  b2 = 67.26;
  b3 = 0.34;
  HMAX = 35;
  DMAX = 100;
  S = 1;
  G = 140;
  c_rate = 0.1;

  tick = 0;
}

TreeFunctions::~TreeFunctions()
{

}

float TreeFunctions::getHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = 137 + ((b2 * _dbh) - (b3 * (_dbh * _dbh)));

  return currentHeight;
}

float TreeFunctions::expHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = (HMAX * (1 - exp(-(S / HMAX) * DBH)) * 100);

  return currentHeight;

}

float TreeFunctions::growth(float DBH)
{
  float _dbh = DBH;

  float part1 = G * _dbh;
  float part2 = b2 * _dbh;
  float part3 = (b3 * (_dbh * _dbh));
  float part4 = 137 + part2 - part3;
  float part5 = (_dbh * part4) / (DMAX *(HMAX * 100));
  float part6 = (1 - part5);
  float part7 = part1 * part6;

  float part8 = (3 * (b2 * _dbh));
  float part9 = (4 * (b3 * (_dbh * _dbh)));
  float part10 = 274 + part8 - part9;

  // optimal growth
  float part11 = part7 / part10;

  float currentDBH = _dbh + part11;

  return currentDBH;
}

float TreeFunctions::crownRadius(float DBH)
{
  float _dbh = DBH;

  float _crownradius = (c_rate * _dbh) / 2;

  return _crownradius;
}

void TreeFunctions::updateGeometry(float DBH)
{

}
