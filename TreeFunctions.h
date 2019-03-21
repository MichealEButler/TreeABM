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
  float initAge(float DBH);
  float expHeight(float DBH);
  float growth(float DBH);
  float crownRadius(float DBH);
  void updateGeometry(float DBH);
  void tempEffect(float tEffect);
  void slopeEffect();
  void mortality();

  void setAge(int age);
  void setSpecies(int species);
  void setB2(float b2);
  void setB3(float b3);
  void setHMAX(float hmax);
  void setDMAX(float dmax);
  void setS(float s);
  void setG(float g);
  void setCRATE(float crate);

  int getAge();
  int getSpecies();
  float getB2();
  float getB3();
  float getHMAX();
  float getDMAX();
  float getS();
  float getG();
  float getCRATE();

private:
  int _species;
  float _b2;
  float _b3;
  float _hmax;
  float _dmax;
  float _s;
  float _g;
  float _crate;
  float _age;

  float _currentDBH;

  int tick;
};

#endif
