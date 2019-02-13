#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Agent.h"
#include "TreeFunctions.h"
#include "Display.h"
#include "DrawFunctions.h"

using namespace std;

class Tree : public Agent
{
public:
  Tree();
  Tree(int _id, int x, int y);
  ~Tree();
  void setDBH(float DBH);
  float getDBH();
  void update(float DBH);

  TreeFunctions* tf;
  // need a functions which inputs species data from file perhaps use enum classes to extend Tree class

  float _startDBH;
  float _DBH;
  float _Height;
  float _radius;
  float _age;
private:

};

#endif
