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
#include <vector>
#include "Simulation.h"

using namespace std;

vector<Simulation*> simulations;

int main(int argc, char** argv)
{

  simulations = vector<Simulation*>(1);

  srand(time(NULL));

  unsigned long seconds = 10;
  unsigned long begTime = clock();

  int counter = 0;
  int startFile = 0;

  float m1 = 0.1;

  for(int i = 0; i < 1; i++)
  {
    for(int i = 0; i < 1; i++)
    {

      simulations[i] = new Simulation();

      simulations[i]->setStartFile(startFile);
      simulations[i]->setManageP(m1);
      simulations[i]->initSimulation();
      simulations[i]->renderSimulation();
      simulations[i]->cleanSimulation();

      delete simulations[i];

      startFile++;

    }

    m1 = m1 + 0.1;

    /*
    if(m1 == 1.0)
    {
      m1 = 0.98;
    }
    */

  }

  unsigned long elapsedTime = ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
  cout << "Elapsed time: " << elapsedTime << " secs." << endl;

  return 0;
}
