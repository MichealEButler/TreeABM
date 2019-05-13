#include "World.h"

World::World()
{
  df = new DrawFunctions();

}
World::~World()
{


}

void World::loadWorld(const char* fileName)
{
  for(int i=0;i<100;i++)
  {
    for(int j=0;j<100;j++)
    {
      world[i][j] = (rand() % 3) + 1;
    }
  }
}

void World::renderWorld(SDL_Renderer* renderer)
{
  float type;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      type = world[i][j];

      if(type == 1)
      {
        SDL_SetRenderDrawColor(renderer, 36, 36, 36, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type == 2)
      {
        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type == 3)
      {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        df->fillRect(renderer, i*8, j*8, 8, 8);
      }
    }
  }
}
