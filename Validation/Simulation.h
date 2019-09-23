#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
#include <string>
#include "World.h"
#include "Display.h"
#include "Tree.h"
#include "Agent.h"
#include "TreeFunctions.h"
#include "Output.h"
#include "Chunk.h"
#include "Environment.h"
#include "Recruitment.h"
#include "Input.h"
#include "Patch.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  ~Simulation();
  void initSimulation();
  void updateSimulation();
  void renderSimulation();
  void cleanSimulation();
  void setConsts(int ticks, float elmNo, float pineNo, float oakNo, float alderNo, float hazelNo, float ashNo, float limeNo, float birchNo, float hornNo, float larchNo, float beechNo, float willowNo, float mapleNo, float pftNo, float change);
  void setupPatches();
  void outputCounts();
  void bunceRecruits();
  void setPlot(int plot);
  void setIteration(int iteration);

  int agentNo;
  int agentNoSplit;
  int species[14];

private:
  Patch ** patches;
  Input * input;
  Display * display;
  World * world;
  Environment * environment;
  Recruitment * recruitment;
  Agent ** agents;
  TreeFunctions * treeFunctions;
  vector<Tree*> trees; // = vector<Tree*>(10);
  //Tree ** trees;
  Output * output;
  Chunk ** chunks;

  int _worldState; // determines which raster asset to display

  int _ticks;
  int _elmNo;
  int _pineNo;
  int _oakNo;
  int _alderNo;
  int _hazelNo;
  int _ashNo;
  int _limeNo;
  int _birchNo;
  int _hornNo;
  int _larchNo;
  int _beechNo;
  int _willowNo;
  int _mapleNo;
  int _pftNo;
  int _plot;
  int _iteration;

  int _isElm;
  int _isPine;
  int _isOak;
  int _isAlder;
  int _isHazel;
  int _isAsh;
  int _isLime;
  int _isBirch;
  int _isHorn;
  int _isLarch;
  int _isBeech;
  int _isWillow;
  int _isMaple;
  int _isPFT;
  float _change;

  int _plotPopulation;

  int treeHere[14][14];
  int numPatchTrees[14][14];

  bool _SDL;

};

#endif
