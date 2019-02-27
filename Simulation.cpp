#include "Simulation.h"
#include <string>

Simulation::Simulation()
{
  agentNo = 9000;
  elmNo = 3000;
  pineNo = 3000;
  alderNo = 3000;
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

//  vector<Tree*> trees(agentNo/agentNoSplit);
  trees = vector<Tree*>(agentNo/agentNoSplit);

  output = new Output();

  for(int i=0; i<agentNo; i++)
  {
    if (i<elmNo)
    {
      trees[i] = new Tree(i,0,0,1);
    }
    else if (i>=elmNo&&i<elmNo+pineNo)
    {
      trees[i] = new Tree(i,0,0,2);
    }
    else if (i>=elmNo+pineNo && i<agentNo)
    {
      trees[i] = new Tree(i,0,0,3);
    }
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
  char input;
  int newAgents = 1000;

  const string part1 = "Output/tick"; // you must create a folder called Output in src dirctory
  const string part2 = ".txt";

  while (display->running())
  {
    tick++;
    const string all = ((part1 + to_string(tick))+ part2);
    output->openFile(all);
    display->clearRenderer();
    display->renderDisplay();

    for(int i=0; i<trees.size(); i++)
    {
      trees[i]->update(trees[i]->getDBH());
      //trees[i]->isAlive(trees[i]->getAlive());

      if(trees[i]->removeTree() == true)
      {
        trees.erase(trees.begin() + i);
        //cout << "Agent deleted! " << endl;
      }
    }

    for(int i=0; i<trees.size(); i++)
    {
      //cout << "Agent deleted " << endl;
      output->runOutput(trees[i]->getID(),"Tree ",trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),trees[i]->getRadius());
    }
    //world->renderWorld();
    int recruit = agentNo+((newAgents*tick)-1000); // for id's

    for (int i = 0; i < newAgents; i++)
    {
      trees.push_back(new Tree(recruit+i, 0,0,1));
    }

    display->updateDisplay();
    display->renderPresent();
    cout << "Tick = " << tick << endl;
    output->closeFile();
    display->handleEvents();
  }
}

void Simulation::cleanSimulation()
{
  display->cleanDisplay();

  for(int i = 0; i < agentNo; i++)
  {
    delete agents[i]; // calls each ~Agent()
  }

  for(int i = 0; i < trees.size(); i++)
  {
    delete trees[i]; // calls each ~Agent()
  }

  delete display;
  delete world;
  delete treeFunctions;
  delete output;
}
