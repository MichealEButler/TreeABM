#include "TreeFunctions.h"

TreeFunctions::TreeFunctions()
{

  tick = 0;
}

TreeFunctions::~TreeFunctions()
{

}

void TreeFunctions::setConstants(int species)
{
  switch (species) {
    case 1 : //Elm
      _b2 = 128.76;
      _b3 = 1.07;
      _hmax = 40;
      _dmax = 60;
      _s = 1;
      _g = 70;
      _crate = 0.1;
      break;
    case 2 : //Pine
      _b2 = 67.26;
      _b3 = 0.34;
      _hmax = 35;
      _dmax = 100;
      _s = 1;
      _g = 140;
      _crate = 0.1;
      break;
    case 3 : //Oak
      _b2 = 38.63;
      _b3 = 0.096;
      _hmax = 40;
      _dmax = 200;
      _s = 0.7;
      _g = 70;
      _crate = 0.1;
      break;
    default:
      cout << "No species found " << endl;
  }
}

void TreeFunctions::setAge(int age)
{
  _age = age;
}

void TreeFunctions::setSpecies(int species)
{
  _species = species;
}

void TreeFunctions::setB2(float b2)
{
  _b2 = b2;
}

void TreeFunctions::setB3(float b3)
{
  _b3 = b3;
}

void TreeFunctions::setHMAX(float hmax)
{
  _hmax = hmax;
}

void TreeFunctions::setDMAX(float dmax)
{
  _dmax = dmax;
}

void TreeFunctions::setS(float s)
{
  _s = s;
}

void TreeFunctions::setG(float g)
{
  _g = g;
}

void TreeFunctions::setCRATE(float crate)
{
  _crate = crate;
}

int TreeFunctions::getAge()
{
  return _age;
}

int TreeFunctions::getSpecies()
{
  return _species;
}

float TreeFunctions::getB2()
{
  return _b2;
}

float TreeFunctions::getB3()
{
  return _b3;
}

float TreeFunctions::getHMAX()
{
  return _hmax;
}

float TreeFunctions::getDMAX()
{
  return _dmax;
}

float TreeFunctions::getS()
{
  return _s;
}

float TreeFunctions::getG()
{
  return _g;
}

float TreeFunctions::getCRATE()
{
  return _crate;
}

float TreeFunctions::initAge(float DBH)
{

}

float TreeFunctions::getHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = 137 + ((_b2 * _dbh) - (_b3 * (_dbh * _dbh)));

  return currentHeight;
}

float TreeFunctions::expHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = (_hmax * (1 - exp(-(_s / _hmax) * DBH)) * 100);

  return currentHeight;

}

float TreeFunctions::growth(float DBH)
{
  float _dbh = DBH;

  float part1 = _g * _dbh;
  float part2 = _b2 * _dbh;
  float part3 = (_b3 * (_dbh * _dbh));
  float part4 = 137 + part2 - part3;
  float part5 = (_dbh * part4) / (_dmax *(_hmax * 100));
  float part6 = (1 - part5);
  float part7 = part1 * part6;

  float part8 = (3 * (_b2 * _dbh));
  float part9 = (4 * (_b3 * (_dbh * _dbh)));
  float part10 = 274 + part8 - part9;

  // optimal growth
  float part11 = part7 / part10;

  float currentDBH = _dbh + part11;

  return currentDBH;
}

float TreeFunctions::crownRadius(float DBH)
{
  float _dbh = DBH;

  float _crownradius = (_crate * _dbh) / 2;

  return _crownradius;
}

void TreeFunctions::updateGeometry(float DBH)
{

}

void TreeFunctions::slopeEffect()
{
  // needs to reference the slope of the stored square where the individual tree lies
}

void tempEffect(float tEffect)
{
  // to take in processed DEGD and species response from the envirn class
}

void mortality()
{
  // mortality probability based on general mortality function and Environment
  // to be added here
}
