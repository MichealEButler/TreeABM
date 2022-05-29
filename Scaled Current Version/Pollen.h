#ifndef POLLEN_H
#define POLLEN_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Grid.h"

using namespace std;

// a Pollen class is generated for each source area

class Pollen
{
public:
  //needs to use input arrays to determine catchment area of Pollen
  //source areas need defining
  //needs to take in pollen data, with reference years

  Pollen();
  ~Pollen();
  void pollenIn(string filename); // input counts for pollen
  void defConsts(); // defines the PPE's, and fall rates of each species within the simulation space
  void lContruct(); // reconstruct landscape from input alloating to the patches
  void storeCatchment(int source, int height[100][100]); // calculates catchments and stores in catchment array

private:
  //array for species allocated to each patch
  //array for catchment, is a 100 x 100 array defining catchment as 1 and 0 as not in cathcment
  // need a function that will easily display this
  ifstream file;

  int _composition[100][100]; // ares outside of catchment are given a zero (1-8) for repsented species
  int _catchment[100][100];
  int _sourcePatch;
  float _year;
  float _x;
  float _y;
  float _elmNo;
  float _pineNo;
  float _oakNo;
  float _alderNo;
  float _hazelNo;
  float _ashNo;
  float _limeNo;
  float _birchNo;

  // pollen production estimates in relation to oak
  float _elmPPE;
  float _pinePPE;
  float _oakPPE;
  float _alderPPE;
  float _hazelPPE;
  float _ashPPE;
  float _limePPE;
  float _birchPPE;

  // pollen fall speed m/s
  float _elmFS;
  float _pineFS;
  float _oakFS;
  float _alderFS;
  float _hazelFS;
  float _ashFS;
  float _limeFS;
  float _birchFS;


  Grid * pGrid; // stores final landscape state

};

#endif
