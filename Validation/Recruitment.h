#ifndef RECRUITMENT_H
#define RECRUITMENT_H

#include <iostream>

using namespace std;

class Recruitment
{
public:
  Recruitment();
  Recruitment(int numRecruits, int species[14]);
  void speciesProbability(float DEGD, int recuits);
  ~Recruitment();

  void setNumRecruits();
  int getNumRecruits();

  int getNumElm(float elmPercent);
  int getNumPine(float pinePercent);
  int getNumOak(float oakPercent);
  int getNumAlder(float alderPercent);
  int getNumHazel(float hazelPercent);
  int getNumAsh(float ashPercent);
  int getNumLime(float limePercent);
  int getNumBirch(float birchPercent);
  int getNumHorn(float hornPercent);
  int getNumLarch(float larchPercent);
  int getNumBeech(float beechPercent);
  int getNumWillow(float willowPercent);
  int getNumMaple(float maplePercent);
  int getNumPFT(float pftPercent);

  float overall;

private:
  int _numRecruits;
  int _acRecruits;
  int _species[14]; // value of one to 8 depending on how many species represented
  float _proportion;

  float _elmProb;
  float _pineProb;
  float _oakProb;
  float _alderProb;
  float _hazelProb;
  float _ashProb;
  float _limeProb;
  float _birchProb;
  float _hornProb;
  float _larchProb;
  float _beechProb;
  float _willowProb;
  float _mapleProb;
  float _pftProb;
};

#endif
