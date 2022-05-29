#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

class TreeFunctions
{

public:
  TreeFunctions();
  ~TreeFunctions();
  void setConstants(int species);
  float getHeight(float DBH);
  void initAge(float DBH);
  float farHeight(float DBH); //fareast height equation
  float expHeight(float DBH);
  float growth(float DBH, float tEffect, float lClimate, float pCover);
  float fareastGrowth(float DBH, float cHeight);
  float crownRadius(float DBH);
  float linCrownRadius(float DBH); // linear models constructed from Pretzsch (2015)
  float crownArea(float cradius);
  void updateGeometry(float DBH);
  float tempEffect(float DEGD);
  float biomass(float DBH);
  void slopeEffect();
  void mortality();
  void volume(float DBH, float height);
  void basalArea(float DBH);
  void vWeight(); //weight from stem volume
  void jabowaMortality();
  void jabRand(); // set random number for mortality function
  void annualProb(); //ammual probabily of death from JABOWA
  void shadedMortality(); // run when shade is greater than 90%

  void setSpecies(int species);
  void setB2(float b2);
  void setB3(float b3);
  void setHMAX(float hmax);
  void setDMAX(float dmax);
  void setS(float s);
  void setG(float g);
  void setCRATE(float crate);
  void setDDmin(float DDmin);
  void setDDmax(float DDmax);
  void setHeight(float height);

  int getAge();
  int getAgeMax();
  int getSpecies();
  float getB2();
  float getB3();
  float getHMAX();
  float getDMAX();
  float getS();
  float getG();
  float getCRATE();
  float getDDmin();
  float getDDmax();
  float getTEffect();
  float getBiomass();
  bool getMortality();
  float getBasalArea();
  float getVolume();
  float getWeight(); //calculated from volume (stem weight)
  float getEL(); //returns light eiv
  int getPPA();

  float getOptDegree(); // return optimal degrees for species

  float getOptG();
  float getRealG();
  float getGVigor(); //returns percentage of what the optimal growth should be

private:
  const float PI = 3.14159265358979f;

  int _species;
  float _b2;
  float _b3;
  float _cr1;
  float _cr2;
  float _hmax;
  float _dmax;
  float _agemx;
  float _s;
  float _g;
  float _g2;
  float _crate;
  float _age;
  float _DDmin;
  float _DDmax;
  float _tEffect;
  float _bio0;
  float _bio1;
  float _biomass;
  float _currentHeight;
  float _seedmax;
  float _volume;
  float _BA; // basal area
  float _vWeight;
  float _den; //density for volume to weight conversion
  float _eL; //light eiv
  int _PPA; // age at which species produces pollen

  float _optDegree; //optimum degree days for a species used for testing stand dynamics for validation

  float _optimalG;
  float _realG;
  float _currentDBH;
  float _gVigor;

  bool _mortality;
  float _jabRand; // random number generation for mortality
  float _annualProb; // annual probaility of death from JABOWA
  int tick;
};

#endif
