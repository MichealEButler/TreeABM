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
#include "Camp.h"
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
  void setConsts(int ticks, int elmNo, int pineNo, int oakNo, int alderNo, int hazelNo, int ashNo, int limeNo, int birchNo);
  void setupPatches();

  int agentNo;
  int agentNoSplit;

  int campNo;
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
  Camp ** camps;

  int _ticks;
  int _elmNo;
  int _pineNo;
  int _oakNo;
  int _alderNo;
  int _hazelNo;
  int _ashNo;
  int _limeNo;
  int _birchNo;

  int _isElm;
  int _isPine;
  int _isOak;
  int _isAlder;
  int _isHazel;
  int _isAsh;
  int _isLime;
  int _isBirch;

  int treeHere[100][100];
  int numPatchTrees[100][100];

  bool _SDL;

};

#endif
