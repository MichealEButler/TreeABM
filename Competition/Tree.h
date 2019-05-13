#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Tree
{
public:
  Tree();
  Tree(int id);
  ~Tree();

  int getX();
  int getY();
  int getCRadius();
  int getHeight();
  int getID();
  bool getDominance();
  int getTCover();
  int getMyPatches();
  float intersectArea(float Ax, float Ay, float Bx, float By, float Ar, float Br);

  void setNeighbors(vector<Tree*> trees);
  void setDominance(vector<Tree*> nTrees);
  void setTCover();
  void outData();
  void resetPatches();

  void referencePatches(int num); // takes in a vector of the

private:
  vector<Tree*> _nTrees; // neighouring trees
  vector<int> _idTrees;

  int _x;
  int _y;
  int _id;
  int _cradius;
  int _height;
  bool _dominance;

  int _tCover;
  int _myPatches;

  float _canopyCover;

  const float PI = 3.14159265358979f;
};

#endif
