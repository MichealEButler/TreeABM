#include "World.h"

World::World()
{


}
World::~World()
{


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

  for (int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      file >> my_array[i][j];
      world[i][j] = my_array[i][j];
    }
    //cout << endl;
  }

  file.close();

  cout << "Array created! " << endl;

  for (int i = 0; i < 1000; i++) {
    delete[] my_array[i];
  }

  delete[] my_array;
}

void World::renderWorld()
{
  float type;

  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 1000; i++) {
      type = world[j][i];

      if (type >= 150 && type < 165)
      {
        SDL_SetRenderDrawColor(Display::renderer, 0, 0, 0, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 165 && type < 175)
      {
        SDL_SetRenderDrawColor(Display::renderer, 112,128,144, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 175 && type < 190)
      {
        SDL_SetRenderDrawColor(Display::renderer, 119, 136, 153, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 190 && type < 200)
      {
        SDL_SetRenderDrawColor(Display::renderer, 105, 105, 105, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 200 && type < 210)
      {
        SDL_SetRenderDrawColor(Display::renderer, 128, 128, 128, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 210 && type < 225)
      {
        SDL_SetRenderDrawColor(Display::renderer, 169, 169, 169, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 210 && type < 225)
      {
        SDL_SetRenderDrawColor(Display::renderer, 192, 192, 192, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 225 && type < 240)
      {
        SDL_SetRenderDrawColor(Display::renderer, 211, 211, 211, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
      if (type >= 240 && type < 265)
      {
        SDL_SetRenderDrawColor(Display::renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(Display::renderer, i, j);
      }
    }
  }
}
