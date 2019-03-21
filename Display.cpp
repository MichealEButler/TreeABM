#include "Display.h"
#include "DrawFunctions.h"
#include "World.h"

using namespace std;

SDL_Renderer* Display::renderer = nullptr;
DrawFunctions * drawFunctions = nullptr;
World * world = nullptr;

Display::Display()
{
    world = new World();
    drawFunctions = new DrawFunctions();

    //world->loadWorld("Input/testDEM.txt");
    //world->loadWorld("Input/slope_7204.txt");
    world->loadWorld("Input/nz7204_DTM_1M.txt");
}

Display::~Display()
{

}

void Display::initDisplay(const char* title, int x, int y, int w, int h, bool isShown)
{

  isCPressed = false;

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    cout << endl << "Display initialised . . . " << endl;

    window = SDL_CreateWindow(title, x, y , w, h, SDL_WINDOW_SHOWN);
    if(window)
    {
      cout << "Window created . . . " << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer)
    {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      cout << "Renderer created . . . " << endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

}

void Display::handleEvents()
{
  SDL_Event e;

  SDL_PollEvent(&e);

  if(e.type == SDL_KEYDOWN)
  {
    if (e.key.keysym.sym == SDLK_RETURN)
    {
      isRunning = false;
    }

    if (e.key.keysym.sym == SDLK_c)
    {
      isCPressed = true;
    }

    if (e.key.keysym.sym == SDLK_x)
    {
      isCPressed = false;
    }
  }

  if (e.type == SDL_QUIT)
  {
    isRunning = false;
  }
}

void Display::updateDisplay()
{
  //  drawFunctions->fillCircle(renderer,500,500,10);
//  SDL_RenderPresent(renderer);
}

void Display::clearRenderer()
{
  SDL_RenderClear(renderer);
}

void Display::renderDisplay()
{

  //SDL_RenderClear(renderer); // this was removed as display was recoloring everytime agents were being drawn
/*  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, i , j);
    }
  }
*/
  world->renderWorld(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

}

void Display::renderPresent()
{
  SDL_RenderPresent(renderer);
}

void Display::cleanDisplay()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  delete world;

  cout << "Display cleaned . . . " << endl << endl;
}

bool Display::running()
{
  return isRunning;
}

bool Display::cPressed()
{
  return isCPressed;
}
