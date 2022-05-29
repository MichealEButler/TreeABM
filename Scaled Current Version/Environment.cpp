#include "Environment.h"

Environment::Environment()
{

}

Environment::~Environment()
{

}

void Environment::loadDEGD(string filename, float change)
{

  int a;
  float b;

  cout << "Change DEGD = " << change << endl;
  //cin >> change;

  ifstream file;
  file.open(filename);

  while(file >> a >> b)
  {
    _year.push_back(a);
    _DEGD.push_back(b+change);
  }

  for(int i = 0;i < _year.size(); i++)
  {
    //cout << "Year = " << _year[i] << endl;
  }

  file.close();
}

void Environment::loadRain(string filename)
{
  int a;
  float b;

  ifstream file;
  file.open(filename);

  while(file >> a >> b)
  {
    _rain.push_back(b);
  }

  file.close();
}

void Environment::palaeoDEGD(string filename, int res)
{
  int a;
  float b;

  ifstream file;
  file.open(filename);

  while(file >> a >> b)
  {
    for(int i = 0; i < res; i++)
    {
      _pYear.push_back(a);
      _DEGD.push_back(b);
    }
  }

  for(int i = 0;i < _pYear.size(); i++)
  {
    //cout << "Year = " << _year[i] << endl;
  }

  file.close();
}

void Environment::palaeoRain(string filename)
{
  int a;
  float b;

  ifstream file;
  file.open(filename);

  while(file >> a >> b)
  {
    _pRain.push_back(b);
  }

  file.close();
}

void Environment::readDEGD(string file)
{

}

void Environment::closeFile(string filename)
{


}

float Environment::constantDEGD(int tick)
{

  return 1200;
/*  if(tick < 200)
  {
    return 2000;
  }
  if(tick >= 200 && tick < 400)
  {
    return 1950;
  }
  if(tick >= 400 && tick < 600)
  {
    return 1900;
  }
  if(tick >= 600 && tick < 800)
  {
    return 1800;
  }
  if(tick >= 800 && tick < 1000)
  {
    return 1750;
  }
  if(tick >= 1000 && tick < 1200)
  {
    return 1700;
  }
  if(tick >= 1200 && tick < 1400)
  {
    return 1650;
  }
  if(tick >= 1400 && tick < 1600)
  {
    return 1600;
  }
  if(tick >= 1600 && tick < 1800)
  {
    return 1550;
  }
  if(tick >= 1800 && tick <= 2000)
  {
    return 1500;
  }
  */
}
