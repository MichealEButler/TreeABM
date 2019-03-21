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

void Output::createDirectories()
{
  // creates chunk directories
  for (int i = 0; i < 100; i++)
  {
    const char* a = "/home/micheal/Documents/CppModel/CppModel 3.0/Output/Chunks/Chunk";
    string stringB = to_string(i);
    const char* b = stringB.c_str();
    char buffer[256];
    strncpy(buffer, a, sizeof(buffer));
    strncat(buffer, b, sizeof(buffer));

    const int dir = mkdir(buffer, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  }
}

void Output::runOutput(int agentID, string species, int x, int y, float DBH, float height, float radius, int chunk)
{
  //cout << "agentID = " << agentID << endl;
  file << agentID << ", ";
  //cout << "species = " << species << endl;
  file << species << ", ";
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
  file << chunk << " " << endl;
}

void Output::blenderOutput(int agentID, string species, int x, int y,float DBH, float height, float radius)
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
  file << radius << " " << endl;
}

void Output::chunkOutput(int agentID, int x, int y, int chunk)
{
  file << agentID << ",";
  file << x << ",";
  file << y << ",";
  file << chunk << " " << endl;
}

void Output::closeFile()
{
  file.close();
}

void Output::displayOutput()
{

}
