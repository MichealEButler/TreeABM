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
  void loadDEGD(string filename, float change);
  void loadRain(string filename);
  void closeFile(string filename);
  void readDEGD(string filename);

  float constantDEGD();

  vector<int> _year;
  vector<float> _DEGD;
  vector<float> _rain;

private:

};

#endif
