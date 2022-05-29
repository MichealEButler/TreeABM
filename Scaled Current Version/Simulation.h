#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <random>
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
#include "Grid.h"
#include "Manage.h"
#include "Data.h"

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
  void setStartFile(int startFile);
  void setManageP(float percent);

  int agentNo;
  int agentNoSplit;

  int campNo;
  int species[8];

private:
  Patch ** patches;
  Input * input;
  Display * display;
  World * world2;
  Environment * environment;
  Recruitment * recruitment;
  Agent ** agents;
  //TreeFunctions * treeFunctions;
  vector<Tree*> trees; // = vector<Tree*>(10);
  //Tree ** trees;
  Output * output;
  Output * initOut;
  Chunk ** chunks;
  Camp ** camps;
  Manage * manage1;
  Data * data;

  //seperate species data objects (to be replaced to something more manageable)

  Data * standCohort;
  Data * elmCohort;
  Data * pineCohort;
  Data * oakCohort;
  Data * alderCohort;
  Data * hazelCohort;
  Data * ashCohort;
  Data * limeCohort;
  Data * birchCohort;

  int _worldState; // determines which raster asset to display
  int listLength; // for assessing tree ID's for patch ID list

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
  float _change;
  int _startFile;
  float _mpercent;

  vector<int> oakArray;
  vector<int> manageArray;
  vector<int> speciesMArray; //array which the targetted species are added to
  vector<int> arraycopy; // copy all trees to this to use for management as unsure of the effect of push from another array

  int treeHere[100][100];
  int numPatchTrees[100][100];

  bool _SDL;

};

#endif
