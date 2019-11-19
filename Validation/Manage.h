#ifndef MANAGE_H
#define MANAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Manage
{
public:
  Manage();
  ~Manage();
  void setSpecies(vector<int> speciesList);
  void setDBHrange(int DBHmin, int DBHmax); // in cms
  void setYear(int year);
  bool removeState(int species, int DBHrange, int rYear); //returns true if the individual is to be removed from the simulation

private:
  int _species; //species to be removed
  int _DBHmin; //minimum dbh for removal
  int _DBHmax; //maximum dbh for removal
  int _year; //year at which individuals will be removed

  vector<int> _speciesList;
};

#endif
