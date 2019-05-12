#ifndef CHUNKS_H
#define CHUNKS_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "World.h"
#include "Tree.h"
#include "Output.h"

using namespace std;

class Chunk
{
public:
  Chunk();
  Chunk(int id);
  ~Chunk();

  void setX1(int x1);
  void setX2(int x2);
  void setY1(int y1);
  void setY2(int y2);

  int getID();
  int getX1();
  int getX2();
  int getY1();
  int getY2();

  //vector <Tree*> getTrees();

  vector <Tree*> chunkTrees;

  void storeTrees(vector <Tree*> trees, int tick);
  void deleteTrees();
  void renderChunk();
  void storeNeighbours();
  void outNeighbours();

private:
  int _id;
  int _x1;
  int _x2;
  int _y1;
  int _y2;

  Output * output;
  int nChunks[8]; // array holding ID's of neighbouring chunks

};

#endif
