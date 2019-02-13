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

void Output::runOutput(const char* agentID, const char* species, int x, int y, float DBH, float height, float radius)
{
  //cout << "agentID = " << agentID << endl;
  file << agentID << " ";
  //cout << "species = " << species << endl;
  file << species << " ";
  //cout << "x = " << x << endl;
  file << x << " ";
  //cout << "y = " << y << endl;
  file << y << " ";
  //cout << "DBH = " << DBH << endl;
  file << DBH << " ";
  //cout << "Height = " << height << endl;
  file << height << " ";
  //cout << "Radius = " << radius << endl;
  file << radius << " " << endl;
}

void Output::closeFile()
{
  file.close();
}

void Output::displayOutput()
{

}
