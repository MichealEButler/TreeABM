#include "Display.h"
#include "World.h"

using namespace std;

World *world = nullptr;

Display::Display()
{
    world = new World();
    world->loadWorld();
}

Display::~Display()
{

}

void Display::initDisplay(const char* title, int x, int y, int w, int h, bool isShown)
{

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
    if (e.key.keysym.sym == SDLK_SPACE)
    {
      isSpace = true;
    }
  }

  if(e.type == SDL_KEYUP)
  {
    if (e.key.keysym.sym == SDLK_SPACE)
    {
      isSpace = false;
    }
  }

  if (e.type == SDL_QUIT)
  {
    isRunning = false;
  }
}

void Display::updateDisplay()
{

}

void Display::clearRenderer()
{
  SDL_RenderClear(renderer);
}

void Display::renderDisplay()
{

  world->renderWorld(renderer);
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

bool Display::space()
{
  return isSpace;
}
