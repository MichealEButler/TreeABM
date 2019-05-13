#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Input
{
public:
  Input();
  ~Input();

  void loadFile(string filename);
  void readConsts();
  void closeFile();

  int getTicks();
  int getElmCount();
  int getPineCount();
  int getOakCount();
  int getAlderCount();
  int getHazelCount();
  int getAshCount();
  int getLimeCount();
  int getBirchCount();

private:
  ifstream file;
  int _ticks;
  int _elmNo;
  int _pineNo;
  int _oakNo;
  int _alderNo;
  int _hazelNo;
  int _ashNo;
  int _limeNo;
  int _birchNo;
};

#endif
