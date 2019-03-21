#include "Simulation.h"
#include <string>

Simulation::Simulation()
{
  agentNo = 18000;
  elmNo = 6000;
  pineNo = 6000;
  oakNo = 6000;
  campNo = 1;
  agentNoSplit = 1;
  cout << endl << "Simulation class agents created " << endl;
}

Simulation::~Simulation()
{
  cout << endl << "Simulation class destroyed! " << endl << endl;
}

void Simulation::initSimulation()
{
  output = new Output();

  //to be called during initial run to construct chunk directories
  output->createDirectories();
  //create agents
  //agents = new Agent*[agentNo];
  chunks = new Chunk*[100];
  camps = new Camp*[campNo];

//  vector<Tree*> trees(agentNo/agentNoSplit);
  trees = vector<Tree*>(agentNo/agentNoSplit);

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

  // create the array of chunks and ask each chunk to reference which trees are in their space
  for(int i = 0; i < 100; i++)
  {
    chunks[i] = new Chunk(i);
    chunks[i]->storeNeighbours();
  }

  for (int i = 0; i < campNo; i++)
  {
      camps[i] = new Camp(-1, 500, 500, 20,20);
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
  int newAgents = 2000;

  const string part1 = "Output/tick"; // you must create a folder called Output in src dirctory
  const string part2 = ".txt";

  while (display->running() && tick < 200)
  {
    tick++;
    const string all = ((part1 + to_string(tick))+ part2);
    output->openFile(all);
    display->clearRenderer();
    display->renderDisplay();

    // stores vector of trees within chunks
    for(int i = 0; i < 100; i++)
    {
      chunks[i]->storeTrees(trees, tick);
    }

    for(int i = 0; i < trees.size(); i++)
    {
      trees[i]->getNeighbors(chunks[(trees[i]->getChunk())]->chunkTrees);
    }

    for(int i=0; i<trees.size(); i++)
    {
      if(trees[i]->removeTree() == true)
      {
        trees.erase(trees.begin() + i);
      }

      trees[i]->update(trees[i]->getDBH(), Display::renderer);

      //trees[i]->isAlive(trees[i]->getAlive());
    }

    for (int i = 0; i < campNo; i++)
    {
      //camps[i]->drawCamp(Display::renderer);
    }

    for(int i=0; i<trees.size(); i++)
    {
      string species;

      if(trees[i]->getSpecies() == 1)
      {
        species = "Elm";
      }
      else if(trees[i]->getSpecies() == 2)
      {
        species = "Pine";
      }
      else if (trees[i]->getSpecies() == 3)
      {
        species = "Oak";
      }

      //output->blenderOutput(trees[i]->getID(),species,trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),trees[i]->getRadius());
      output->runOutput(trees[i]->getID(),species,trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),trees[i]->getRadius(),trees[i]->getChunk());
    }
    //world->renderWorld();
    int recruit = agentNo+((newAgents*tick)-agentNo); // for id's

    for (int i = 0; i < newAgents; i++)
    {
      int randS = rand() % 3 + 1;

      trees.push_back(new Tree(recruit+i, 0,0,randS));
      display->handleEvents();
    }

    cout << "Trees = " << trees.size() << endl;

/*  // fr displaying grid of chunks
    if(display->cPressed())
    {
      for(int i = 0; i < 10; i++)
      {
        for (int j = 0; j < 10; j++)
        {
          //chunk->loadChunk((i*100),(i*100+100),(j*100),(j*100+100), Display::renderer);
        }
      }
    }
*/

    display->updateDisplay();
    display->renderPresent();

    cout << "Tick = " << tick << endl;
    output->closeFile();

    for(int i = 0; i < 100; i++)
    {
      chunks[i]->chunkTrees.clear();
    }
  }
}

void Simulation::cleanSimulation()
{
  display->cleanDisplay();

  for(int i = 0; i < 100; i++)
  {
    //chunks[i]->deleteTrees();
    delete chunks[i];
  }

/*
  for(int i = 0; i < agentNo; i++)
  {
    delete agents[i]; // calls each ~Agent()
  }
*/
  for(int i = 0; i < trees.size(); i++)
  {
    delete trees[i]; // calls each ~Agent()
  }

  for(int i = 0; i < campNo; i++)
  {
    delete camps[i]; // calls each ~Agent()
  }

  delete display;
  delete world;
  delete treeFunctions;
  delete output;
}
