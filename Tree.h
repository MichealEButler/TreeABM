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
  void setAge(int age, int ticks);
  void setSpecies(int species);
  void setChunk();
  void storeSlope(); // needs to refernce the world
  void setElevation(float worldElevation);

  void getNeighbors(vector<Tree*> cTrees);

  float getDBH();
  float getHeight();
  float getRadius();
  int getAge();
  bool getAlive();
  int getSpecies();
  float getBiomass();
  int getChunk();
  float getElevation();

  void setTEffect(float DEGD);
  float getTEffect();

  void update(float DBH, float tEffect, SDL_Renderer * renderer);

  void isAlive(bool alive);
  void setCMortality();
  bool crowdingMortality();
  bool removeTree();

private:
  TreeFunctions* tf;
  vector<Tree*> _nTrees; // neighbor trees
  vector<int> _idTrees;

  bool _alive;
  float _startDBH;
  float _DBH;
  float _height;
  float _radius;
  float _biomass;
  int _age;
  int _species;
  int _chunk;
  float _slope;
  float _tEffect;
  float _elevation;
  bool _cMortality;
};

#endif
