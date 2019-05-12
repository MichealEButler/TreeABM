#include "Recruitment.h"

Recruitment::Recruitment()
{
  _elmProb = 0;
  _pineProb = 0;
  _oakProb = 0;
  _alderProb = 0;
  _hazelProb = 0;
  _ashProb = 0;
  _limeProb = 0;
  _birchProb = 0;
}

Recruitment::Recruitment(int numRecruits, int species[8])
{
  _numRecruits = numRecruits;
  int * array;
  array = species;

  for (int i = 0; i < 8; i++)
  {
    _species[i] = array[i];
  }
}

Recruitment::~Recruitment()
{

}

void Recruitment::speciesProbability(float DEGD, int recruits)
{
  //first identify how many species are present
  int numSpecies = 8; //counts number of species for determining probabilty

  for(int i = 0; i < 8; i++)
  {
    switch(_species[i])
    {
      case 0 :
        numSpecies--;
        break;
      case 1 :
        _elmProb = (4 * ((4890 - DEGD) * (DEGD - 830))) / ((4890 - 830) * (4890 - 830));
        if(_elmProb < 0)
        {
          _elmProb = 0.01;
        }
        break;
      case 2 :
        _pineProb = (4 * ((2350 - DEGD) * (DEGD - 450))) / ((2350 - 450) * (2350 - 450));
        if(_pineProb < 0)
        {
          _pineProb = 0.01;
        }
        break;
      case 3 :
        _oakProb = (4 * ((4330 - DEGD) * (DEGD - 810))) / ((4330 - 810) * (4330 - 810));
        if(_oakProb < 0)
        {
          _oakProb = 0.01;
        }
        break;
      case 4 :
        _alderProb = (4 * ((4890 - DEGD) * (DEGD - 1100))) / ((4890 - 1100) * (4890 - 1100));
        break;
      case 5 :
        _hazelProb = (4 * ((4300 - DEGD) * (DEGD - 410))) / ((4300 - 410) * (4300 - 410));
        break;
      case 6 :
        _ashProb = (4 * ((4170 - DEGD) * (DEGD - 750))) / ((4170 - 750) * (4170 - 750));
        break;
      case 7 :
        _limeProb = (4 * ((4170 - DEGD) * (DEGD - 1100))) / ((4170 - 1100) * (4170 - 1100));
        break;
      case 8 :
        _birchProb = (4 * ((2300 - DEGD) * (DEGD - 410))) / ((2300 - 410) * (2300 - 410));
        break;
    }
  }

  float percent = 1 / (float)numSpecies;
/*
  cout << "Percent Elm recruit = " << _elmProb << endl;
  cout << "Percent Pine recruit = " << _pineProb << endl;
  cout << "Percent Oak recruit = " << _oakProb << endl << endl;

  cout << "Reduced percent Elm recruit = " << _elmProb * percent << endl;
  cout << "Reduced percent Pine recruit = " << _pineProb * percent << endl;
  cout << "Reduced percent Oak recruit = " << _oakProb * percent << endl << endl;

  cout << "Number of species present = " << numSpecies << endl;
  cout << "Percentage = " << percent << endl;
*/
  _elmProb = _elmProb * percent;
  _pineProb = _pineProb * percent;
  _oakProb = _oakProb * percent;

  overall = _elmProb + _pineProb + _oakProb;

  float newRecruits = (float)recruits * overall;
  _acRecruits = (int)newRecruits;

  //cout << "New Recruits = " << _acRecruits << endl;
}

int Recruitment::getNumRecruits()
{
  return _acRecruits;
}

int Recruitment::getNumElm()
{
  float numElm = (float)_acRecruits * _elmProb;

  return (int)numElm;
}

int Recruitment::getNumPine()
{
  float numPine = (float)_acRecruits *_pineProb;

  return (int)numPine;
}

int Recruitment::getNumOak()
{
  float numOak = (float)_acRecruits * _oakProb;

  return (int)numOak;
}
