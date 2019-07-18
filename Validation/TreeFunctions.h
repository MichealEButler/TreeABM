#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include <iostream>
#include <cmath>

using namespace std;

class TreeFunctions
{

public:
  TreeFunctions();
  ~TreeFunctions();
  void setConstants(int species);
  float getHeight(float DBH);
  void initAge(float DBH);
  float expHeight(float DBH);
  float growth(float DBH, float tEffect, float lClimate);
  float crownRadius(float DBH);
  float crownArea(float cradius);
  void updateGeometry(float DBH);
  float tempEffect(float DEGD);
  float biomass(float DEGD);
  void slopeEffect();
  void mortality();

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
  void setDBHrange(float DBH); // allocates number based on DBH 

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

private:
  const float PI = 3.14159265358979f;

  int _species;
  float _b2;
  float _b3;
  float _hmax;
  float _dmax;
  float _agemx;
  float _s;
  float _g;
  float _crate;
  float _age;
  float _DDmin;
  float _DDmax;
  float _tEffect;
  float _bio0;
  float _bio1;
  float _biomass;
  int _DBHrange; // this value taken from Bunce survey incremental every 5cm change

  float _optimalG;
  float _realG;
  float _currentDBH;

  bool _mortality;
  int tick;
};

#endif
