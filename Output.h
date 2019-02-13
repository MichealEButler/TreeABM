#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Output
{
public:
  Output();
  ~Output();
  void openFile(string title);
  void runOutput(const char* agentID, const char* species, int x, int y, float DBH, float height, float radius);
  void closeFile();

  void displayOutput();

  ofstream file;
private:

};

#endif
