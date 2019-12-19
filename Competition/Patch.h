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
  void setTreeCoverC(Tree* circle);
  void setPixelCoverC(Tree* circle);
  void storePixels(int width, int height); // takes in display parameters to determine pixel locations within patches

  int getID();
  int getX();
  int getY();
  int getNumCover();
  vector<int> getTreeCover(); // get ID's of trees
  vector<int> getCCover();

private:
  int _id;
  int _x;
  int _y;
  vector<int> treeCover; // puts ID's of tree's covering the patch
  vector<int> circleCover;
  vector<int> pixelCover;
  int _numCover; // number of trees covering it
};

#endif
