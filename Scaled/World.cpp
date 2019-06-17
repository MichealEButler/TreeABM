#include "World.h"

World::World()
{
  df = new DrawFunctions();

}
World::~World()
{


}

float World::getLNumH()
{
  return _lNumH;
}

float World::getSmNumH()
{
  return _smNumH;
}

float World::getLNumS()
{
  return _lNumS;
}

float World::getSmNumS()
{
  return _smNumS;
}

void World::loadHeight(const char* fileName)
{
  string line;
  ifstream file (fileName);
  file.is_open();

  float **my_array;
  my_array = new float*[100];

  for (int i = 0; i < 100; i++) {
    my_array[i] = new float[100];
  }

  _lNumH = height[0][0];

  for (int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      file >> my_array[i][j];
      if(height[i][j] >= 0)
      {
        height[i][j] = my_array[i][j];
      } else {
        height[i][j] = 0;
      }
      if(_lNumH < height[i][j])
      {
        _lNumH = height[i][j];
      }
    }
    //cout << endl;
  }

  _smNumH = _lNumH;

  for (int i = 0; i < 100; i++)
  {
    for(int j = 0; j < 100; j++)
    {
      if(_smNumH > height[i][j] && height[i][j] >= 0)
      {
        _smNumH = height[i][j];
      }
    }
  }

  file.close();

  cout << "Array created! " << endl;

  for (int i = 0; i < 100; i++) {
    delete[] my_array[i];
  }

  delete[] my_array;
}

void World::loadSlope(const char* fileName)
{
  string line;
  ifstream file (fileName);
  file.is_open();

  float **my_array;
  my_array = new float*[100];

  for (int i = 0; i < 100; i++) {
    my_array[i] = new float[100];
  }

  _lNumS = slope[0][0];

  for (int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      file >> my_array[i][j];
      if(slope[i][j] >= 0)
      {
        slope[i][j] = my_array[i][j];
      } else {
        slope[i][j] = 0;
      }
      if(_lNumS < slope[i][j])
      {
        _lNumS = slope[i][j];
      }
    }
    //cout << endl;
  }

  _smNumS = _lNumS;

  for (int i = 0; i < 100; i++)
  {
    for(int j = 0; j < 100; j++)
    {
      if(_smNumS > slope[i][j] && slope[i][j] >= 0)
      {
        _smNumS = slope[i][j];
      }
    }
  }

  file.close();

  cout << "Array created! " << endl;

  for (int i = 0; i < 100; i++) {
    delete[] my_array[i];
  }

  delete[] my_array;
}

void World::renderHeight(SDL_Renderer* renderer)
{
  float type;

  float range = _lNumH - _smNumH;
  float tenth = range / 20;

  for (int j = 0; j < 100; j++) {
    for (int i = 0; i < 100; i++) {
      type = height[j][i];

      if(type < _smNumH + tenth)
      {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + tenth && type < _smNumH + (tenth*2))
      {
        SDL_SetRenderDrawColor(renderer, 12, 12, 12, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*2) && type < _smNumH + (tenth*3))
      {
        SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*3) && type < _smNumH + (tenth*4))
      {
        SDL_SetRenderDrawColor(renderer, 36, 36, 36, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*4) && type < _smNumH + (tenth*5))
      {
        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*5) && type < _smNumH + (tenth*6))
      {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*6) && type < _smNumH + (tenth*7))
      {
        SDL_SetRenderDrawColor(renderer, 72, 72, 72, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*7) && type < _smNumH + (tenth*8))
      {
        SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*8) && type < _smNumH + (tenth*9))
      {
        SDL_SetRenderDrawColor(renderer, 96, 96, 96, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*9) && type < _smNumH + (tenth*10))
      {
        SDL_SetRenderDrawColor(renderer, 108, 108, 108, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if(type >= _smNumH + (tenth*10) && type < _smNumH + (tenth*11))
      {
        SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*11) && type < _smNumH + (tenth*12))
      {
        SDL_SetRenderDrawColor(renderer, 132, 132, 132, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*12) && type < _smNumH + (tenth*13))
      {
        SDL_SetRenderDrawColor(renderer, 144, 144, 144, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*13) && type < _smNumH + (tenth*14))
      {
        SDL_SetRenderDrawColor(renderer, 156, 156, 156, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*14) && type < _smNumH + (tenth*15))
      {
        SDL_SetRenderDrawColor(renderer, 168, 168, 168, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*15) && type < _smNumH + (tenth*16))
      {
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*16) && type < _smNumH + (tenth*17))
      {
        SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*17) && type < _smNumH + (tenth*18))
      {
        SDL_SetRenderDrawColor(renderer, 204, 204, 204, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*18) && type < _smNumH + (tenth*19))
      {
        SDL_SetRenderDrawColor(renderer, 216, 216, 216, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumH + (tenth*19))
      {
        SDL_SetRenderDrawColor(renderer, 228, 228, 228, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
    }
  }
}

void World::renderSlope(SDL_Renderer* renderer)
{
  float type;

  float range = _lNumH - _smNumH;
  float tenth = range / 20;

  for (int j = 0; j < 100; j++) {
    for (int i = 0; i < 100; i++) {
      type = slope[j][i];

      if(type < _smNumS + tenth)
      {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + tenth && type < _smNumS + (tenth*2))
      {
        SDL_SetRenderDrawColor(renderer, 12, 12, 12, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*2) && type < _smNumS + (tenth*3))
      {
        SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*3) && type < _smNumS + (tenth*4))
      {
        SDL_SetRenderDrawColor(renderer, 36, 36, 36, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*4) && type < _smNumS + (tenth*5))
      {
        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*5) && type < _smNumS + (tenth*6))
      {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*6) && type < _smNumS + (tenth*7))
      {
        SDL_SetRenderDrawColor(renderer, 72, 72, 72, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*7) && type < _smNumS + (tenth*8))
      {
        SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*8) && type < _smNumS + (tenth*9))
      {
        SDL_SetRenderDrawColor(renderer, 96, 96, 96, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*9) && type < _smNumS + (tenth*10))
      {
        SDL_SetRenderDrawColor(renderer, 108, 108, 108, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if(type >= _smNumS + (tenth*10) && type < _smNumS + (tenth*11))
      {
        SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*11) && type < _smNumS + (tenth*12))
      {
        SDL_SetRenderDrawColor(renderer, 132, 132, 132, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*12) && type < _smNumS + (tenth*13))
      {
        SDL_SetRenderDrawColor(renderer, 144, 144, 144, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*13) && type < _smNumS + (tenth*14))
      {
        SDL_SetRenderDrawColor(renderer, 156, 156, 156, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*14) && type < _smNumS + (tenth*15))
      {
        SDL_SetRenderDrawColor(renderer, 168, 168, 168, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*15) && type < _smNumS + (tenth*16))
      {
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*16) && type < _smNumS + (tenth*17))
      {
        SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*17) && type < _smNumS + (tenth*18))
      {
        SDL_SetRenderDrawColor(renderer, 204, 204, 204, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*18) && type < _smNumS + (tenth*19))
      {
        SDL_SetRenderDrawColor(renderer, 216, 216, 216, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type >= _smNumS + (tenth*19))
      {
        SDL_SetRenderDrawColor(renderer, 228, 228, 228, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
    }
  }
}

float World::getElevation(int x, int y)
{
  return height[y][x];
}

float World::getSlope(int x, int y)
{
  return slope[y][x];
}
