#include "Simulation.h"

Simulation::Simulation()
{
  agentNo = 10;
  agentNoSplit = 1;
  cout << endl << "Simulation class agents created " << endl;
}

Simulation::~Simulation()
{
  cout << endl << "Simulation class destroyed! " << endl << endl;
}

void Simulation::initSimulation()
{
  //create agents
  agents = new Agent*[agentNo];
  trees = new Tree*[agentNo/agentNoSplit];

  for(int i=0; i<agentNo; i++)
  {
    trees[i] = new Tree();
  }

  display = new Display();

  display->initDisplay("Test Display",0,0,1000,1000,true);

  cout << endl << "Simulation class agents created " << endl;
  //create world
}

void Simulation::updateSimulation()
{
  //run tree commands
}

void Simulation::renderSimulation()
{
  while (display->running())
  {
    for(int i=0; i<agentNo; i++)
    {
      trees[i]->renderAgent();
      display->handleEvents();
    }
    //world->renderWorld();
    display->updateDisplay();
    display->renderDisplay();
  }
}

void Simulation::cleanSimulation()
{
  display->cleanDisplay();

  for(int i = 0; i < agentNo; i++)
  {
    delete agents[i]; // calls each ~Agent()
  }

  for(int i = 0; i < agentNo; i++)
  {
    delete trees[i]; // calls each ~Agent()
  }

  delete display;
}
