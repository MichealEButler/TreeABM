#ifndef PATCH_H
#define PATCH_H

#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

class Patch
{
public:
  Patch();
  ~Patch();

  void setX(int x);
  void setY(int y);
  void setID(int id);
  void setTreeCover(vector<Tree*> trees);

  int getID();
  int getX();
  int getY();
  int getNumCover();
  vector<int> getTreeCover(); // get ID's of trees

private:
  int _id;
  int _x;
  int _y;
  vector<int> treeCover; // puts ID's of tree's covering the patch
  int _numCover; // number of trees covering it
};

#endif
