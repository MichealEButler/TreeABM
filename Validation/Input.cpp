#include "Input.h"

Input::Input()
{

}

Input::~Input()
{

}

void Input::loadFile(string filename)
{
  string one;
  string two;
  float value;

  file.open(filename);

  while(file >> one >> two >> three)
  {
    
  }

  for(int i = 0; i < 10; i++)
  {
    file >> one >> two >> value;
    switch(i)
    {
      case 0:
        _species = (int)value; // value between 1 and 8 for species
        break;
      case 1:
        _elmNo = value;
        break;
      case 2:
        _pineNo = value;
        break;
      case 3:
        _oakNo = value;
        break;
      case 4:
        _alderNo = value;
        break;
      case 5:
        _hazelNo = value;
        break;
      case 6:
        _ashNo = value;
        break;
      case 7:
        _limeNo = value;
        break;
      case 8:
        _birchNo = value;
        break;
      case 9:
        _change = value;
        break;
      default:
        break;
    }
  }
}

void Input::readConsts()
{

}

void Input::closeFile()
{
  file.close();
}

int Input::getTicks()
{
  return _ticks;
}

float Input::getElmCount()
{
  return _elmNo;
}

float Input::getPineCount()
{
  return _pineNo;
}

float Input::getOakCount()
{
  return _oakNo;
}

float Input::getAlderCount()
{
  return _alderNo;
}

float Input::getHazelCount()
{
  return _hazelNo;
}

float Input::getAshCount()
{
  return _ashNo;
}

float Input::getLimeCount()
{
  return _limeNo;
}

float Input::getBirchCount()
{
  return _birchNo;
}

float Input::getChange()
{
  return _change;
}
