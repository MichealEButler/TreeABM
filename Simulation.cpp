#include "Simulation.h"
#include <string>

Simulation::Simulation()
{
  for (int i = 0; i < 1000; i++)
  {
    for (int j = 0; j < 1000; j++)
    {
        treeHere[i][j] = false;
    }
  }

  agentNo = 18000;
  elmNo = 6000;
  pineNo = 6000;
  oakNo = 6000;
  alderNo = 0;
  hazelNo = 0;
  ashNo = 0;
  limeNo = 0;
  birchNo = 0;
  campNo = 1;
  agentNoSplit = 1;

  for(int i = 0; i < 8; i++)
  {
    species[i] = 0;

    if(elmNo > 0 && i == 0)
    {
      species[i] = 1;
    }

    if(pineNo > 0 && i == 1)
    {
      species[i] = 2;
    }

    if(oakNo > 0 && i == 2)
    {
      species[i] = 3;
    }

    if(alderNo > 0 && i == 3)
    {
      species[i] = 4;
    }

    if(hazelNo > 0 && i == 4)
    {
      species[i] = 5;
    }

    if(ashNo > 0 && i == 5)
    {
      species[i] = 6;
    }

    if(limeNo > 0 && i == 6)
    {
      species[i] = 7;
    }

    if(birchNo > 0 && i == 7)
    {
      species[i] = 8;
    }
  }

  cout << endl << "Simulation class agents created " << endl;

  for(int i = 0; i < 8; i++)
  {
    cout << species[i] << " ";
  }
  cout << endl;
}

Simulation::~Simulation()
{
  cout << endl << "Simulation class destroyed! " << endl << endl;
}

void Simulation::initSimulation()
{
  world = new World();
  world->loadWorld("Input/nz7204_DTM_1M.txt");

  output = new Output();
  environment = new Environment();
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
      trees[i]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[i]->getX()][trees[i]->getY()] == true)
      {
        trees[i]->setCMortality();
      }
      else
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = true;
      }
    }
    else if (i>=elmNo&&i<elmNo+pineNo)
    {
      trees[i] = new Tree(i,0,0,2);
      trees[i]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[i]->getX()][trees[i]->getY()] == true)
      {
        trees[i]->setCMortality();
      }
      else
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = true;
      }
    }
    else if (i>=elmNo+pineNo && i<agentNo)
    {
      trees[i] = new Tree(i,0,0,3);
      trees[i]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[i]->getX()][trees[i]->getY()] == true)
      {
        trees[i]->setCMortality();
      }
      else
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = true;
      }
    }
  }

  // create the array of chunks and ask each chunk to reference which trees are in their space
  for(int i = 0; i < 100; i++)
  {
    chunks[i] = new Chunk(i+1);
    chunks[i]->storeNeighbours();
  }

  for (int i = 0; i < campNo; i++)
  {
      camps[i] = new Camp(-1, 500, 500, 20,20);
  }

  recruitment = new Recruitment(2000, species);
  display = new Display();

  display->initDisplay("Test Display",500,0,1000,1000,true);

  cout << endl << "Simulation class agents created " << endl;

  environment->loadDEGD("Input/DEGD.txt");
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
  int startID = agentNo;

  const string part1 = "Output/tick"; // you must create a folder called Output in src dirctory
  const string part2 = ".txt";

  while (display->running() && tick <= 100)
  {
    tick++;
    const string all = ((part1 + to_string(tick))+ part2);
    output->openFile(all);
    display->clearRenderer();
    display->renderDisplay();

    recruitment->speciesProbability(environment->_DEGD[tick-1], 2000);

    // stores vector of trees within chunks
    for(int i = 0; i < 100; i++)
    {
      chunks[i]->storeTrees(trees, tick);
      //cout << "Trees stored in chunks! " << chunks[i]->getID() << endl;
    }

    for(int i=0; i<trees.size(); i++)
    {
      //cout << "DEGD " << environment->_DEGD[tick-1] << endl;
      trees[i]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[i]->getNeighbors(chunks[(trees[i]->getChunk()-1)]->chunkTrees);
      trees[i]->setTEffect(environment->_DEGD[tick-1]); // not working as intended
      trees[i]->update(trees[i]->getDBH(), trees[i]->getTEffect(), Display::renderer);
      trees[i]->setAge(trees[i]->getAge(), 1);

      if(trees[i]->removeTree() == true)
      {
        trees.erase(trees.begin() + i);
      }


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

      output->blenderOutput(trees[i]->getID(),trees[i]->getSpecies(),trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),trees[i]->getRadius(), trees[i]->getElevation());
      //output->runOutput(trees[i]->getID(),species,trees[i]->getAge(),trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),trees[i]->getRadius(),trees[i]->getBiomass(),trees[i]->getChunk());

    }
    //world->renderWorld();
    int recruit = agentNo+((newAgents*tick)-agentNo); // for id's

    // call function from recruitment for size of newAgents array


    // call function from recruitment for how many of each species to recruit


    for(int i = 0; i < recruitment->getNumElm(); i++)
    {
      trees.push_back(new Tree(startID, 0,0,1));
      startID++;
    }

    for(int i = 0; i < recruitment->getNumPine(); i++)
    {
      trees.push_back(new Tree(startID, 0,0,2));
      startID++;
    }

    for(int i = 0; i < recruitment->getNumOak(); i++)
    {
      trees.push_back(new Tree(startID, 0,0,3));
      startID++;
    }

    cout << "Trees = " << trees.size() << endl;

    display->updateDisplay();
    display->renderPresent();

    cout << "Tick = " << tick << endl;
    output->closeFile();

    for(int i = 0; i < 100; i++)
    {
      chunks[i]->chunkTrees.clear();
    }

    cout << "<---------------------------------------->" << endl << endl;

    display->handleEvents();
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
