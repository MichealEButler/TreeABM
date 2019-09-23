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

  for(int i = 0; i < 10; i++)
  {
    file >> one >> two;
    switch(i)
    {
      case 0:
        _ticks = (int)value; // value between 1 and 8 for species
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
        _hornNo = value;
        break;
      case 10:
        _larchNo = value;
        break;
      case 11:
        _beechNo = value;
        break;
      case 12:
        _willowNo = value;
        break;
      case 13:
        _mapleNo = value;
        break;
      case 14:
        _pftNo = value;
        break;
      case 15:
        _change = value;
        break;
      default:
        break;
    }
  }
}

void Input::loadPlotFile(string inFile, int nplot)
{
  string species;
  int plot;
  int DBHclass;
  int count;
  int year;

  _elmCount.clear();
  _pineCount.clear();
  _oakCount.clear();
  _alderCount.clear();
  _hazelCount.clear();
  _ashCount.clear();
  _limeCount.clear();
  _birchCount.clear();

  _elmCountTwo.clear();
  _pineCountTwo.clear();
  _oakCountTwo.clear();
  _alderCountTwo.clear();
  _hazelCountTwo.clear();
  _ashCountTwo.clear();
  _limeCountTwo.clear();
  _birchCountTwo.clear();

  ifstream file;
  file.open(inFile);

  while(file)
  {
    file >> plot;
    file >> species;
    file >> DBHclass;
    file >> count;
    file >> year;

    if(plot == nplot)
    {
      if(year == 1)
      {
        if(readSpecies(species) == 1)
        {
        // pseudo procedure = store in species vector to be based to simualtion
        // vector will include list of every inidividuals dbhclass, which will then be read
        // during initialisation in the Simulation class
          for(int i = 0; i < count; i++)
          {
            _elmCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 2)
        {
          for(int i = 0; i < count; i++)
          {
            _pineCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 3)
        {
          for(int i = 0; i < count; i++)
          {
            _oakCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 4)
        {
          for(int i = 0; i < count; i++)
          {
            _alderCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 5)
        {
          for(int i = 0; i < count; i++)
          {
            _hazelCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 6)
        {
          for(int i = 0; i < count; i++)
          {
            _ashCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 7)
        {
          for(int i = 0; i < count; i++)
          {
            _limeCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 8)
        {
          for(int i = 0; i < count; i++)
          {
            _birchCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 9)
        {
          for(int i = 0; i < count; i++)
          {
            _hornCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 10)
        {
          for(int i = 0; i < count; i++)
          {
            _larchCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 11)
        {
          for(int i = 0; i < count; i++)
          {
            _beechCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 12)
        {
          for(int i = 0; i < count; i++)
          {
            _willowCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 13)
        {
          for(int i = 0; i < count; i++)
          {
            _mapleCount.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 14)
        {
          for(int i = 0; i < count; i++)
          {
            _pftCount.push_back(DBHclass);
          }
        }
      }

      if(year == 2)
      {
        if(readSpecies(species) == 1)
        {
          // pseudo procedure = store in species vector to be based to simualtion
          // vector will include list of every inidividuals dbhclass, which will then be read
          // during initialisation in the Simulation class
          for(int i = 0; i < count; i++)
          {
            _elmCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 2)
        {
          for(int i = 0; i < count; i++)
          {
            _pineCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 3)
        {
          for(int i = 0; i < count; i++)
          {
            _oakCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 4)
        {
          for(int i = 0; i < count; i++)
          {
            _alderCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 5)
        {
          for(int i = 0; i < count; i++)
          {
            _hazelCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 6)
        {
          for(int i = 0; i < count; i++)
          {
            _ashCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 7)
        {
          for(int i = 0; i < count; i++)
          {
            _limeCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 8)
        {
          for(int i = 0; i < count; i++)
          {
          _birchCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 9)
        {
          for(int i = 0; i < count; i++)
          {
            _hornCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 10)
        {
          for(int i = 0; i < count; i++)
          {
            _larchCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 11)
        {
          for(int i = 0; i < count; i++)
          {
            _beechCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 12)
        {
          for(int i = 0; i < count; i++)
          {
            _willowCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 13)
        {
          for(int i = 0; i < count; i++)
          {
            _mapleCountTwo.push_back(DBHclass);
          }
        }
        if(readSpecies(species) == 14)
        {
          for(int i = 0; i < count; i++)
          {
            _pftCountTwo.push_back(DBHclass);
          }
        }
      }
    }
  }
  file.close();
}

void Input::readVectors()
{
  //read vectors that have more than one element
  if(_elmCount.size() >= 1)
  {
    for(int i = 0; i < _elmCount.size(); i++)
    {
      cout << "Elm tree " << i << " dbh = " << _elmCount[i] << endl;
    }
  }

  if(_pineCount.size() >= 1)
  {
    for(int i = 0; i < _pineCount.size(); i++)
    {
      cout << "Pine tree " << i << " dbh = " << _pineCount[i] << endl;
    }
  }

  if(_oakCount.size() >= 1)
  {
    for(int i = 0; i < _oakCount.size(); i++)
    {
      cout << "Oak tree " << i << " dbh = " << _oakCount[i] << endl;
    }
  }

  if(_alderCount.size() >= 1)
  {
    for(int i = 0; i < _alderCount.size(); i++)
    {
      cout << "Alder tree " << i << " dbh = " << _alderCount[i] << endl;
    }
  }

  if(_hazelCount.size() >= 1)
  {
    for(int i = 0; i < _hazelCount.size(); i++)
    {
      cout << "Hazel tree " << i << " dbh = " << _hazelCount[i] << endl;
    }
  }

  if(_ashCount.size() >= 1)
  {
    for(int i = 0; i < _ashCount.size(); i++)
    {
      cout << "Ash tree " << i << " dbh = " << _ashCount[i] << endl;
    }
  }

  if(_limeCount.size() >= 1)
  {
    for(int i = 0; i < _limeCount.size(); i++)
    {
      cout << "Lime tree " << i << " dbh = " << _limeCount[i] << endl;
    }
  }

  if(_birchCount.size() >= 1)
  {
    for(int i = 0; i < _birchCount.size(); i++)
    {
      cout << "Birch tree " << i << " dbh = " << _birchCount[i] << endl;
    }
  }

  if(_hornCount.size() >= 1)
  {
    for(int i = 0; i < _hornCount.size(); i++)
    {
      cout << "Hornbeam tree " << i << " dbh = " << _hornCount[i] << endl;
    }
  }

  if(_larchCount.size() >= 1)
  {
    for(int i = 0; i < _larchCount.size(); i++)
    {
      cout << "Larch tree " << i << " dbh = " << _larchCount[i] << endl;
    }
  }

  if(_beechCount.size() >= 1)
  {
    for(int i = 0; i < _beechCount.size(); i++)
    {
      cout << "Beech tree " << i << " dbh = " << _beechCount[i] << endl;
    }
  }

  if(_willowCount.size() >= 1)
  {
    for(int i = 0; i < _willowCount.size(); i++)
    {
      cout << "Willow tree " << i << " dbh = " << _willowCount[i] << endl;
    }
  }

  if(_mapleCount.size() >= 1)
  {
    for(int i = 0; i < _mapleCount.size(); i++)
    {
      cout << "Maple tree " << i << " dbh = " << _mapleCount[i] << endl;
    }
  }

  if(_pftCount.size() >= 1)
  {
    for(int i = 0; i < _pftCount.size(); i++)
    {
      cout << "PFT tree " << i << " dbh = " << _pftCount[i] << endl;
    }
  }

}

int Input::readSpecies(string name)
{
  char* first;
  char* second;
  char* third;
  char* forth;

  int species = 0;

  first = &name.at(0);
  second = &name.at(1);
  third = &name.at(2);
  forth = &name.at(3);

  switch(*first)
  {
    case 'U' :
      switch(*third)
      {
        case 'e' :
          cout << "Species is Ulex. " << endl;
          species = 14;
          break;
        case 'm' :
          cout << "Species is Ulmus. " << endl;
          species = 1;
          break;
      }
      break;
    case 'C' :
      switch(*second)
      {
        case 'o' :
          switch(*third)
          {
            case 'r' :
              switch(*forth)
              {
                case 'n' :
                  cout << "Species is Cornus. " << endl;
                  species = 14;
                  break;
                case 'y' :
                  cout << "Species is Corylus. " << endl;
                  species = 5;
                  break;
              }
              break;
          }
          break;
        case 'r' :
          cout << "Species is Crataegus. " << endl;
          species = 14;
          break;
        case 'l' :
          cout << "Species is Clematis. " << endl;
          species = 14;
          break;
        case 'y' :
          cout << "Species is Cytitus. " << endl;
          species = 14;
          break;
        case 'a' :
          switch(*third)
          {
            case 's' :
              cout << "Species is Castanea. " << endl;
              species = 14;
              break;
            case 'r' :
              cout << "Species is Carpinus. " << endl;
              species = 9;
              break;
          }
          break;
      }
      break;
    case 'L' :
      switch(*second)
      {
        case 'i' :
          cout << "Species is Ligustrum. " << endl;
          species = 14;
          break;
        case 'a' :
          cout << "Species is Larix. " << endl;
          species = 10;
          break;
      }
      break;
    case 'R' :
      switch(*third)
      {
        case 'a' :
          cout << "Species is Rhamus. " << endl;
          species = 14;
          break;
        case 'o' :
          cout << "Species is Rhododendron. " << endl;
          species = 14;
          break;
      }
      break;
    case 'V' :
      cout << "Species is Viburnum. " << endl;
      species = 14;
      break;
    case 'E' :
      cout << "Species is Euonymus. " << endl;
      species = 14;
      break;
    case 'J' :
      cout << "Species is Juniperus. " << endl;
      species = 14;
      break;
    case 'S' :
        switch(*second)
        {
          case 'a' :
            switch(*third)
            {
              case 'm' :
                cout << "Species is Sambucus. " << endl;
                species = 14;
                break;
              case 'l' :
                cout << "Species is Salix. " << endl;
                species = 12;
                break;
            }
            break;
          case 'o' :
            cout << "Species is Sorbus. " << endl;
            species = 14;
            break;
        }
        break;
      case 'F' :
        switch(*second)
        {
          case 'r' :
            switch(*forth)
            {
              case 'n' :
                cout << "Species is Frangula. " << endl;
                species = 14;
                break;
              case 'x' :
                cout << "Species is Fraxinus. " << endl;
                species = 6;
                break;
            }
            break;
          case 'a' :
            cout << "Species is Fagus. " << endl;
            species = 11;
            break;
        }
        break;
      case 'P' :
        switch(*second)
        {
          case 'r' :
            cout << "Species is Prunus. " << endl;
            species = 14;
            break;
          case 'o' :
            cout << "Species is Populus " << endl;
            species = 14;
            break;
          case 'i' :
            switch(*third)
            {
              case 'c' :
                cout << "Species is Picea. " << endl;
                species = 14;
                break;
              case 'n' :
                cout << "Species is Pinus. " << endl;
                species = 2;
                break;
            }
            break;
          case 's' :
            cout << "Species is Pseudostuga. " << endl;
            species = 14;
            break;
        }
        break;
      case 'B' :
        cout << "Species is Betula. " << endl;
        species = 8;
        break;
      case 'Q' :
        cout << "Speices is Quercus. " << endl;
        species = 3;
        break;
      case 'M' :
        cout << "Species is Malus. " << endl;
        species = 14;
        break;
      case 'A' :
        switch(*second)
        {
          case 'c' :
            cout << "Species is Acer. " << endl;
            species = 13;
            break;
          case 'e' :
            cout << "Species is Aesculus. " << endl;
            species = 14;
            break;
          case 'l' :
            cout << "Species is Alnus. " << endl;
            species = 4;
            break;
          case 'b' :
            cout << "Species is Abies. " << endl;
            species = 14;
            break;
        }
        break;
      case 'T' :
        switch(*second)
        {
          case 'i' :
            cout << "Species is Tilia. " << endl;
            species = 7;
            break;
          case 'a' :
            cout << "Species is Taxus. " << endl;
            species = 14;
            break;
          case 'h' :
            cout << "Species is Thuja. " << endl;
            species = 14;
            break;
          case 's' :
            cout << "Species is Tsuga. " << endl;
            species = 14;
            break;
        }
        break;
    default:
      cout << "Unknown Species " << endl;
      //species = 14;
  }

  cout << species << endl;
  return species;
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

float Input::getHornCount()
{
  return _hornNo;
}

float Input::getLarchCount()
{
  return _larchNo;
}

float Input::getBeechCount()
{
  return _beechNo;
}

float Input::getWillowCount()
{
  return _willowNo;
}

float Input::getMapleCount()
{
  return _mapleNo;
}

float Input::getPFTCount()
{
  return _pftNo;
}

float Input::getChange()
{
  return _change;
}

vector <int> Input::getElmInit()
{
  return _elmCount;
}

vector <int> Input::getPineInit()
{
  return _pineCount;
}

vector <int> Input::getOakInit()
{
  return _oakCount;
}

vector <int> Input::getAlderInit()
{
  return _alderCount;
}

vector <int> Input::getHazelInit()
{
  return _hazelCount;
}

vector <int> Input::getAshInit()
{
  return _ashCount;
}

vector <int> Input::getLimeInit()
{
  return _limeCount;
}

vector <int> Input::getBirchInit()
{
  return _birchCount;
}

vector <int> Input::getHornInit()
{
  return _hornCount;
}

vector <int> Input::getLarchInit()
{
  return _larchCount;
}

vector <int> Input::getBeechInit()
{
    return _beechCount;
}

vector <int> Input::getWillowInit()
{
  return _willowCount;
}

vector <int> Input::getMapleInit()
{
  return _mapleCount;
}

vector <int> Input::getPFTInit()
{
  return _pftCount;
}
