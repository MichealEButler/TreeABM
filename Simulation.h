#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
#include "World.h"
#include "Display.h"
#include "Tree.h"
#include "Agent.h"
#include "TreeFunctions.h"
#include "Output.h"

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

private:
  Display * display;
  World * world;
  Agent ** agents;
  TreeFunctions * treeFunctions;
  vector<Tree*> trees; // = vector<Tree*>(10);
  //Tree ** trees;
  Output * output;
};

#endif
