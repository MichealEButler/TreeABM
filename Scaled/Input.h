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
  float getElmCount();
  float getPineCount();
  float getOakCount();
  float getAlderCount();
  float getHazelCount();
  float getAshCount();
  float getLimeCount();
  float getBirchCount();

private:
  ifstream file;
  int _ticks;
  float _elmNo;
  float _pineNo;
  float _oakNo;
  float _alderNo;
  float _hazelNo;
  float _ashNo;
  float _limeNo;
  float _birchNo;
};

#endif
