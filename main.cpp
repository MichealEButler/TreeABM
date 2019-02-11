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
#include "Display.h"
#include "World.h"
#include "Agent.h"
#include "Tree.h"

using namespace std;

const int NUM_AGENTS = 100;

Display *display = nullptr;
//World *world;
Tree *tree;

int main(int argc, char** argv)
{
  int agentNo = NUM_AGENTS;
  Agent **agents = new Agent*[agentNo];
  for(int i=0; i<agentNo; i++)
    agents[i] = new Agent(1, 0, 0);

  display = new Display();
  tree = new Tree();

  tree->update(tree->getDBH());

  display->initDisplay("Test Display",0,0,1000,1000,true);

  while (display->running()) {
    for(int i=0; i<agentNo; i++){
      agents[i]->renderAgent();
      display->handleEvents();
    }
    //world->renderWorld();
    display->updateDisplay();
    display->renderDisplay();

  }

  display->cleanDisplay();

//  delete world;

  for(int i = 0; i < agentNo; i++)
    delete agents[i]; // calls each ~Agent()

  delete tree;


  return 0;
}
