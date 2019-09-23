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
  void loadPlotFile(string inFile, int nplot); // function for loading in contemporary site data
  int readSpecies(string name);
  void readVectors();
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
  float getHornCount();
  float getLarchCount();
  float getBeechCount();
  float getWillowCount();
  float getMapleCount();
  float getPFTCount();
  float getChange();

  vector <int> getElmInit(); // functions which return stored initialisation data for contemporary datasets
  vector <int> getPineInit();
  vector <int> getOakInit();
  vector <int> getAlderInit();
  vector <int> getHazelInit();
  vector <int> getAshInit();
  vector <int> getLimeInit();
  vector <int> getBirchInit();
  vector <int> getHornInit();
  vector <int> getLarchInit();
  vector <int> getBeechInit();
  vector <int> getWillowInit();
  vector <int> getMapleInit();
  vector <int> getPFTInit();

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
  float _hornNo;
  float _larchNo;
  float _beechNo;
  float _willowNo;
  float _mapleNo;
  float _pftNo;
  float _change;

  vector<int> _elmCount; //1d list of dbh classes per each tree to be initialised
  vector<int> _pineCount;
  vector<int> _oakCount;
  vector<int> _alderCount;
  vector<int> _hazelCount;
  vector<int> _ashCount;
  vector<int> _limeCount;
  vector<int> _birchCount;
  vector<int> _hornCount;
  vector<int> _larchCount;
  vector<int> _beechCount;
  vector<int> _willowCount;
  vector<int> _mapleCount;
  vector<int> _pftCount;

  vector<int> _elmCountTwo;
  vector<int> _pineCountTwo;
  vector<int> _oakCountTwo;
  vector<int> _alderCountTwo;
  vector<int> _hazelCountTwo;
  vector<int> _ashCountTwo;
  vector<int> _limeCountTwo;
  vector<int> _birchCountTwo;
  vector<int> _hornCountTwo;
  vector<int> _larchCountTwo;
  vector<int> _beechCountTwo;
  vector<int> _willowCountTwo;
  vector<int> _mapleCountTwo;
  vector<int> _pftCountTwo;

};

#endif
