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

void Output::populations(int year, int elmNo, float elmAge, int pineNo, float pineAge, int oakNo, float oakAge, int alderNo, float alderAge,
                          int hazelNo, float hazelAge, int ashNo, float ashAge, int limeNo, float limeAge, int birchNo, float birchAge)
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
  file << birchAge << " " << endl;
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

void Output::closeFile()
{
  file.close();
}

void Output::displayOutput()
{

}
