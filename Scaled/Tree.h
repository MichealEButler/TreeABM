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
  void setupAge();
  void randomDBH();
  void setHeight(float height);
  void setRadius(float radius);
  void setAge(int age);
  void setSpecies(int species);
  void setChunk();
  void setDominance();
  void setPDominace();
  void storeSlope(); // needs to refernce the world
  void setElevation(float worldElevation);
  void resetPatches();
  void setTCover();
  void referencePatches(int num);
  void storePatches(); // generates an array of id's based on location and size of individuals crown

  void getNeighbors(vector<Tree*> cTrees);

  float getDBH();
  float getHeight();
  float getRadius();
  int getAge();
  bool getAlive();
  bool getDominance();
  bool getPDominance(); // sets true if tree over patch is the highest
  int getSpecies();
  float getBiomass();
  int getChunk();
  float getElevation();
  float getLEffect();
  int getMyPatches();

  void setTEffect(float DEGD);
  void lightEffect();
  float getTEffect();

  void update(float DBH, float tEffect, float lClimate);
  void draw(SDL_Renderer * renderer);

  void isAlive(bool alive);
  void setCMortality();
  bool crowdingMortality();
  bool removeTree();
  bool ageMortality();

private:
  TreeFunctions* tf;
  vector<Tree*> _nTrees; // neighbor trees
  vector<int> _idTrees;
  vector<int> _npatches; // id of all patches covered by individual

  bool _alive;
  bool _dominance;
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
  bool _aMortality;
  bool _pDominace;
  float _lEffect;

  int _tCover;
  int _myPatches;
};

#endif
