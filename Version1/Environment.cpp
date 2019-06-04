#include "Environment.h"

Environment::Environment()
{

}

Environment::~Environment()
{

}

void Environment::loadDEGD(string filename)
{

  int a;
  float b;
  float change = 500;
  //cout << "Change DEGD by a value of? " << endl;
  //cin >> change;

  ifstream file;
  file.open(filename);
  cout << "Soething loaded" << endl;


  while(file >> a >> b)
  {
    _year.push_back(a);
    _DEGD.push_back(b+change);
    cout << "DEGD loaded " << endl;

  }

  for(int i = 0;i < _year.size(); i++)
  {
    //cout << "Year = " << _year[i] << endl;

  }

  file.close();
}

void Environment::readDEGD(string file)
{

}

void Environment::closeFile(string filename)
{


}
