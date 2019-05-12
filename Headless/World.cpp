#include "World.h"

World::World()
{


}
World::~World()
{


}

float World::getLNum()
{
  return _lNum;
}

float World::getSmNum()
{
  return _smNum;
}

void World::loadWorld(const char* fileName)
{
  string line;
  ifstream file (fileName);
  file.is_open();

  float **my_array;
  my_array = new float*[1000];

  for (int i = 0; i < 1000; i++) {
    my_array[i] = new float[1000];
  }

  _lNum = world[0][0];

  for (int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      file >> my_array[i][j];
      world[i][j] = my_array[i][j];
      if(_lNum < world[i][j])
      {
        _lNum = world[i][j];
      }
    }
    //cout << endl;
  }

  _smNum = _lNum;

  for (int i = 0; i < 1000; i++)
  {
    for(int j = 0; j < 1000; j++)
    {
      if(_smNum > world[i][j] && world[i][j] >= 0)
      {
        _smNum = world[i][j];
      }
    }
  }

  file.close();

  cout << "Array created! " << endl;

  for (int i = 0; i < 1000; i++) {
    delete[] my_array[i];
  }

  delete[] my_array;
}
