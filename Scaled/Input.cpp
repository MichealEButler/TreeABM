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
  int value;

  file.open(filename);

  for(int i = 0; i < 9; i++)
  {
    file >> one >> two >> value;
    switch(i)
    {
      case 0:
        _ticks = value;
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

int Input::getElmCount()
{
  return _elmNo;
}

int Input::getPineCount()
{
  return _pineNo;
}

int Input::getOakCount()
{
  return _oakNo;
}

int Input::getAlderCount()
{
  return _alderNo;
}

int Input::getHazelCount()
{
  return _hazelNo;
}

int Input::getAshCount()
{
  return _ashNo;
}

int Input::getLimeCount()
{
  return _limeNo;
}

int Input::getBirchCount()
{
  return _birchNo;
}
