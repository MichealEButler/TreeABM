#include "TreeFunctions.h"

TreeFunctions::TreeFunctions()
{

  _mortality = false;
  _optimalG = 0.0f;
  _realG = 0.0f;
  _currentDBH = 0.0f;
  _gVigor = 0.0f;
  _currentHeight = 0;
  _volume = 0;
  _BA = 0;
  _vWeight = 0;
  _jabRand = 0;
  _annualProb = 0;
}

TreeFunctions::~TreeFunctions()
{

}

void TreeFunctions::setConstants(int species)
{
  switch (species) {
    case 1 : //Elm
      _b2 = 109.075;
      _b3 = 0.68172;
      _cr1 = 0.695;
      _cr2 = 0.1184;
      _hmax = 45;
      _dmax = 80;
      _agemx = 400;
      _s = 1.0;
      _g = 110;
      _g2 = 0.7;
      _crate = 0.1;
      _DDmin = 830;
      _DDmax = 4890;
      _bio0 = 0.13;
      _bio1 = 2.49;
      _den = 600;
      _eL = 0.4;
      _optDegree = 2860;
      _PPA = 40;
      break;

/*
    case 1 : //Beech
      _b2 = 44.85;
      _b3 = 0.14;
      _cr1 = 0.9461;
      _cr2 = 0.0651;
      _hmax = 35;
      _dmax = 150;
      _agemx = 350;
      _s = 0.7;
      _g = 140;
      _g2 = 0.8; // unknown (not available in FAREAST)
      _crate = 0.1;
      _DDmin = 500;
      _DDmax = 4330;
      _bio0 = 0.1143;
      _bio1 = 2.503;
      _den = 610;
      _eL = 0.3;
      _optDegree = 2440;
      _PPA = 50;
      break;
*/
/*
    case 1 : //Spruce
      _b2 = 69.808;
      _b3 = 0.27923;
      _cr1 = 0.4672;
      _cr2 = 0.0438;
      _hmax = 45;
      _dmax = 125;
      _agemx = 400;
      _s = 0.7;
      _g = 130;
      _g2 = 1.0;
      _crate = 0.1;
      _DDmin = 470;
      _DDmax = 2250;
      _bio0 = 0.255;
      _bio1 = 2.174;
      _den = 465;
      _eL = 0.5;
      _optDegree = 1360;
      break;
*/
/*
   case 2 : //Larch
      _b2 = 64.84;
      _b3 = 0.21613;
      _cr1 = 0.2109;
      _cr2 = 0.0638;
      _hmax = 40;
      _dmax = 150;
      _agemx = 400;
      _s = 0.7;
      _g = 130;
      _g2 = 1.1;
      _crate = 0.1;
      _DDmin = 110;
      _DDmax = 2060;
      _bio0 = 0.1732;
      _bio1 = 2.2044;
      _den = 512;
      _eL = 0.8;
      _optDegree = 1085;
      break;
*/
/*
    case 1 : //Hornbeam
      _b2 = 37.26;
      _b3 = 0.1863;
      _cr1 = 0.7431;
      _cr2 = 0.0969;
      _hmax = 20;
      _dmax = 100;
      _agemx = 250;
      _s = 0.4;
      _g = 120;
      _g2 = 0.7;
      _crate = 0.1;
      _DDmin = 670;
      _DDmax = 4330;
      _bio0 = 0.1093;
      _bio1 = 2.3595;
      _den = 665;
      _eL = 0.4;
      _optDegree = 2500;
      break;
*/
/*    case 1 : //Maple
      _b2 = 28.63;
      _b3 = 0.07158;
      _cr1 = 0.5898;
      _cr2 = 0.0513;
      _hmax = 30;
      _dmax = 200;
      _agemx = 600;
      _s = 0.7; // unknown (not available in fareast)
      _g = 90;
      _g2 = 1.0; // unknown (not available in fareast)
      _crate = 0.1;
      _DDmin = 670;
      _DDmax = 4170;
      _bio0 = 0.0633;
      _bio1 = 2.5189;
      _den = 565;
      _eL = 0.4;
      _optDegree = 2420;
      break;
*/
/*    case 1 : //Willow
      _b2 = 57.26;
      _b3 = 0.2863;
      _cr1 = 0.1489;
      _cr2 = 0.0888;
      _hmax = 30;
      _dmax = 100;
      _agemx = 150;
      _s = 0.7; // unknown (not available in fareast)
      _g = 200;
      _g2 = 1.0; // unknown (not available in fareast)
      _crate = 0.1;
      _DDmin = 830;
      _DDmax = 5060;
      _bio0 = 0.4135;
      _bio1 = 2.14;
      _den = 335;
      _eL = 0.7;
      _optDegree = 2945;
      break;
*/

    case 2 : //Pine
      _b2 = 67.26;
      _b3 = 0.33;
      _cr1 = 0.2912;
      _cr2 = 0.0642;
      _hmax = 35;
      _dmax = 100;
      _agemx = 300;
      _s = 1;
      _g = 140;
      _g2 = 1.4;
      _crate = 0.1;
      _DDmin = 450;
      _DDmax = 2350;
      _bio0 = 0.1182;
      _bio1 = 2.3281;
      _den = 414;
      _eL = 0.7;
      _optDegree = 1400;
      _PPA = 20;
      break;

    case 3 : //Oak
      _b2 = 38.63;
      _b3 = 0.096;
      _cr1 = 0.1489;
      _cr2 = 0.0888;
      _hmax = 40;
      _dmax = 200;
      _agemx = 500;
      _s = 0.4;
      _g = 140;
      _g2 = 0.7;
      _crate = 0.1;
      _DDmin = 810;
      _DDmax = 4330;
      _bio0 = 0.4135;
      _bio1 = 2.14;
      _den = 603;
      _eL = 0.7;
      _optDegree = 2570;
      _PPA = 30;
      break;
    case 4 : //Alder
      _b2 = 114.52;
      _b3 = 1.14;
      _cr1 = 0.3229;
      _cr2 = 0.1019;
      _hmax = 30;
      _dmax = 50;
      _agemx = 300;
      _s = 1.2;
      _g = 200;
      _g2 = 2.0;
      _crate = 0.1;
      _DDmin = 670;
      _DDmax = 4890;
      _bio0 = 0.1524;
      _bio1 = 2.2855;
      _den = 424;
      _eL = 0.5;
      _optDegree = 2780;
      _PPA = 10;
      break;
    case 5 : //Hazel
      _b2 = 66.3;
      _b3 = 1.65;
      _cr1 = 0.3229;
      _cr2 = 0.1019;
      _hmax = 8;
      _dmax = 20;
      _agemx = 80;
      _s = 1;
      _g = 200; // not available from studies, but is fast growing
      _g2 = 2.2; // not available from studies, but is fast growing
      _crate = 0.3;
      _DDmin = 410;
      _DDmax = 4300;
      _bio0 = 0.1524;
      _bio1 = 2.2855;
      _den = 517;
      _eL = 0.6;
      _optDegree = 2355;
      _PPA = 8;
      break;
    case 6 : //Ash
      _b2 = 39.56;
      _b3 = 0.11;
      _cr1 = 0.389;
      _cr2 = 0.0563;
      _hmax = 35;
      _dmax = 170;
      _agemx = 250;
      _s = 0.4;
      _g = 130;
      _g2 = 1.2;
      _crate = 0.1;
      _DDmin = 750;
      _DDmax = 4170;
      _bio0 = 0.17;
      _bio1 = 2.46;
      _den = 608;
      _eL = 0.5;
      _optDegree = 2460;
      _PPA = 30;
      break;
    case 7 : //lime
      _b2 = 15.75;
      _b3 = 0.02;
      _cr1 = 0.6533;
      _cr2 = 0.0602;
      _hmax = 25;
      _dmax = 300; //??
      _agemx = 400;
      _s = 0.2;
      _g = 80;
      _g2 = 0.6;
      _crate = 0.1;
      _DDmin = 1100;
      _DDmax = 4170;
      _bio0 = 0.0686;
      _bio1 = 2.4542;
      _den = 422;
      _eL = 0.5;
      _optDegree = 2635;
      _PPA = 20;
      break;
    case 8 : //Birch
      _b2 = 95.43;
      _b3 = 0.79;
      _cr1 = 0.2945;
      _cr2 = 0.085;
      _hmax = 30;
      _dmax = 60;
      _agemx = 120;
      _s = 1;
      _g = 200;
      _g2 = 2.2;
      _crate = 0.1;
      _DDmin = 410;
      _DDmax = 2300;
      _bio0 = 0.1682;
      _bio1 = 2.2864;
      _den = 417;
      _eL = 0.7;
      _optDegree = 1355;
      _PPA = 10;
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

void TreeFunctions::setHeight(float height)
{
  _currentHeight = height;
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

  _currentHeight = 137 + ((_b2 * _dbh) - (_b3 * (_dbh * _dbh)));
  _currentHeight = _currentHeight / 100;

  return _currentHeight;
}

float TreeFunctions::getBasalArea()
{
  return _BA;
}

float TreeFunctions::getVolume()
{
  return _volume;
}

float TreeFunctions::getWeight()
{
  return _vWeight;
}

float TreeFunctions::getOptG()
{
  return _optimalG;
}

float TreeFunctions::getRealG()
{
  return _realG;
}

float TreeFunctions::getGVigor()
{
  _gVigor = (_realG * 100) / _optimalG;
  return _gVigor;
}

float TreeFunctions::getEL()
{
  return _eL;
}

int TreeFunctions::getPPA()
{
  return _PPA;
}

float TreeFunctions::getOptDegree()
{
  return _optDegree;
}

float TreeFunctions::farHeight(float DBH)
{
  //fareast function
  float _dbh = DBH;

  float part1 = (_hmax - 1.3);
  float part2 = (_s * DBH) / (_hmax - 1.3);
  float part3 = 1 - (exp(-part2));
  float part4 = part1 * part3;

  float _currentHeight = 1.3 + part4;

  return _currentHeight;
}

float TreeFunctions::expHeight(float DBH)
{
  //SORTIE function implemented in the NetLogo
  float _dbh = DBH;

  float currentHeight = (_hmax * (1 - exp(-(_s / _hmax) * DBH)) * 100);

  return currentHeight;

}

float TreeFunctions::growth(float DBH, float tEffect, float lClimate, float pCover)
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

/*
  float lightEIV = 1.0;

  if (lClimate <= 0.9)
  {
    lightEIV = lClimate * 0.7; //value for pine
  } else {
    lightEIV = lClimate;
  }
*/
  float envirnOrig = ((tEffect + lClimate) / 2); // originally implemented function
  //float envirn = tEffect; // light climate removed to be replaced by shade intolerence values

  float envirnNew = tEffect * lClimate; //new function which reduces envirn varible by percent of light

  _realG = (part7 / part10) * envirnOrig;

  float currentDBH = _dbh + _realG;

  //cout << "DBH = " << currentDBH << endl;
  return currentDBH;
}

float TreeFunctions::fareastGrowth(float DBH, float cHeight)
{
  float _dbh = DBH;
  float _cHeight = cHeight;

  float part1 = _g2 * _dbh;
  //cout << "part 1 = " << part1 << endl;
  float part2 = _dmax * _hmax;
  //cout << "part 2 = " << part2 << endl;
  float part3 = _dbh * _cHeight;
  //cout << "part 3 = " << part3 << endl;
  float part4 = part3 / part2;
  //cout << "part 4 = " << part4 << endl;
  float part5 = 1.0 - part4;
  //cout << "part 5 = " << part5 << endl;
  float part6 = part1 * part5;
  //cout << "part 6 = " << part6 << endl;

  float part7 = 2.0 * _cHeight;
  //cout << "part 7 = " << part7 << endl;
  float part8 = -_s * _dbh;
  //cout << "part 8 = " << part8 << endl;
  float part9 = (_hmax - 1.3) * _dbh;
  //cout << "part 9 = " << part9 << endl;
  float part10 = part8 / part9;
  //cout << "part 10 = " << part10 << endl;
  float part11 = exp(part10);
  //cout << "part 11 = " << part11 << endl;
  float part12 = _s * part11;
  //cout << "part 12 = " << part12 << endl;
  float part13 = part7 + part12;
  //cout << "part 13 = " << part13 << endl;

  float growth = part6 / part13;

  float currentDBH = _dbh + growth;

  return currentDBH;

}

float TreeFunctions::crownRadius(float DBH)
{
  float _dbh = DBH;

  float _crownradius = (_crate * _dbh) / 2;

  return _crownradius;
}

float TreeFunctions::linCrownRadius(float DBH) // returns meters
{
  float _dbh = DBH;

  float _crownradius = _cr1 + (_cr2 * _dbh);

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
    else
    {
    _mortality = false;
    }
  }
}

void TreeFunctions::shadedMortality()
{
  int death = rand() % 1000;

  if (death < 368)
  {
    _mortality = true;
  }
  else
  {
  _mortality = false;
  }
}

void TreeFunctions::volume(float DBH, float height)
{
  float _radius = (DBH / 2) / 100;
  float _height = height;

  _volume = (M_PI * (pow(_radius,2))) * _height;
}

void TreeFunctions::basalArea(float DBH) // in meters squared
{
  float _dbh = DBH;
  _BA = M_PI * (pow(_dbh, 2) / 40000);
}

void TreeFunctions::vWeight()
{
  _vWeight = _volume * _den;
}

void TreeFunctions::jabowaMortality()
{
  jabRand();
  if(_jabRand <= _annualProb)
  {
    _mortality = true;
  }
}

void TreeFunctions::jabRand()
{
  _jabRand = (float) rand() / RAND_MAX;
}

void TreeFunctions::annualProb()
{
  _annualProb = 4.0 / _agemx;
}
