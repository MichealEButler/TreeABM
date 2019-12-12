#ifndef MANAGE_H
#define MANAGE_H

#include <iostream>
#include <vector>

class Manage
{
public:
  Manage();
  ~Manage();
  void genRemoval(); // removes set amount of a species at specified tick intervals
  void setTicks(int ticks);
  void setSpecies(int species);
  void setRSum(int rSum);

  int getTicks();
  int getSpecies();
  int getRSum();

private:
  int _species;
  int _ticks;
  int _rSum; // number of species
  int _rPer; // Percentage of total species
};

#endif
