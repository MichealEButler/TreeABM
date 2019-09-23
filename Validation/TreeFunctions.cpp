#include "TreeFunctions.h"

TreeFunctions::TreeFunctions()
{

  _mortality = false;
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
      _agemx = 400;
      _s = 1;
      _g = 70;
      _crate = 0.1;
      _DDmin = 830;
      _DDmax = 4890;
      _bio0 = 0.13;
      _bio1 = 2.49;
      break;
    case 2 : //Pine
      _b2 = 67.26;
      _b3 = 0.34;
      _hmax = 35;
      _dmax = 100;
      _agemx = 450;
      _s = 1;
      _g = 140;
      _crate = 0.1;
      _DDmin = 450;
      _DDmax = 2350;
      _bio0 = 0.3;
      _bio1 = 2.22;
      break;
    case 3 : //Oak
      _b2 = 38.63;
      _b3 = 0.096;
      _hmax = 40;
      _dmax = 200;
      _agemx = 500;
      _s = 0.7;
      _g = 70;
      _crate = 0.1;
      _DDmin = 810;
      _DDmax = 4330;
      _bio0 = 0.23;
      _bio1 = 2.28;
      break;
    case 4 : //Alder
      _b2 = 128.76;
      _b3 = 1.07;
      _hmax = 30;
      _dmax = 50;
      _agemx = 300;
      _s = 1.2;
      _g = 200;
      _crate = 0.1;
      _DDmin = 1100;
      _DDmax = 4890;
      _bio0 = 0.3;
      _bio1 = 2.22;
      break;
    case 5 : //Hazel
      _b2 = 67.26;
      _b3 = 0.34;
      _hmax = 12;
      _dmax = 20;
      _agemx = 60;
      _s = 1;
      _g = 200;
      _crate = 0.3;
      _DDmin = 410;
      _DDmax = 4300;
      _bio0 = 0.2;
      _bio1 = 2.19;
      break;
    case 6 : //Ash
      _b2 = 38.63;
      _b3 = 0.096;
      _hmax = 35;
      _dmax = 170;
      _agemx = 250;
      _s = 0.4;
      _g = 120;
      _crate = 0.1;
      _DDmin = 750;
      _DDmax = 4170;
      _bio0 = 0.13;
      _bio1 = 2.52;
      break;
    case 7 : //lime
      _b2 = 128.76;
      _b3 = 1.07;
      _hmax = 25;
      _dmax = 30; //??
      _agemx = 400;
      _s = 0.2;
      _g = 60;
      _crate = 0.1;
      _DDmin = 1100;
      _DDmax = 4170;
      _bio0 = 0.13; // not correct
      _bio1 = 2.49; // not correct
      break;
    case 8 : //Birch
      _b2 = 67.26;
      _b3 = 0.34;
      _hmax = 30;
      _dmax = 60;
      _agemx = 120;
      _s = 1;
      _g = 220;
      _crate = 0.1;
      _DDmin = 410;
      _DDmax = 2300;
      _bio0 = 0.13;
      _bio1 = 2.43;
      break;
    case 9 : //Hornbeam
      _b2 = 109.4;
      _b3 = 2.18;
      _hmax = 15;
      _dmax = 25;
      _agemx = 130;
      _s = 0.9;
      _g = 60;
      _crate = 0.1;
      _DDmin = 1400;
      _DDmax = 3300;
      _bio0 = 0.13; //provisional from Pretzsch
      _bio1 = 2.49;
      break;
    case 10 : //Larch
      _b2 = 64.84;
      _b3 = 0.22;
      _hmax = 50;
      _dmax = 150;
      _agemx = 400;
      _s = 0.7;
      _g = 110;
      _crate = 0.1;
      _DDmin = 110;
      _DDmax = 2060;
      _bio0 = 0.04; //provisional from Pretzsch
      _bio1 = 1.37;
      break;
    case 11 : //Beech
      _b2 = 64.84;
      _b3 = 0.22;
      _hmax = 50;
      _dmax = 150;
      _agemx = 400;
      _s = 0.7;
      _g = 110;
      _crate = 0.1;
      _DDmin = 110;
      _DDmax = 2060;
      _bio0 = 0.04; //provisional from Pretzsch
      _bio1 = 1.37;
      break;
    case 12 : //Willow
      _b2 = 64.84;
      _b3 = 0.22;
      _hmax = 50;
      _dmax = 150;
      _agemx = 400;
      _s = 0.7;
      _g = 110;
      _crate = 0.1;
      _DDmin = 110;
      _DDmax = 2060;
      _bio0 = 0.04; //provisional from Pretzsch
      _bio1 = 1.37;
      break;
    case 13 : //Maple
      _b2 = 64.84;
      _b3 = 0.22;
      _hmax = 50;
      _dmax = 150;
      _agemx = 400;
      _s = 0.7;
      _g = 110;
      _crate = 0.1;
      _DDmin = 110;
      _DDmax = 2060;
      _bio0 = 0.04; //provisional from Pretzsch
      _bio1 = 1.37;
      break;
    case 14 : //PFT place holder to mantain populations
      _b2 = 64.84;
      _b3 = 0.22;
      _hmax = 50;
      _dmax = 150;
      _agemx = 400;
      _s = 0.7;
      _g = 110;
      _crate = 0.1;
      _DDmin = 110;
      _DDmax = 2060;
      _bio0 = 0.04; //provisional from Pretzsch
      _bio1 = 1.37;
      break;
    default:
      cout << "No species found " << endl;
  }
}

void TreeFunctions::initAge(float DBH)
{
  //called once at the start of the simulation
  // linear function taken from the netlogo version of the model
  if (DBH > 0)
  {
    float a1 = _dmax / DBH;
    float a2 = 1 / a1;
    float a3 = float(_agemx) * a2;

    _age = (int)a3;
  }
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

void TreeFunctions::setDDmin(float DDmin)
{
  _DDmin = DDmin;
}

void TreeFunctions::setDDmax(float DDmax)
{
  _DDmax = DDmax;
}

int TreeFunctions::getAgeMax()
{
  return _agemx;
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

float TreeFunctions::getDDmin()
{
  return _DDmin;
}

float TreeFunctions::getDDmax()
{
  return _DDmax;
}

float TreeFunctions::getTEffect()
{
  return _tEffect;
}

float TreeFunctions::getBiomass()
{
  return _biomass;
}

bool TreeFunctions::getMortality()
{
  return _mortality;
}

float TreeFunctions::getHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = 137 + ((_b2 * _dbh) - (_b3 * (_dbh * _dbh)));

  return currentHeight;
}

float TreeFunctions::expHeight(float DBH)
{
  //SORTIE function implemented in the NetLogo
  float _dbh = DBH;

  float currentHeight = (_hmax * (1 - exp(-(_s / _hmax) * DBH)) * 100);

  return currentHeight;

}

float TreeFunctions::growth(float DBH, float tEffect, float lClimate)
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
  _optimalG = part7 / part10;
  float envirn = ((tEffect + lClimate) / 2);
  _realG = (part7 / part10) * envirn;

  float currentDBH = _dbh + _realG;

  //cout << "DBH = " << currentDBH << endl;
  return currentDBH;
}

float TreeFunctions::crownRadius(float DBH)
{
  float _dbh = DBH;

  float _crownradius = (_crate * _dbh) / 2;

  return _crownradius;
}

float TreeFunctions::crownArea(float cradius)
{
  float cArea = PI * (pow(cradius, 2));

  return cArea;
}

float TreeFunctions::biomass(float DBH)
{
  _biomass = _bio0 * (pow(DBH, _bio1));
  return _biomass;
}

void TreeFunctions::updateGeometry(float DBH)
{

}

void TreeFunctions::slopeEffect()
{
  // needs to reference the slope of the stored square where the individual tree lies
}

float TreeFunctions::tempEffect(float DEGD)
{
  // to take in processed DEGD and species response from the envirn class
  _tEffect = (4 * ((_DDmax - DEGD) * (DEGD - _DDmin))) / ((_DDmax - _DDmin) * (_DDmax - _DDmin));
  //cout << "Temperature effect = " << _tEffect << endl;
  return _tEffect;
}

void TreeFunctions::mortality()
{
  // mortality probability based on general mortality function and Environment
  // to be added here
  if (_realG < (_optimalG / 10))
  {
    int death = rand() % 1000;

    if (death < 368)
    {
      _mortality = true;
    }
  } else {
    _mortality = false;
  }
}
