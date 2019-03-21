#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Agent.h"
#include "TreeFunctions.h"
#include "DrawFunctions.h"
//#include "Chunk.h"

using namespace std;

class Tree : public Agent
{
protected:
  //Chunk *_chunk;

public:
  Tree();
  Tree(int _id, int x, int y, int species);
  ~Tree();
  void setDBH(float DBH);
  void setHeight(float height);
  void setRadius(float radius);
  void setAge(float age);
  void setSpecies(int species);
  void setChunk();
  void storeSlope(); // needs to refernce the world

  void getNeighbors(vector<Tree*> cTrees);

  float getDBH();
  float getHeight();
  float getRadius();
  float getAge();
  bool getAlive();
  int getSpecies();
  int getChunk();

  void update(float DBH, SDL_Renderer * renderer);

  void isAlive(bool alive);
  bool removeTree();

private:
  TreeFunctions* tf;
  vector<Tree*> _nTrees; // neighbor trees

  bool _alive;
  float _startDBH;
  float _DBH;
  float _height;
  float _radius;
  float _age;
  int _species;
  int _chunk;
  float _slope;
};

#endif
