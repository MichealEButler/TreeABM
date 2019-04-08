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

float World::getElevation(int x, int y)
{
  return world[y][x];
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

void World::renderWorld(SDL_Renderer* renderer)
{
  float type;

  float range = _lNum - _smNum;
  float tenth = range / 20;

  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 1000; i++) {
      type = world[j][i];

      if(type < _smNum + tenth)
      {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + tenth && type < _smNum + (tenth*2))
      {
        SDL_SetRenderDrawColor(renderer, 12, 12, 12, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*2) && type < _smNum + (tenth*3))
      {
        SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*3) && type < _smNum + (tenth*4))
      {
        SDL_SetRenderDrawColor(renderer, 36, 36, 36, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*4) && type < _smNum + (tenth*5))
      {
        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*5) && type < _smNum + (tenth*6))
      {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*6) && type < _smNum + (tenth*7))
      {
        SDL_SetRenderDrawColor(renderer, 72, 72, 72, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*7) && type < _smNum + (tenth*8))
      {
        SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*8) && type < _smNum + (tenth*9))
      {
        SDL_SetRenderDrawColor(renderer, 96, 96, 96, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*9) && type < _smNum + (tenth*10))
      {
        SDL_SetRenderDrawColor(renderer, 108, 108, 108, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if(type >= _smNum + (tenth*10) && type < _smNum + (tenth*11))
      {
        SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*11) && type < _smNum + (tenth*12))
      {
        SDL_SetRenderDrawColor(renderer, 132, 132, 132, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*12) && type < _smNum + (tenth*13))
      {
        SDL_SetRenderDrawColor(renderer, 144, 144, 144, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*13) && type < _smNum + (tenth*14))
      {
        SDL_SetRenderDrawColor(renderer, 156, 156, 156, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*14) && type < _smNum + (tenth*15))
      {
        SDL_SetRenderDrawColor(renderer, 168, 168, 168, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*15) && type < _smNum + (tenth*16))
      {
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*16) && type < _smNum + (tenth*17))
      {
        SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*17) && type < _smNum + (tenth*18))
      {
        SDL_SetRenderDrawColor(renderer, 204, 204, 204, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*18) && type < _smNum + (tenth*19))
      {
        SDL_SetRenderDrawColor(renderer, 216, 216, 216, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (type >= _smNum + (tenth*19))
      {
        SDL_SetRenderDrawColor(renderer, 228, 228, 228, 255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
    }
  }
}
