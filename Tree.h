#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Agent.h"

using namespace std;

class Tree : public Agent
{
public:
  Tree();
  ~Tree();
  void setDBH(float DBH);
  float getDBH();
  void update(float DBH);
  // need a functions which inputs species data from file perhaps use enum classes to extend Tree class
private:
  float _DBH;
  float _Height;
  float _radius;
  float _age;
};

#endif
