#include "Pollen.h"

Pollen::Pollen()
{

}

Pollen::~Pollen()
{

}

void Pollen::pollenIn(string filename)
{
  string one;
  string two;
  float value;

  file.open(filename);

  for(int i = 0; i < 11; i++)
  {
    file >> one >> two >> value;
    switch(i)
    {
      case 0:
        _year = value;
        break;
      case 1:
        _x = value;
        break;
      case 2:
        _y = value;
        break;
      case 3:
        _elmNo = value;
        break;
      case 4:
        _pineNo = value;
        break;
      case 5:
        _oakNo = value;
        break;
      case 6:
        _alderNo = value;
        break;
      case 7:
        _hazelNo = value;
        break;
      case 8:
        _ashNo = value;
        break;
      case 9:
        _limeNo = value;
        break;
      case 10:
        _birchNo = value;
        break;
      default:
        break;
    }
  }
}

void Pollen::defConsts()
{
  // Oak as reference taken from Sugita 1999(a) and Bunting 2005(b)
  _elmPPE = 0.17; // a
  _pinePPE = 0.75; // a
  _oakPPE = 1.0;
  _alderPPE = 1.39; // b
  _hazelPPE = 0.19; // a
  _ashPPE = 0.15; // b
  _limePPE = 0.11; // a
  _birchPPE = 1.29; // b

  // fall speeds taken from Matthias 2012(a) and Sugita et al 1999(b)
  _elmFS = 0.032; // b
  _pineFS = 0.031; // a
  _oakFS = 0.035; // a
  _alderFS = 0.021; // a
  _hazelFS = 0.025; // b
  _ashFS = 0.022; // a
  _limeFS = 0.032; // a
  _birchFS = 0.022; // a
}

void Pollen::lContruct()
{
  // simple equation going to use the grid class
}

void Pollen::storeCatchment(int source, int height[100][100])
{

}
