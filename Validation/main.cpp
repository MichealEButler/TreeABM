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

using namespace std;

Simulation * simulation;

int main(int argc, char** argv)
{
  int iterate = 0;

  srand(time(NULL));
  unsigned long seconds = 10;
  unsigned long begTime = clock();

  cout << "Specify iterations: ";
  cin >> iterate;

  for(int i = 0; i < iterate; i++)
  {
    simulation = new Simulation();

    int itPlot = 0;

    while(itPlot < 16)
    {
      itPlot++;
      simulation->setPlot(itPlot);
      simulation->setIteration(i+1);
      simulation->initSimulation();
      simulation->renderSimulation();
      simulation->cleanSimulation();
    }

    delete simulation;
  }

  unsigned long elapsedTime = ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
  cout << "Elapsed time: " << elapsedTime << " secs." << endl;

  return 0;
}
