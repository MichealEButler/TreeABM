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

void Input::loadPlotFile(string inFile)
{
  string plot, species, DBHclass, count;
  int year;

  ifstream file;
  file.open(inFile);

  while(file)
  {
    file >> plot;
    file >> species;
    file >> DBHclass;
    file >> count;
    file >> year;

    if(year == 1)
    {
      if(readSpecies(species) == 1)
      {

      }
      if(readSpecies(species) == 2)
      {

      }
      if(readSpecies(species) == 3)
      {

      }
      if(readSpecies(species) == 4)
      {

      }
      if(readSpecies(species) == 5)
      {

      }
      if(readSpecies(species) == 6)
      {

      }
      if(readSpecies(species) == 7)
      {

      }
      if(readSpecies(species) == 8)
      {

      }
    }

    if(year == 2)
    {
      if(readSpecies(species) == 1)
      {

      }
      if(readSpecies(species) == 2)
      {

      }
      if(readSpecies(species) == 3)
      {

      }
      if(readSpecies(species) == 4)
      {

      }
      if(readSpecies(species) == 5)
      {

      }
      if(readSpecies(species) == 6)
      {

      }
      if(readSpecies(species) == 7)
      {

      }
      if(readSpecies(species) == 8)
      {

      }
    }
  }
  file.close();
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
          break;
        case 'l' :
          cout << "Species is Clematis. " << endl;
          break;
        case 'y' :
          cout << "Species is Cytitus. " << endl;
          break;
        case 'a' :
          switch(*third)
          {
            case 's' :
              cout << "Species is Castanea. " << endl;
              break;
            case 'r' :
              cout << "Species is Carpinus. " << endl;
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
          break;
        case 'a' :
          cout << "Species is Larix. " << endl;
          break;
      }
      break;
    case 'R' :
      switch(*third)
      {
        case 'a' :
          cout << "Species is Rhamus. " << endl;
          break;
        case 'o' :
          cout << "Species is Rhododendron. " << endl;
          break;
      }
      break;
    case 'V' :
      cout << "Species is Viburnum. " << endl;
      break;
    case 'E' :
      cout << "Species is Euonymus. " << endl;
      break;
    case 'J' :
      cout << "Species is Juniperus. " << endl;
      break;
    case 'S' :
        switch(*second)
        {
          case 'a' :
            switch(*third)
            {
              case 'm' :
                cout << "Species is Sambucus. " << endl;
                break;
              case 'l' :
                cout << "Species is Salix. " << endl;
                break;
            }
            break;
          case 'o' :
            cout << "Species is Sorbus. " << endl;
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
                break;
              case 'x' :
                cout << "Species is Fraxinus. " << endl;
                species = 6;
                break;
            }
            break;
          case 'a' :
            cout << "Species is Fagus. " << endl;
            break;
        }
        break;
      case 'P' :
        switch(*second)
        {
          case 'r' :
            cout << "Species is Prunus. " << endl;
            break;
          case 'o' :
            cout << "Species is Populus " << endl;
            break;
          case 'i' :
            switch(*third)
            {
              case 'c' :
                cout << "Species is Picea. " << endl;
                break;
              case 'n' :
                cout << "Species is Pinus. " << endl;
                species = 2;
                break;
            }
            break;
          case 's' :
            cout << "Species is Pseudostuga. " << endl;
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
        break;
      case 'A' :
        switch(*second)
        {
          case 'c' :
            cout << "Species is Acer. " << endl;
            break;
          case 'e' :
            cout << "Species is Aesculus. " << endl;
            break;
          case 'l' :
            cout << "Species is Alnus. " << endl;
            species = 4;
            break;
          case 'b' :
            cout << "Species is Abies. " << endl;
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
            break;
          case 'h' :
            cout << "Species is Thuja. " << endl;
            break;
          case 's' :
            cout << "Species is Tsuga. " << endl;
            break;
        }
        break;
    default:
      cout << "Unknown Species " << endl;
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

float Input::getChange()
{
  return _change;
}
