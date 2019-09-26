#include "Manage.h"

Manage::Manage()
{

}

Manage::~Manage()
{

}

void Manage::setSpecies(vector<int> speciesList)
{
  _speciesList = speciesList;
}

void Manage::setDBHrange(int DBHmin, int DBHmax)
{
  _DBHmin = DBHmin;
  _DBHmax = DBHmax;
}

void Manage::setYear(int year)
{
  _year = year;
}

bool Manage::removeState(int species, int DBHrange, int rYear)
{
  if(rYear == _year)
  {
    if(DBHrange >= _DBHmin && DBHrange <= _DBHmax)
    {
      for(int i = 0; i < _speciesList.size(); i++)
      {
        if(species == _speciesList[i])
        {
          cout << "Returned True " << endl;
          return true;
        }
      }
    }
  }

  return false;
}
