#include "Tree.h"

DrawFunctions * drawFunctionsTree = nullptr;

Tree::Tree(int _id, int x, int y) : Agent(_id, x, y)
{
  _DBH = rand() % 10;

  x = _x;
  y = _y;

  tf = new TreeFunctions();
  //cout << "Tree Created! " << endl;
  //cout << "x = " << x << endl;
  //cout << "y = " << y << endl;
}

Tree::~Tree()
{
  //cout << "Tree Destroyed! " << endl;
}

void Tree::update(float DBH)
{
  setDBH(DBH);

  _height = tf->getHeight(DBH);
  setDBH(tf->growth(DBH));
  _radius = (tf->crownRadius(DBH));

  drawFunctionsTree = new DrawFunctions();

  drawFunctionsTree->fillCircle(Display::renderer,_x,_y,_radius);

}

void Tree::setDBH(float DBH)
{
  _DBH = DBH;
}

void Tree::setHeight(float height)
{
  _height = height;
}

void Tree::setRadius(float radius)
{
  _radius = radius;
}

void Tree::setAge(float age)
{
  _age = age;
}

float Tree::getDBH()
{
  return _DBH;
}

float Tree::getHeight()
{
  return _height;
}

float Tree::getRadius()
{
  return _radius;
}

float Tree::getAge()
{
  return _age;
}
