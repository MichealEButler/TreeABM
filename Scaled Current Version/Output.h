#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cstring>

using namespace std;

class Output
{
public:
  Output();
  ~Output();
  void openFile(string title);
  void createDirectories();
  void createFolder(int folderN);
  void outPatches(int array[100][100], string filename);
  void QMD(float QMD, float BA, int population);
  void monoStand(int pop1, float QMD1, float BA1, float SDI1);
  void dualStand(int pop1, float QMD1, float BA1, float SDI1, int pop2, float QMD2, float BA2, float SDI2);
  void mixedStand(int pop1, float QMD1, float BA1, float SDI1, int pop2, float QMD2, float BA2, float SDI2,int pop3, float QMD3, float BA3, float SDI3);
  void palaeoStand(int pop1, float QMD1, float BA1, float BIO1, float BIOA1, int pop2, float QMD2, float BA2, float BIO2, float BIOA2, int pop3, float QMD3, float BA3, float BIO3, float BIOA3, int pop4, float QMD4, float BA4, float BIO4, float BIOA4,
                  int pop5, float QMD5, float BA5, float BIO5, float BIOA5, int pop6, float QMD6, float BA6, float BIO6, float BIOA6, int pop7, float QMD7, float BA7, float BIO7, float BIOA7, int pop8, float QMD8, float BA8, float BIO8, float BIOA8);
  void initialPopulation(int agentID, int species, float DBH, int sizeClass);
  void populations(int &year, int &elmNo, float &elmAge, int &pineNo, float &pineAge, int &oakNo, float &oakAge, int &alderNo, float &alderAge, int &hazelNo, float &hazelAge,
    int &ashNo, float &ashAge, int &limeNo, float &limeAge, int &birchNo, float &birchAge, int &openPatches, float &biomass, float &diameter);
  void runOutput(int agentID, int species, int age, int x, int y, float DBH, float height, float radius, float biomass, int chunk, bool dominant, float elevation);
  void openessOutput(int year, int openPatches);
  void blenderOutput(int agentID, int species, int x, int y,float DBH, float height, float radius, float elevation);
  void chunkOutput(int agentID, int species, int x, int y, int chunk, float DBH, float height, float radius, float elevation);
  void manageOutput(int s1Pop, float s1Biomass, int s2Pop, float s2Biomass, int s3Pop, float s3Biomass, float lBiomass, int population);
  void closeFile();

  void displayOutput();

  ofstream file;
  ofstream f;
private:

};

#endif
