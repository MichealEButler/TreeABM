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
  void setTreeCoverTwo(int treeID); // adds to vector
  void clearTreeIDs();
  void setNeighbors();
  void outNeighbors();

  int getID();
  int getX();
  int getY();
  int getNumCover();
  int getHTree();

private:
  int _id;
  int _x;
  int _y;
  int _numCover; // number of trees covering it
  int _hTree; // highest tree id
  int neighbors[8]; // array of neighbors
  int neighbors4[4]; // von neumann neighbors
  vector <int> treeIDs; //vector of trees covering this patch
};

#endif
