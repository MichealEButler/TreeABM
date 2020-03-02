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
  void outPatches(int array[100][100], string filename);
  void populations(int &year, int &elmNo, float &elmAge, int &pineNo, float &pineAge, int &oakNo, float &oakAge, int &alderNo, float &alderAge, int &hazelNo, float &hazelAge,
    int &ashNo, float &ashAge, int &limeNo, float &limeAge, int &birchNo, float &birchAge, int &openPatches, float &biomass, float &diameter);
  void runOutput(int agentID, int species, int age, int x, int y, float DBH, float height, float radius, float biomass, int chunk, bool dominant, float elevation);
  void openessOutput(int year, int openPatches);
  void blenderOutput(int agentID, int species, int x, int y,float DBH, float height, float radius, float elevation);
  void chunkOutput(int agentID, int species, int x, int y, int chunk, float DBH, float height, float radius, float elevation);
  void closeFile();

  void displayOutput();

  ofstream file;
  ofstream f;
private:

};

#endif
