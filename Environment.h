#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Environment
{
public:
  Environment();
  ~Environment();
  void loadDEGD(string filename);
  void closeFile(string filename);
  void readDEGD(string filename);

private:

};

#endif
