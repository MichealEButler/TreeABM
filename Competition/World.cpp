#include "World.h"

World::World()
{

}
World::~World()
{


}

void World::loadWorld()
{
  for(int i=0;i<20;i++)
  {
    for(int j=0;j<20;j++)
    {
      world[i][j] = (rand() % 3) + 1;
    }
  }
}

void World::renderWorld(SDL_Renderer* renderer)
{
  float type;

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      type = world[i][j];

      if(type == 1)
      {
        SDL_SetRenderDrawColor(renderer, 36, 36, 36, 255);
        fillRect(renderer, i*20, j*20, 20, 20);
      }
      if (type == 2)
      {
        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        fillRect(renderer, i*20, j*20, 20, 20);
      }
      if (type == 3)
      {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        fillRect(renderer, i*20, j*20, 20, 20);
      }
    }
  }
}

void World::fillRect(SDL_Renderer * renderer, int x, int y, int width, int height)
{
  int x2 = x + width;
  int y2 = y + height;

  if (x < 0) x = 0;
  if(x >= 400) x = 400;
  if (y < 0) y = 0;
  if(y >= 400) y = 400;

  if (x2 < 0) x2 = 0;
  if(x2 >= 400) x2 = 400;
  if (y2 < 0) y2 = 0;
  if(y >= 400) y2 = 400;

  for(int i = x; i < x2; i++)
  {
    for(int j = y; j < y2; j++)
    {
      SDL_RenderDrawPoint(renderer, i, j);
    }
  }
}
