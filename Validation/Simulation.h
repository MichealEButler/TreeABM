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
  void setConsts(int ticks, float elmNo, float pineNo, float oakNo, float alderNo, float hazelNo, float ashNo, float limeNo, float birchNo, float change);
  void setupPatches();
  void outputCounts();
  void bunceRecruits();
  void setPlot(int plot);

  int agentNo;
  int agentNoSplit;
  int species[8];

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
  int _plot;

  int _isElm;
  int _isPine;
  int _isOak;
  int _isAlder;
  int _isHazel;
  int _isAsh;
  int _isLime;
  int _isBirch;
  float _change;

  int _plotPopulation;

  int treeHere[14][14];
  int numPatchTrees[14][14];

  bool _SDL;

};

#endif
