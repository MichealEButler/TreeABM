#include "Chunk.h"

Chunk::Chunk()
{

}

Chunk::Chunk(int id)
{
  _id = id;
  cout << "Chunk with ID = " << id << " created!" << endl;
}

Chunk::~Chunk()
{

}

void Chunk::setX1(int x1)
{
  _x1 = x1;
}

void Chunk::setX2(int x2)
{
  _x2 = x2;
}

void Chunk::setY1(int y1)
{
  _y1 = y1;
}

void Chunk::setY2(int y2)
{
  _y2 = y2;
}

int Chunk::getID()
{
  return _id;
}

int Chunk::getX1()
{
  return _x1;
}

int Chunk::getX2()
{
  return _x2;
}

int Chunk::getY1()
{
  return _y1;
}

int Chunk::getY2()
{
  return _y2;
}

void Chunk::loadChunk(int x1, int x2, int y1, int y2, SDL_Renderer* renderer)
{
  _x1 = x1;
  _x2 = x2;
  _y1 = y1;
  _y2 = y2;

  for (int i = x1; i < x2; i++)
  {
    for (int j = y1; j < y2; j++)
    {
      if(i >= x1 && i < x2 && j == y1)
      {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if(i == x1 && j >= y1 && j < y2)
      {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if(i == x2 - 1 && j >= y1 && j < y2)
      {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if(j == y2 - 1 && i >= x1 && i < x2)
      {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
    }
  }
}

void Chunk::storeTrees(vector <Tree*> trees, int tick)
{
  //output = new Output();
  const string part1 = "Output/Chunks/Chunk";
  const string part2 = "/tick";
  const string part3 = ".txt";

  const string all = (part1 + to_string(getID()) + part2 + to_string(tick) + part3);
  //output->openFile(all);
  //takes in the vector of trees from the simulation class
  //iterates through the chunk variable of all the trees
  // if chunk is equal to the id, store this tree in a vector here
  for(int i= 0; i < trees.size(); i++)
  {
    if(trees[i]->getChunk() == getID())
    {
      chunkTrees.push_back(trees[i]);
      //output->chunkOutput(trees[i]->getID(), trees[i]->getSpecies(), trees[i]->getX(), trees[i]->getY(), trees[i]->getChunk(), trees[i]->getDBH(), trees[i]->getHeight(), trees[i]->getRadius(), trees[i]->getElevation());
    }
  }
  //output->closeFile();
}
/*
vector <Tree*> Chunk::getTrees()
{
  return chunkTrees;
}
*/
void Chunk::deleteTrees()
{
  for(int i = 0; i < chunkTrees.size(); i++)
  {
    delete chunkTrees[i];
  }
}

void Chunk::renderChunk()
{

}

void Chunk::storeNeighbours()
{
  // get id of 8 neighbouring Chunks
  int origin = getID();
  int N, S, E, W, NE, NW, SE, SW;

  if((origin - 1) % 10 == 0)
  {
    N = -1;
    NE = -1;
    NW = -1;
  } else {
    N = origin - 1;
    NE = N + 10;
    NW = N - 10;
  }

  if(origin % 10 == 0)
  {
    S = -1;
    SE = -1;
    SW = -1;
  } else {
    S = origin + 1;
    SE = S + 10;
    SW = S - 10;
  }

  E = origin + 10;
  W = origin - 10;

  if(origin == 1)
  {
    SW = -1;
    W = -1;
    N = -1;
    NE = -1;
    NW = -1;
  }

  if(origin == 91)
  {
    SE = -1;
    E = -1;
    N = -1;
    NE = -1;
    NW = -1;
  }

  if(origin == 100)
  {
    NE = -1;
    E = -1;
    S = -1;
    SE = -1;
    SW = -1;
  }

  if(origin == 10)
  {
    NW = -1;
    W = -1;
    S = -1;
    SE = -1;
    SW = -1;
  }

  nChunks[0] = N;
  nChunks[1] = S;
  nChunks[2] = E;
  nChunks[3] = W;
  nChunks[4] = NE;
  nChunks[5] = NW;
  nChunks[6] = SE;
  nChunks[7] = SW;
}

void Chunk::outNeighbours()
{
  for(int i = 0; i < 8; i++)
  {
    cout << nChunks[i] << " ";
  }
  cout << endl;
}
