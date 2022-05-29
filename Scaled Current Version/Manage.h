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
  void setRPer(float rPer);

  int getTicks();
  int getSpecies();
  int getRSum();
  float getRPer();

private:
  int _species;
  int _ticks;
  int _rSum; // number of species
  float _rPer; // Percentage of total species
};

#endif
