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
  float getHeight(float DBH);
  float expHeight(float DBH);
  float growth(float DBH);
  float crownRadius(float DBH);
  void updateGeometry(float DBH);

private:
  float b2;
  float b3;
  float HMAX;
  float DMAX;
  float S;
  float G;
  float c_rate;

  float _currentDBH;

  int tick;
};

#endif
