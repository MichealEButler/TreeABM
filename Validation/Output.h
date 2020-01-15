#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cstring>

using namespace std;

class Output
{
public:
  Output();
  ~Output();
  void openFile(string title);
  void createDirectories();
  void outPatches(int array[14][14], string filename);
  void populations(int year, int elmNo, int pineNo, int oakNo, int alderNo, int hazelNo, int ashNo, int limeNo, int birchNo, int hornNo, int larchNo, int beechNo, int willowNo, int mapleNo, int pftNo);
  void runOutput(int agentID, int species, int age, int x, int y, float DBH, float height, float radius);
  void blenderOutput(int agentID, int species, int x, int y,float DBH, float height, float radius, float elevation);
  void chunkOutput(int agentID, int species, int x, int y, int chunk, float DBH, float height, float radius, float elevation);
  void closeFile();

  void displayOutput();

  ofstream file;
  ofstream f;
private:

};

#endif
