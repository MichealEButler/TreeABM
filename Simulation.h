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

  int agentNo;
  int agentNoSplit;
  int tick;

  int elmNo;
  int pineNo;
  int oakNo;
  int alderNo;
  int hazelNo;
  int ashNo;
  int limeNo;
  int birchNo;
  int campNo;

  int species[8];

private:
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

  bool treeHere[1000][1000];

};

#endif
