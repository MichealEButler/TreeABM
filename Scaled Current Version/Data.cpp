#include "Data.h"

Data::Data()
{
  _BA = 0;
  _QMD = 0;
  _pop = 0;
  _biomass = 0;
  _SDI = 0;
  _BIO = 0;
  _BIOA = 0;
}

Data::~Data()
{

}

void Data::basalArea(float BA)
{
  _BA = _BA + BA;
}

void Data::QMD()
{
  _QMD = sqrt (_BA / (0.0000785 * _pop));
}

void Data::QMD2(float avgDiameter)
{
  _QMD2 = sqrt (avgDiameter / _pop);
}

void Data::population(int pop)
{
  _pop = _pop + pop;
}

void Data::cohortBiomass(float biomass)
{
  _biomass = _biomass + biomass;
}

void Data::BIO(float BIO)
{
  _BIO = _BIO + BIO;
}

void Data::BIOA(float BIOA)
{
  _BIOA = _BIOA + BIOA;
}

void Data::setBasalArea(float BA)
{
  _BA = BA;
}

void Data::setQMD(float QMD)
{
  _QMD = QMD;
}

void Data::setPopulation(int pop)
{
  _pop = pop;
}

void Data::setCohortBiomass(float biomass)
{
  _biomass = biomass;
}

void Data::setSDI(float SDI)
{
  _SDI = SDI;
}

void Data::setBIO(float BIO)
{
  _BIO = BIO;
}

void Data::setBIOA(float BIO)
{
  _BIOA = BIO;
}

void Data::SDI()
{
  _SDI = _pop * pow((25/_QMD), -1.605);
}

void Data::calcSpeciesVigor(int speciesPop)
{

}

float Data::getBasalArea()
{
  return _BA;
}

float Data::getQMD()
{
  return _QMD;
}

float Data::getPopulation()
{
  return _pop;
}

float Data::getQMD2()
{
  return _QMD2;
}

float Data::getBiomass()
{
  return _biomass;
}

float Data::getSDI()
{
  return _SDI;
}

float Data::getBIO()
{
  return _BIO;
}

float Data::getBIOA()
{
  return _BIOA;
}
