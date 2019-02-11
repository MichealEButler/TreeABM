#include "Tree.h"
#include "TreeFunctions.h"

Tree::Tree()
{
  _DBH = 5;
  cout << "Tree Created! " << endl;
}

Tree::~Tree()
{
  cout << "Tree Destroyed! " << endl;
}

void Tree::update(float DBH)
{
  TreeFunctions* tf;
  tf = new TreeFunctions();

  float height = tf->getHeight(DBH);
  cout << "Height = " << height << endl;
}

void Tree::setDBH(float DBH)
{
  _DBH = DBH;
}

float Tree::getDBH()
{
  return _DBH;
}
