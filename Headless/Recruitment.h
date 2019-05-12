#ifndef RECRUITMENT_H
#define RECRUITMENT_H

#include <iostream>

using namespace std;

class Recruitment
{
public:
  Recruitment();
  Recruitment(int numRecruits, int species[8]);
  void speciesProbability(float DEGD, int recuits);
  ~Recruitment();

  void setNumRecruits();
  int getNumRecruits();

  int getNumElm();
  int getNumPine();
  int getNumOak();

  float overall;

private:
  int _numRecruits;
  int _acRecruits;
  int _species[8]; // value of one to 8 depending on how many species represented
  float _proportion;

  float _elmProb;
  float _pineProb;
  float _oakProb;
  float _alderProb;
  float _hazelProb;
  float _ashProb;
  float _limeProb;
  float _birchProb;
};

#endif
