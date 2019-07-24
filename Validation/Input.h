#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Input
{
public:
  Input();
  ~Input();

  void loadFile(string filename);
  void loadPlotFile(string inFile); // function for loading in contemporary site data
  int readSpecies(string name);
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
  float getChange();

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
  float _change;

  vector<int> _elmCount; //1d list of dbh classes per each tree to be initialised
  vector<int> _pineCount;
  vector<int> _oakCount;
  vector<int> _alderCount;
  vector<int> _hazelCount;
  vector<int> _ashCount;
  vector<int> _limeCount;
  vector<int> _birchCount;

  vector<int> _elmCountTwo;
  vector<int> _pineCountTwo;
  vector<int> _oakCountTwo;
  vector<int> _alderCountTwo;
  vector<int> _hazelCountTwo;
  vector<int> _ashCountTwo;
  vector<int> _limeCountTwo;
  vector<int> _birchCountTwo;

};

#endif
