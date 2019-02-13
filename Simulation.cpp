#include "Simulation.h"
#include <string>

Simulation::Simulation()
{
  agentNo = 1000;
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
  output = new Output();

  for(int i=0; i<agentNo; i++)
  {
    trees[i] = new Tree(1,0,0);
  }

  display = new Display();

  display->initDisplay("Test Display",500,0,1000,1000,true);

  cout << endl << "Simulation class agents created " << endl;
  //create world
}

void Simulation::updateSimulation()
{
  //run tree commands
}

void Simulation::renderSimulation()
{
  tick = 0;

  const string part1 = "Output/tick";
  const string part2 = ".txt";

  while (display->running())
  {
    tick++;
    //const string all = ((part1 + to_string(tick))+ part2);
    //output->openFile(all);
    display->clearRenderer();
    display->renderDisplay();
    for(int i=0; i<agentNo; i++)
    {
      trees[i]->update(trees[i]->getDBH());
      display->handleEvents();
      //output->runOutput("ID ","Tree ",trees[i]->_x,trees[i]->_y,trees[i]->_DBH,trees[i]->_Height,trees[i]->_radius);
    }
    //world->renderWorld();
    display->updateDisplay();
    display->renderPresent();
    cout << "Tick = " << tick << endl;
    //output->closeFile();
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
  delete world;
  delete treeFunctions;
  delete output;
}
