#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

class Data
{
public:
  Data();
  ~Data();
  void basalArea(float BA); // takes indivdual basal area
  void QMD();
  void QMD2(float avgDiameter);
  void population(int pop);
  void cohortBiomass(float biomass);
  void SDI();
  void BIO(float BIO);
  void BIOA(float BIOA);

  void setBasalArea(float BA); //used o reset basal area calcualtions every tick (pass in 0)
  void setQMD(float QMD); //used o reset QMD calcualtions every tick (pass in 0)
  void setPopulation(int pop);
  void setCohortBiomass(float biomass); // total biomass for specific species
  void setSDI(float SDI);
  void setBIO(float BIO);
  void setBIOA(float BIO);

  void calcSpeciesVigor(int speciesPop);


  float getBasalArea();
  float getQMD();
  float getQMD2();
  float getPopulation();
  float getBiomass();
  float getSDI();
  float getBIO();
  float getBIOA();

private:
  float _BA;
  float _QMD;
  float _pop;
  float _QMD2;
  float _biomass; //species biomass
  float _SDI;
  float _BIO;
  float _BIOA;
};

#endif
