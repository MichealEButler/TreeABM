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
  Tree(int _id, int x, int y, int color);
  ~Tree();
  void setDBH(float DBH);
  void setHeight(float height);
  void setRadius(float radius);
  void setAge(float age);
  void setColor(int color);

  float getDBH();
  float getHeight();
  float getRadius();
  float getAge();
  bool getAlive();
  int getColor();

  void update(float DBH);

  void isAlive(bool alive);
  bool removeTree();

private:
  TreeFunctions* tf;

  bool _alive;
  float _startDBH;
  float _DBH;
  float _height;
  float _radius;
  float _age;
  int _color;
};

#endif
