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
  _hornProb = 0;
  _larchProb = 0;
  _beechProb = 0;
  _willowProb = 0;
  _mapleProb = 0;
  _pftProb = 0;
}

Recruitment::Recruitment(int numRecruits, int species[14])
{
  _numRecruits = numRecruits;
  int * array;
  array = species;

  for (int i = 0; i < 14; i++)
  {
    _species[i] = array[i];
  }
}

Recruitment::~Recruitment()
{

}

void Recruitment::speciesProbability(float DEGD, int recruits)
{
  // add percent of current population to reduce recruitment based on population size
  //first identify how many species are present
  int numSpecies = 14; //counts number of species for determining probabilty

  for(int i = 0; i < 14; i++)
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
        if(_alderProb < 0)
        {
          _alderProb = 0.01;
        }
        break;
      case 5 :
        _hazelProb = (4 * ((4300 - DEGD) * (DEGD - 410))) / ((4300 - 410) * (4300 - 410));
        if(_hazelProb < 0)
        {
          _hazelProb = 0.01;
        }
        break;
      case 6 :
        _ashProb = (4 * ((4170 - DEGD) * (DEGD - 750))) / ((4170 - 750) * (4170 - 750));
        if(_ashProb < 0)
        {
          _ashProb = 0.01;
        }
        break;
      case 7 :
        _limeProb = (4 * ((4170 - DEGD) * (DEGD - 1100))) / ((4170 - 1100) * (4170 - 1100));
        if(_limeProb < 0)
        {
          _limeProb = 0.01;
        }
        break;
      case 8 :
        _birchProb = (4 * ((2300 - DEGD) * (DEGD - 410))) / ((2300 - 410) * (2300 - 410));
        if(_birchProb < 0)
        {
          _birchProb = 0.01;
        }
        break;
      case 9 :
        _hornProb = (4 * ((4330 - DEGD) * (DEGD - 810))) / ((4330 - 810) * (4330 - 810));
        if(_hornProb < 0)
        {
          _hornProb = 0.01;
        }
        break;
      case 10 :
        _larchProb = (4 * ((4890 - DEGD) * (DEGD - 1100))) / ((4890 - 1100) * (4890 - 1100));
        if(_larchProb < 0)
        {
          _larchProb = 0.01;
        }
        break;
      case 11 :
        _beechProb = (4 * ((4300 - DEGD) * (DEGD - 410))) / ((4300 - 410) * (4300 - 410));
        if(_beechProb < 0)
        {
          _beechProb = 0.01;
        }
        break;
      case 12 :
        _willowProb = (4 * ((4170 - DEGD) * (DEGD - 750))) / ((4170 - 750) * (4170 - 750));
        if(_willowProb < 0)
        {
          _willowProb = 0.01;
        }
        break;
      case 13 :
        _mapleProb = (4 * ((4170 - DEGD) * (DEGD - 1100))) / ((4170 - 1100) * (4170 - 1100));
        if(_mapleProb < 0)
        {
          _mapleProb = 0.01;
        }
        break;
      case 14 :
        _pftProb = (4 * ((2300 - DEGD) * (DEGD - 410))) / ((2300 - 410) * (2300 - 410));
        if(_pftProb < 0)
        {
          _pftProb = 0.01;
        }
        break;
    }
  }

  float percent = 1 / (float)numSpecies;

  //cout << "Percent Elm recruit = " << _elmProb << endl;
  //cout << "Percent Pine recruit = " << _pineProb << endl;
  //cout << "Percent Oak recruit = " << _oakProb << endl << endl;

  //cout << "Reduced percent Elm recruit = " << _elmProb * percent << endl;
  //cout << "Reduced percent Pine recruit = " << _pineProb * percent << endl;
  //cout << "Reduced percent Oak recruit = " << _oakProb * percent << endl << endl;

  //cout << "Number of species present = " << numSpecies << endl;
  //cout << "Percentage = " << percent << endl;

  if(_elmProb > 0)
  {
    _elmProb = _elmProb * percent;
    //cout << "Elm probabilty = " << _elmProb << endl;
  }

  if(_pineProb > 0)
  {
    _pineProb = _pineProb * percent;
    //cout << "Pine probabilty = " << _pineProb << endl;
  }

  if(_oakProb > 0)
  {
    _oakProb = _oakProb * percent;
    //cout << "Oak probabilty = " << _oakProb << endl;
  }

  if(_alderProb > 0)
  {
    _alderProb = _alderProb * percent;
    //cout << "Alder probabilty = " << _alderProb << endl;
  }

  if(_hazelProb > 0)
  {
    _hazelProb = _hazelProb * percent;
    //cout << "Hazel probabilty = " << _hazelProb << endl;
  }

  if(_ashProb > 0)
  {
    _ashProb = _ashProb * percent;
    //cout << "Ash probabilty = " << _ashProb << endl;
  }

  if(_limeProb > 0)
  {
    _limeProb = _limeProb * percent;
    //cout << "Lime probabilty = " << _limeProb << endl;
  }

  if(_birchProb > 0)
  {
    _birchProb = _birchProb * percent;
    //cout << "Birch probabilty = " << _birchProb << endl;
  }

  if(_hornProb > 0)
  {
    _hornProb = _hornProb * percent;
    //cout << "Hornbeam probabilty = " << _hornProb << endl;
  }

  if(_larchProb > 0)
  {
    _larchProb = _larchProb * percent;
    //cout << "Larch probabilty = " << _larchProb << endl;
  }

  if(_beechProb > 0)
  {
    _beechProb = _beechProb * percent;
    //cout << "Beech probabilty = " << _beechProb << endl;
  }

  if(_willowProb > 0)
  {
    _willowProb = _willowProb * percent;
    //cout << "Willow probabilty = " << _willowProb << endl;
  }

  if(_mapleProb > 0)
  {
    _mapleProb = _mapleProb * percent;
    //cout << "Maple probabilty = " << _mapleProb << endl;
  }

  if(_pftProb > 0)
  {
    _pftProb = _pftProb * percent;
    //cout << "PFT probabilty = " << _pftProb << endl;
  }

  overall = _elmProb + _pineProb + _oakProb + _alderProb + _hazelProb + _ashProb + _limeProb + _birchProb
        + _hornProb + _larchProb + _beechProb + _willowProb + _mapleProb + _pftProb;

  float newRecruits = (float)recruits * overall;
  _acRecruits = recruits;
  int _acRecruits2 = (int)newRecruits;

  cout << "New Recruits = " << _acRecruits2 << endl;
}

int Recruitment::getNumRecruits()
{
  return _acRecruits;
}

int Recruitment::getNumElm(float elmPercent)
{
  float numElm = ((float)_acRecruits * _elmProb) * elmPercent;

  if(numElm < 1)
  {
    numElm = 0;
  }

  return (int)numElm;
}

int Recruitment::getNumPine(float pinePercent)
{
  float numPine = ((float)_acRecruits *_pineProb) * pinePercent;

  if(numPine < 1)
  {
    numPine = 0;
  }

  return (int)numPine;
}

int Recruitment::getNumOak(float oakPercent)
{
  float numOak = ((float)_acRecruits * _oakProb) * oakPercent;

  if(numOak < 1)
  {
    numOak = 0;
  }

  return (int)numOak;
}

int Recruitment::getNumAlder(float alderPercent)
{
  float numAlder = ((float)_acRecruits * _alderProb) * alderPercent;

  if(numAlder < 1)
  {
    numAlder = 0;
  }

  return (int)numAlder;
}

int Recruitment::getNumHazel(float hazelPercent)
{
  float numHazel = ((float)_acRecruits *_hazelProb) * hazelPercent;

  if(numHazel < 1)
  {
    numHazel = 0;
  }

  return (int)numHazel;
}

int Recruitment::getNumAsh(float ashPercent)
{
  float numAsh = ((float)_acRecruits * _ashProb) * ashPercent;

  if(numAsh < 1)
  {
    numAsh = 0;
  }

  return (int)numAsh;
}

int Recruitment::getNumLime(float limePercent)
{
  float numLime = ((float)_acRecruits *_limeProb) * limePercent;

  if(numLime < 1)
  {
    numLime = 0;
  }

  return (int)numLime;
}

int Recruitment::getNumBirch(float birchPercent)
{
  float numBirch = ((float)_acRecruits * _birchProb) * birchPercent;

  if(numBirch < 1)
  {
    numBirch = 0;
  }

  return (int)numBirch;
}

int Recruitment::getNumHorn(float hornPercent)
{
  float numHorn = ((float)_acRecruits * _hornProb) * hornPercent;

  if(numHorn < 1)
  {
    numHorn = 0;
  }

  return (int)numHorn;
}

int Recruitment::getNumLarch(float larchPercent)
{
  float numLarch = ((float)_acRecruits * _larchProb) * larchPercent;

  if(numLarch < 1)
  {
    numLarch = 0;
  }

  return (int)numLarch;
}

int Recruitment::getNumBeech(float beechPercent)
{
  float numBeech = ((float)_acRecruits * _beechProb) * beechPercent;

  if(numBeech < 1)
  {
    numBeech = 0;
  }

  return (int)numBeech;
}

int Recruitment::getNumWillow(float willowPercent)
{
  float numWillow = ((float)_acRecruits * _willowProb) * willowPercent;

  if(numWillow < 1)
  {
    numWillow = 0;
  }

  return (int)numWillow;
}

int Recruitment::getNumMaple(float maplePercent)
{
  float numMaple = ((float)_acRecruits * _mapleProb) * maplePercent;

  if(numMaple < 1)
  {
    numMaple = 0;
  }

  return (int)numMaple;
}

int Recruitment::getNumPFT(float pftPercent)
{
  float numPFT = ((float)_acRecruits * _pftProb) * pftPercent;

  if(numPFT < 1)
  {
    numPFT = 0;
  }

  return (int)numPFT;
}
