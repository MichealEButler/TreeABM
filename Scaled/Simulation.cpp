#include "Simulation.h"
#include <string>

Simulation::Simulation()
{
  char set;
  _worldState = 0;

  cout << "Simulation is initialising! " << endl;
  cout << "Enter overall tree population: ";
  cin >> agentNo;
  cout << endl;
  cout << "Starting population = " << agentNo << endl;

  cout << "Would you like to enable graphics? y/n: ";
  cin >> set;

  if(set == 'y')
  {
    cout << endl << "Graphics have been enabled! " << endl;
    _SDL = true;
    cout << "Set world projection: " << endl;
    cout << "1 = Height " << endl << "2 = Slope " << endl << "3 = Slope " << endl << "Enter: ";
    cin >> _worldState;
  }
  if(set == 'n')
  {
    cout << endl << "Graphics have been disabled! " << endl;
    _SDL = false;
  }

  _isElm = 0;
  _isPine = 0;
  _isOak = 0;
  _isAlder = 0;
  _isHazel = 0;
  _isAsh = 0;
  _isLime = 0;
  _isBirch = 0;

  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
        treeHere[i][j] = 0;
    }
  }

  setupPatches();

  input = new Input();
  input->loadFile("Input/parameters.txt");
  input->closeFile();

  setConsts(input->getTicks(), input->getElmCount(), input->getPineCount(), input->getOakCount(), input->getAlderCount(),
            input->getHazelCount(), input->getAshCount(), input->getLimeCount(), input->getBirchCount(), input->getChange());

  agentNo = _elmNo + _pineNo + _oakNo + _alderNo + _hazelNo + _ashNo + _limeNo + _birchNo;

  cout << "Number of Trees = " << agentNo << endl;

  campNo = 1;
  agentNoSplit = 1;

  for(int i = 0; i < 8; i++)
  {
    species[i] = 0;

    if(_elmNo > 0 && i == 0)
    {
      species[i] = 1;
      _isElm = 1;
      cout << "Number of Elm = " << _elmNo << endl;
    }

    if(_pineNo > 0 && i == 1)
    {
      species[i] = 2;
      _isPine = 1;
      cout << "Number of Pine = " << _pineNo << endl;
    }

    if(_oakNo > 0 && i == 2)
    {
      species[i] = 3;
      _isOak = 1;
      cout << "Number of Oak = " << _oakNo << endl;
    }

    if(_alderNo > 0 && i == 3)
    {
      species[i] = 4;
      _isAlder = 1;
      cout << "Number of Alder = " << _alderNo << endl;
    }

    if(_hazelNo > 0 && i == 4)
    {
      species[i] = 5;
      _isHazel = 1;
      cout << "Number of Hazel = " << _hazelNo << endl;
    }

    if(_ashNo > 0 && i == 5)
    {
      species[i] = 6;
      _isAsh = 1;
      cout << "Number of Ash = " << _ashNo << endl;
    }

    if(_limeNo > 0 && i == 6)
    {
      species[i] = 7;
      _isLime = 1;
      cout << "Number of Lime = " << _limeNo << endl;
    }

    if(_birchNo > 0 && i == 7)
    {
      species[i] = 8;
      _isBirch = 1;
      cout << "Number of Birch = " << _birchNo << endl;
    }
  }

  cout << endl << "Is Elm = " << _isElm << endl;
  cout << "Is Pine = " << _isPine << endl;
  cout << "Is Oak = " << _isOak << endl;
  cout << "Is Alder = " << _isAlder << endl;
  cout << "Is Hazel = " << _isHazel << endl;
  cout << "Is Ash = " << _isAsh << endl;
  cout << "Is Lime = " << _isLime << endl;
  cout << "Is Birch = " << _isBirch << endl << endl;

  cout << endl << "Simulation class agents created " << endl;

  for(int i = 0; i < 8; i++)
  {
    cout << species[i] << " ";
  }
  cout << endl;

  delete input;
}

Simulation::~Simulation()
{
  cout << endl << "Simulation class destroyed! " << endl << endl;
}

void Simulation::initSimulation()
{
  int accNo = 0; // count of how many have been recruited so far, for id
  int start = 0;
  int end = 0;
  world = new World();
  world->loadHeight("Input/height.txt");
  world->loadSlope("Input/slope.txt");
  world->loadSoil("Input/soil.txt");

  output = new Output();
  environment = new Environment();
  //to be called during initial run to construct chunk directories
  //output->createDirectories();
  //create agents
  //agents = new Agent*[agentNo];
  chunks = new Chunk*[1];
  camps = new Camp*[campNo];

//  vector<Tree*> trees(agentNo/agentNoSplit);
  trees = vector<Tree*>(agentNo/agentNoSplit);

  if(_isElm)
  {
    for(int i=0; i<_elmNo; i++)
    {
      trees[i] = new Tree(i,0,0,1);
      trees[i]->randomDBH();
      trees[i]->setupAge();
      trees[i]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[i]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[i]->getX()][trees[i]->getY()] == true)
      {
        trees[i]->setCMortality();
      }
      else
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isPine)
  {
    for(int i=0; i<_pineNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,2);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isOak)
  {
    for(int i=0; i<_oakNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,3);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isAlder)
  {
    for(int i=0; i<_alderNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,4);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isHazel)
  {
    for(int i=0; i<_hazelNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,5);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isAsh)
  {
    for(int i=0; i<_ashNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,6);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isLime)
  {
    for(int i=0; i<_limeNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,7);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  if(_isBirch)
  {
    for(int i=0; i<_birchNo; i++)
    {
      int j = accNo;

      trees[j] = new Tree(j,0,0,8);
      trees[j]->randomDBH();
      trees[j]->setupAge();
      trees[j]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[j]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      if(treeHere[trees[j]->getX()][trees[j]->getY()] == true)
      {
        trees[j]->setCMortality();
      }
      else
      {
        treeHere[trees[j]->getX()][trees[j]->getY()] = 1;
      }

      accNo++;
    }
  }

  // create the array of chunks and ask each chunk to reference which trees are in their space
  for(int i = 0; i < 1; i++)
  {
    chunks[i] = new Chunk(i+1);
    chunks[i]->storeNeighbours();
  }

  for (int i = 0; i < campNo; i++)
  {
    camps[i] = new Camp(-1, 500, 500, 20,20);
  }

  recruitment = new Recruitment(100, species);

  if(_SDL)
  {
    display = new Display();

    display->initDisplay("Test Display",500,0,800,800,true);
  }

  cout << input->getChange();
  cout << endl << "Simulation class agents created " << endl;

  environment->loadDEGD("Input/DEGD2.txt", _change);
  environment->loadRain("Input/rain.txt");
  //create world
}

void Simulation::updateSimulation()
{
  //run tree commands
}

void Simulation::renderSimulation()
{
  int ctick = 0; // current iteration
  int resetDEGD = 0;
  char input;
  int newAgents = 100;
  int startID = agentNo;

  const string part1 = "Output/tick"; // you must create a folder called Output in src dirctory
  const string part2 = ".txt";

  const string part3 = "Output/patches"; // you must create a folder called Output in src dirctory
  const string part4 = ".txt";

  const string pop = "population.txt";
  output->openFile(pop);

  while (ctick <= (_ticks-1)) // change to a while running function that takes in the graphics on/off parameter
  {
    ctick++;
    resetDEGD++;

    if(ctick % 100 == 0)
    {
      resetDEGD = 1;
    }

    int vectorSize = trees.size();
    const string all = ((part1 + to_string(ctick))+ part2);
    const string all2 = ((part3 + to_string(ctick))+ part4);

    //output->openFile(all);
    //output->outPatches(treeHere, all2);

    if(_SDL)
    {
      display->clearRenderer();
      display->renderDisplay(_worldState);
    }

    //recruitment->speciesProbability(environment->_DEGD[resetDEGD-1], 100);
    recruitment->speciesProbability(environment->constantDEGD(ctick), 100);

    //stores vector of trees within chunks
    for(int i = 0; i < 1; i++)
    {
      chunks[i]->storeTrees(trees, ctick);
      //cout << "Trees stored in chunks! " << chunks[i]->getID() << endl;
    }

    cout << "Make it to pre-recruitment! " << endl;

    //// NEW RECUITS LOOP ////

    int newTrees = 0;

    if(_isElm)
    {
      for(int i = 0; i < recruitment->getNumElm(); i++)
      {
        //cout << "New Elm = " << recruitment->getNumElm() << endl;
        trees.push_back(new Tree(startID, 0,0,1));

        if(treeHere[trees[vectorSize]->getX()][trees[vectorSize]->getY()] == true)
        {
          trees[vectorSize]->setCMortality();
          trees.erase(trees.begin() + vectorSize);
          startID++;
        }
        else
        {
          treeHere[trees[vectorSize]->getX()][trees[vectorSize]->getY()] = 1;
          vectorSize++;
          startID++;
          newTrees++;
        }
      }
    }

    if(_isPine)
    {
      for(int i = 0; i < recruitment->getNumPine(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,2));
        //cout << "New pine = " << recruitment->getNumPine() << endl;

        if(treeHere[trees[vectorSize]->getX()][trees[vectorSize]->getY()] == true)
        {
          trees[vectorSize]->setCMortality();
          trees.erase(trees.begin() + vectorSize);
          startID++;
        }
        else
        {
          treeHere[trees[vectorSize]->getX()][trees[vectorSize]->getY()] = 1;
          vectorSize++;
          startID++;
          newTrees++;
        }
      }
    }

    if(_isOak)
    {
      for(int i = 0; i < recruitment->getNumOak(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,3));
        //cout << "New Oak = " << recruitment->getNumOak() << endl;

        if(treeHere[trees[vectorSize]->getX()][trees[vectorSize]->getY()] == true)
        {
          trees[vectorSize]->setCMortality();
          trees.erase(trees.begin() + vectorSize);
          startID++;
        }
        else
        {
          treeHere[trees[vectorSize]->getX()][trees[vectorSize]->getY()] = 1;
          vectorSize++;
          startID++;
          newTrees++;
        }
      }
    }

    if(_isAlder)
    {
      for(int i = 0; i < recruitment->getNumAlder(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,4));
        //cout << "New Alder = " << recruitment->getNumAlder() << endl;

        if(treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] == true)
        {
          trees[vectorSize-1]->setCMortality();
        }
        else
        {
          treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] = 1;
        }

        vectorSize++;
        startID++;
        newTrees++;
      }
    }

    if(_isHazel)
    {
      for(int i = 0; i < recruitment->getNumHazel(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,5));
        //cout << "New Hazel = " << recruitment->getNumHazel() << endl;

        if(treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] == true)
        {
          trees[vectorSize-1]->setCMortality();
        }
        else
        {
          treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] = 1;
        }

        vectorSize++;
        startID++;
        newTrees++;
      }
    }

    if(_isAsh)
    {
      for(int i = 0; i < recruitment->getNumAsh(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,6));
        //cout << "New Ash = " << recruitment->getNumAsh() << endl;

        if(treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] == true)
        {
          trees[vectorSize-1]->setCMortality();
        }
        else
        {
          treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] = 1;
        }

        vectorSize++;
        startID++;
        newTrees++;
      }
    }

    if(_isLime)
    {
      for(int i = 0; i < recruitment->getNumLime(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,7));
        //cout << "New Lime = " << recruitment->getNumLime() << endl;

        if(treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] == true)
        {
          trees[vectorSize-1]->setCMortality();
        }
        else
        {
          treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] = 1;
        }

        vectorSize++;
        startID++;
        newTrees++;
      }
    }

    if(_isBirch)
    {
      for(int i = 0; i < recruitment->getNumBirch(); i++)
      {
        trees.push_back(new Tree(startID, 0,0,8));
        //cout << "New Birch = " << recruitment->getNumBirch() << endl;

        if(treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] == true)
        {
          trees[vectorSize-1]->setCMortality();
        }
        else
        {
          treeHere[trees[vectorSize-1]->getX()][trees[vectorSize-1]->getY()] = 1;
        }

        vectorSize++;
        startID++;
        newTrees++;
      }
    }

    cout << "Recruited new Trees! " << newTrees << endl;

    cout << trees.size() << endl;

    //trees[1]->storePatches();

    for(int i=0; i<vectorSize; i++)
    {
      //cout << "DEGD " << environment->_DEGD[tick-1] << endl;
      trees[i]->setElevation(world->getElevation(trees[i]->getX(), trees[i]->getY()));
      trees[i]->setSlope(world->getSlope(trees[i]->getX(), trees[i]->getY()));
      trees[i]->resetPatches();
      trees[i]->getNeighbors(chunks[(trees[i]->getChunk()-1)]->chunkTrees);
      //trees[i]->setTEffect(environment->_DEGD[resetDEGD-1]);
      trees[i]->setTEffect(environment->constantDEGD(ctick));
      trees[i]->update(trees[i]->getDBH(), trees[i]->getTEffect(), trees[i]->getLEffect());
      trees[i]->storePatches();

      if(_SDL)
      {
        trees[i]->draw(display->renderer);
      }
    }

    for(int i = 0; i < 10000; i++)
    {
      patches[i]->clearTreeIDs();
      patches[i]->setTreeCover(trees);
      cout << "Patch " << patches[i]->getX() << " " << patches[i]->getY() << " tree cover = " << patches[i]->getHTree() << endl;
    }

    for(int i = 0; i < vectorSize; i++)
    {
      //cout << "Elements = " << trees[i]->_npatches.size() << endl;

      for(int j = 0; j < trees[i]->_npatches.size(); j++)
      {
        patches[trees[i]->_npatches[j]]->setTreeCoverTwo(i);
        //cout << trees[i]->_npatches[j] << " ";
      }
    }

    for(int i=0; i<vectorSize; i++)
    {
      for(int j = 0; j < trees[i]->_npatches.size(); j++)
      {

        if(trees[i]->getID() == patches[trees[i]->_npatches[j]]->getHTree())
        {
          trees[i]->setPDominace();
          cout << "Tree " << trees[i]->getID() << "is dominant tree on Patch " << trees[i]->_npatches[j] << endl;
        }

        //if(patches[trees[i]->_npatches[j]]->getX() >= trees[i]->getX() - trees[i]->getRadius() && patches[trees[i]->_npatches[j]]->getX() < trees[i]->getX() + trees[i]->getRadius()
          //&& patches[trees[i]->_npatches[j]]->getY() >= trees[i]->getY() - trees[i]->getRadius() && patches[trees[i]->_npatches[j]]->getY() < trees[i]->getY() + trees[i]->getRadius())
        //{
          trees[i]->setTCover();
          trees[i]->referencePatches(patches[trees[i]->_npatches[j]]->getNumCover());
          trees[i]->lightEffect();
        //}

      }
/*
      if(trees[i]->removeTree() == true || trees[i]->ageMortality() == true || (trees[i]->getMyPatches() == 0 && trees[i]->getPDominance() == false))
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = 0;
        trees.erase(trees.begin() + i);
        vectorSize--;
        i--;
      }
*/
      //trees[i]->isAlive(trees[i]->getAlive());
    }

    for(int i=0; i<vectorSize; i++)
    {
      if(trees[i]->removeTree() == true || trees[i]->ageMortality() == true) // || trees[i]->getPDominance() == false) //(trees[i]->getMyPatches() == 0)) // && trees[i]->getPDominance() == false))
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = 0;
        trees.erase(trees.begin() + i);
        vectorSize--;
        i--;
      }
      else if (trees[i]->getPDominance() == false && trees[i]->getMyPatches() == 0)
      {
        treeHere[trees[i]->getX()][trees[i]->getY()] = 0;
        trees.erase(trees.begin() + i);
        vectorSize--;
        i--;
      }
    }

    cout << "Processed update functions! " << endl;

    for (int i = 0; i < campNo; i++)
    {
      //camps[i]->drawCamp(Display::renderer);
    }

    for(int i=0; i<vectorSize; i++)
    {
      //output->blenderOutput(trees[i]->getID(),trees[i]->getSpecies(),trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),trees[i]->getRadius(), trees[i]->getElevation());
      //output->runOutput(trees[i]->getID(),trees[i]->getSpecies(),trees[i]->getAge(),trees[i]->getX(),trees[i]->getY(),trees[i]->getDBH(),trees[i]->getHeight(),
        //trees[i]->getRadius(),trees[i]->getBiomass(),trees[i]->getChunk(), trees[i]->getDominance(), trees[i]->getElevation());
    }

    int recruit = agentNo+((newAgents*ctick)-agentNo); // for id's

    // call function from recruitment for size of newAgents array
    // call function from recruitment for how many of each species to recruit

    cout << "Trees = " << vectorSize << endl;
    cout << "Next ID = " << startID << endl;

    if(_SDL)
    {
      display->updateDisplay();
      display->renderPresent();
    }

    cout << "Tick = " << ctick << endl;

    for(int i = 0; i < 1; i++)
    {
      chunks[i]->chunkTrees.clear();
    }

    cout << "<---------------------------------------->" << endl << endl;

    if(_SDL)
    {
      display->handleEvents();
    }

    int elmSum = 0;
    int pineSum = 0;
    int oakSum = 0;
    int alderSum = 0;
    int hazelSum = 0;
    int ashSum = 0;
    int limeSum = 0;
    int birchSum = 0;

    float elmAge = 0;
    float pineAge = 0;
    float oakAge = 0;
    float alderAge = 0;
    float hazelAge = 0;
    float ashAge = 0;
    float limeAge = 0;
    float birchAge = 0;

    for(int i = 0; i < trees.size(); i++)
    {
      if(trees[i]->getSpecies() == 1)
      {
        elmSum++;
        elmAge = elmAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 2)
      {
        pineSum++;
        pineAge = pineAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 3)
      {
        oakSum++;
        oakAge = oakAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 4)
      {
        alderSum++;
        alderAge = alderAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 5)
      {
        hazelSum++;
        hazelAge = hazelAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 6)
      {
        ashSum++;
        ashAge = ashAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 7)
      {
        limeSum++;
        limeAge = limeAge + trees[i]->getAge();
      }
      if(trees[i]->getSpecies() == 8)
      {
        birchSum++;
        birchAge = birchAge + trees[i]->getAge();
      }
    }

    elmAge = ((elmAge / elmSum) * 100) / 400;
    pineAge = ((pineAge / pineSum) * 100) / 450;
    oakAge = ((oakAge / oakSum) * 100) / 500;
    alderAge = ((alderAge / alderSum) * 100) / 300;
    hazelAge = ((hazelAge / hazelSum) * 100) / 60;
    ashAge = ((ashAge / ashSum) * 100) / 250;
    limeAge = ((limeAge / limeSum) * 100) / 400;
    birchAge = ((birchAge / birchSum) * 100) / 120;

    //output->closeFile();
    output->populations(ctick, elmSum, elmAge, pineSum, pineAge, oakSum, oakAge, alderSum, alderAge, hazelSum, hazelAge, ashSum, ashAge, limeSum, limeAge, birchSum, birchAge);
  }
  output->closeFile();
}

void Simulation::cleanSimulation()
{
  outputCounts();

  if(_SDL)
  {
    display->cleanDisplay();
  }

  for(int i = 0; i < 1; i++)
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

  for(int i = 0; i < 10000; i++)
  {
    delete patches[i];
  }

  if(_SDL)
  {
    delete display;
  }

  delete world;
  delete treeFunctions;
  delete output;
}

void Simulation::setConsts(int ticks, float elmNo, float pineNo, float oakNo, float alderNo, float hazelNo, float ashNo, float limeNo, float birchNo, float change)
{
  _ticks = ticks;

  if(elmNo > 0)
  {
    _elmNo = (int)((elmNo * agentNo) / 100);
  } else {
    _elmNo = 0;
  }

  if(pineNo > 0)
  {
    _pineNo = (int)((pineNo * agentNo) / 100);
  } else {
    _pineNo = 0;
  }

  if(oakNo > 0)
  {
    _oakNo = (int)((oakNo * agentNo) / 100);
  } else {
    _oakNo = 0;
  }

  if(alderNo > 0)
  {
    _alderNo = (int)((alderNo * agentNo) / 100);
  } else {
    _alderNo = 0;
  }

  if(hazelNo > 0)
  {
    _hazelNo = (int)((hazelNo * agentNo) / 100);
  } else {
    _hazelNo = 0;
  }

  if(ashNo > 0)
  {
    _ashNo = (int)((ashNo * agentNo) / 100);
  } else {
    _ashNo = 0;
  }

  if(limeNo > 0)
  {
    _limeNo = (int)((limeNo * agentNo) / 100);
  } else {
    _limeNo = 0;
  }

  if(birchNo > 0)
  {
    _birchNo = (int)((birchNo * agentNo) / 100);
  } else {
    _birchNo = 0;
  }

  _change = change;
}

void Simulation::setupPatches()
{
  patches = new Patch*[10000];

  for(int i = 0; i < 100; i++)
  {
    for(int j = 0; j < 100; j++)
    {
      int patchNo = (100 * i) + j;
      patches[patchNo] = new Patch();
      patches[patchNo]->setID(patchNo);
      patches[patchNo]->setX(i);
      patches[patchNo]->setY(j);
    }
  }
}

void Simulation::outputCounts()
{
  int elmSum = 0;
  int pineSum = 0;
  int oakSum = 0;
  int alderSum = 0;
  int hazelSum = 0;
  int ashSum = 0;
  int limeSum = 0;
  int birchSum = 0;

  for(int i = 0; i < trees.size(); i++)
  {
    if(trees[i]->getSpecies() == 1)
    {
      elmSum++;
    }
    if(trees[i]->getSpecies() == 2)
    {
      pineSum++;
    }
    if(trees[i]->getSpecies() == 3)
    {
      oakSum++;
    }
    if(trees[i]->getSpecies() == 4)
    {
      alderSum++;
    }
    if(trees[i]->getSpecies() == 5)
    {
      hazelSum++;
    }
    if(trees[i]->getSpecies() == 6)
    {
      ashSum++;
    }
    if(trees[i]->getSpecies() == 7)
    {
      limeSum++;
    }
    if(trees[i]->getSpecies() == 8)
    {
      birchSum++;
    }
  }

  cout << "Elm population = " << elmSum << endl;
  cout << "Pine population = " << pineSum << endl;
  cout << "Oak population = " << oakSum << endl;
  cout << "Alder population = " << alderSum << endl;
  cout << "Hazel population = " << hazelSum << endl;
  cout << "Ash population = " << ashSum << endl;
  cout << "Lime population = " << limeSum << endl;
  cout << "Birch population = " << birchSum << endl;
}
