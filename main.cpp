// #################################################################
// By Micheal Butler | 2019
// Email: mbutlermtb@gmail.com
// -----------------------------------------------------------------
// C++ and SDL2 agent based modelling framework for PhD research
//
// to compile:
// SDL2 library required for compilation
// run TreeABM file or run terminal command:
// sudo g++ main.cpp Display.cpp DrawFunctions.cpp World.cpp Agent.cpp TreeFunctions.cpp Tree.cpp -o main -lSDL2 -std=gnu++0x
//
//
// ##################################################################

#include <iostream>
#include "Simulation.h"

using namespace std;

Simulation * simulation;

int main(int argc, char** argv)
{
  simulation = new Simulation();

  simulation->initSimulation();
  simulation->renderSimulation();
  simulation->cleanSimulation();

  return 0;
}
