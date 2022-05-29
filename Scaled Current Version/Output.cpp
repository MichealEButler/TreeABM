#include "Output.h"

Output::Output()
{

}

Output::~Output()
{

}

void Output::openFile(string title)
{
  file.open(title);
}

void Output::outPatches(int array[100][100], string filename)
{
  f.open(filename);

  for(int i = 0; i < 100; i++)
  {
    for(int j = 0; j < 100; j++)
    {
      f << array[i][j] << " ";
    }
    f << endl;
  }

  f.close();
}

void Output::createFolder(int folderN)
{
  const char* a = "/home/micheal/Documents/Scaled-12-10-21/Output/M";
  string stringB = to_string(folderN);
  const char* b = stringB.c_str();
  char buffer[256];
  strncpy(buffer, a, sizeof(buffer));
  strncat(buffer, b, sizeof(buffer));

  const int dir = mkdir(buffer, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

void Output::createDirectories()
{
  // creates chunk directories
  for (int i = 0; i < 100; i++)
  {
    const char* a = "/home/micheal/Documents/CppModel/CppModel 3.0/Output/Chunks/Chunk";
    string stringB = to_string(i+1);
    const char* b = stringB.c_str();
    char buffer[256];
    strncpy(buffer, a, sizeof(buffer));
    strncat(buffer, b, sizeof(buffer));

    const int dir = mkdir(buffer, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  }
}

void Output::populations(int &year, int &elmNo, float &elmAge, int &pineNo, float &pineAge, int &oakNo, float &oakAge, int &alderNo, float &alderAge,
                          int &hazelNo, float &hazelAge, int &ashNo, float &ashAge, int &limeNo, float &limeAge, int &birchNo, float &birchAge, int &openPatches, float &biomass, float &diameter)
{
  file << year << ", ";
  file << elmNo << ", ";
  file << elmAge << ", ";
  file << pineNo << ", ";
  file << pineAge << ", ";
  file << oakNo << ", ";
  file << oakAge << ", ";
  file << alderNo << ", ";
  file << alderAge << ", ";
  file << hazelNo << ", ";
  file << hazelAge << ", ";
  file << ashNo << ", ";
  file << ashAge << ", ";
  file << limeNo << ", ";
  file << limeAge << ", ";
  file << birchNo << ", ";
  file << birchAge << ", ";
  file << openPatches << ", ";
  file << biomass << ", ";
  file << diameter << " " << endl;
}

void Output::QMD(float QMD, float BA, int population)
{
  file << QMD << ", ";
  file << BA << ", ";
  file << population << " " << endl;
}

void Output::monoStand(int pop1, float QMD1, float BA1, float SDI1)
{
  file << pop1 << ", ";
  file << QMD1 << ", ";
  file << BA1 << ", ";
  file << SDI1 << " " << endl;
}

void Output::dualStand(int pop1, float QMD1, float BA1, float SDI1, int pop2, float QMD2, float BA2, float SDI2)
{
  file << pop1 << ", ";
  file << QMD1 << ", ";
  file << BA1 << ", ";
  file << SDI1 << ", ";
  file << pop2 << ", ";
  file << QMD2 << ", ";
  file << BA2 << ", ";
  file << SDI2 << " " << endl;
}

void Output::mixedStand(int pop1, float QMD1, float BA1, float SDI1, int pop2, float QMD2, float BA2, float SDI2,int pop3, float QMD3, float BA3, float SDI3)
{
  file << pop1 << ", ";
  file << QMD1 << ", ";
  file << BA1 << ", ";
  file << SDI1 << ", ";
  file << pop2 << ", ";
  file << QMD2 << ", ";
  file << BA2 << ", ";
  file << SDI2 << ", ";
  file << pop3 << ", ";
  file << QMD3 << ", ";
  file << BA3 << ", ";
  file << SDI3 << " " << endl;
}

void Output::palaeoStand(int pop1, float QMD1, float BA1, float BIO1, float BIOA1, int pop2, float QMD2, float BA2, float BIO2, float BIOA2, int pop3, float QMD3, float BA3, float BIO3, float BIOA3, int pop4, float QMD4, float BA4, float BIO4, float BIOA4,
                int pop5, float QMD5, float BA5, float BIO5, float BIOA5, int pop6, float QMD6, float BA6, float BIO6, float BIOA6, int pop7, float QMD7, float BA7, float BIO7, float BIOA7, int pop8, float QMD8, float BA8, float BIO8, float BIOA8)
{
  file << pop1 << ", ";
  file << QMD1 << ", ";
  file << BA1 << ", ";
  file << BIO1 << ", ";
  file << BIOA1 << ", ";
  file << pop2 << ", ";
  file << QMD2 << ", ";
  file << BA2 << ", ";
  file << BIO2 << ", ";
  file << BIOA2 << ", ";
  file << pop3 << ", ";
  file << QMD3 << ", ";
  file << BA3 << ", ";
  file << BIO3 << ", ";
  file << BIOA3 << ", ";
  file << pop4 << ", ";
  file << QMD4 << ", ";
  file << BA4 << ", ";
  file << BIO4 << ", ";
  file << BIOA4 << ", ";
  file << pop5 << ", ";
  file << QMD5 << ", ";
  file << BA5 << ", ";
  file << BIO5 << ", ";
  file << BIOA5 << ", ";
  file << pop6 << ", ";
  file << QMD6 << ", ";
  file << BA6 << ", ";
  file << BIO6 << ", ";
  file << BIOA6 << ", ";
  file << pop7 << ", ";
  file << QMD7 << ", ";
  file << BA7 << ", ";
  file << BIO7 << ", ";
  file << BIOA7 << ", ";
  file << pop8 << ", ";
  file << QMD8 << ", ";
  file << BA8 << ", ";
  file << BIO8 << ", ";
  file << BIOA8 << " " << endl;
}

void Output::initialPopulation(int agentID, int species, float DBH, int sizeClass)
{
  file << agentID << ", ";
  file << species << ", ";
  file << DBH << ", ";
  file << sizeClass << " " << endl;
}

void Output::openessOutput(int year, int openPatches)
{
  file << year << ", ";
  file << openPatches << " " << endl;
}

void Output::runOutput(int agentID, int species, int age, int x, int y, float DBH, float height, float radius, float biomass, int chunk, bool dominant, float elevation)
{
  //cout << "agentID = " << agentID << endl;
  file << agentID << ", ";
  //cout << "species = " << species << endl;
  file << species << ", ";
  file << age << ", ";
  //cout << "x = " << x << endl;
  file << x << ", ";
  //cout << "y = " << y << endl;
  file << y << ", ";
  //cout << "DBH = " << DBH << endl;
  file << DBH << ", ";
  //cout << "Height = " << height << endl;
  file << height << ", ";
  //cout << "Radius = " << radius << endl;
  file << radius << ", ";
  file << biomass << ", ";
  file << chunk << ", ";
  file << dominant << ", " << endl;
  file << elevation << " " << endl;
}

void Output::blenderOutput(int agentID, int species, int x, int y,float DBH, float height, float radius, float elevation)
{
  //cout << "agentID = " << agentID << endl;
  file << agentID << ",";
  //cout << "species = " << species << endl;
  file << species << ",";
  //cout << "x = " << x << endl;
  file << x << ",";
  //cout << "y = " << y << endl;
  file << y << ",";
  //cout << "DBH = " << DBH << endl;
  file << DBH << ",";
  //cout << "Height = " << height << endl;
  file << height << ",";
  //cout << "Radius = " << radius << endl;
  file << radius << ", ";
  file << elevation << " " << endl;
}

void Output::chunkOutput(int agentID, int species, int x, int y, int chunk,float DBH, float height, float radius, float elevation)
{
  file << agentID << ",";
  file << species << ",";
  file << x << ",";
  file << y << ",";
  file << chunk << ", ";
  file << DBH << ",";
  file << height << ",";
  file << radius << ", ";
  file << elevation << " " << endl;
}

void Output::manageOutput(int s1Pop, float s1Biomass, int s2Pop, float s2Biomass, int s3Pop, float s3Biomass, float lBiomass, int population)
{
  file << s1Pop << ",";
  file << s1Biomass << ",";
  file << s2Pop << ",";
  file << s2Biomass << ",";
  file << s3Pop << ", ";
  file << s3Biomass << ",";
  file << lBiomass << ",";
  file << population << " " << endl;
}

void Output::closeFile()
{
  file.close();
}

void Output::displayOutput()
{

}
