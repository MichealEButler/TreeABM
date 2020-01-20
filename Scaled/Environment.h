#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Environment
{
public:
  Environment();
  ~Environment();
  void loadDEGD(string filename, float change); // contemporary dataset
  void loadRain(string filename); // contemporary dataset
  void palaeoDEGD(string filename, int res); // palaeo dataset for entire holocene
  void palaeoRain(string filename); // palaeo dataset for entire holocene
  void closeFile(string filename);
  void readDEGD(string filename);

  float constantDEGD(int tick);

  vector<int> _year;
  vector<int> _pYear;
  vector<float> _DEGD;
  vector<float> _rain;
  vector<float> _pDEGD; // palaeo DEGD
  vector<float> _pRain; // palaeo rain

private:

};

#endif
