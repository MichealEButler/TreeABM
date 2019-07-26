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
#include <ctime>
#include <time.h>
#include "Simulation.h"
#include "Input.h"

using namespace std;

Simulation * simulation;
Input * input;

int main(int argc, char** argv)
{
  srand(time(NULL));
  unsigned long seconds = 10;
  unsigned long begTime = clock();

  simulation = new Simulation();
  input = new Input();

/*
  simulation->initSimulation();
  simulation->renderSimulation();
  simulation->cleanSimulation();
*/

  input->loadPlotFile("Input/Balsham.txt", 1);
  input->readVectors();

  unsigned long elapsedTime = ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
  cout << "Elapsed time: " << elapsedTime << " secs." << endl;

  delete input;

  return 0;
}
