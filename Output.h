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
  void runOutput(int agentID, string species, int x, int y, float DBH, float height, float radius, int chunk);
  void blenderOutput(int agentID, string species, int x, int y,float DBH, float height, float radius);
  void chunkOutput(int agentID, int x, int y, int chunk);
  void closeFile();

  void displayOutput();

  ofstream file;
private:

};

#endif
