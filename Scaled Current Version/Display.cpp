#include "Display.h"
#include "World.h"

using namespace std;

//SDL_Renderer* renderer = nullptr;
DrawFunctions * drawFunctions = nullptr;
World *world1 = nullptr;

Display::Display()
{
    world1 = new World();
    drawFunctions = new DrawFunctions();
    isPollen = false;

    //world->loadWorld("Input/testDEM.txt");
    //world->loadWorld("Input/slope_7204.txt");
    world1->loadHeight("Input/height2.txt");
    world1->loadSlope("Input/slope2.txt");
    world1->loadSoil("Input/soil2.txt");
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

void Display::showPollen()
{
  // this runs prior to the simulation LOOP


}

void Display::renderDisplay(int state)
{

  //SDL_RenderClear(renderer); // this was removed as display was recoloring everytime agents were being drawn
/*  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, i , j);
    }
  }
*/

  switch(state) {
    case 1:
      world1->renderHeight(renderer);
      break;
    case 2:
      world1->renderSlope(renderer);
      break;
    case 3:
      world1->renderSoil(renderer);
      break;
    default:
      cout << "Failed to load world file! " << endl;
    }
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

  delete world1;

  cout << "Display cleaned . . . " << endl << endl;
}

void Display::saveImage(SDL_Renderer* renderer, int tick, int currentFile)
{
  const Uint32 format = SDL_PIXELFORMAT_ARGB8888;
  const int width = 800;
  const int height = 800;
  string _tick = to_string(tick);
  string _currentFile = to_string(currentFile);
  string folder = "Output/";
  string subfolder = "M";
  string cFolder = "/";
  string nTick = "Tick-";
  string _format = ".bmp";
  string filename = folder + subfolder + _currentFile + cFolder + nTick + _tick + _format;
  const char* cfilename = filename.c_str();

  //SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
  SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32,0,0,0,0);
  SDL_RenderReadPixels(renderer, NULL, format, surface->pixels, surface->pitch);
  SDL_SaveBMP(surface, cfilename);
  SDL_FreeSurface(surface);
}

bool Display::running()
{
  return isRunning;
}

bool Display::cPressed()
{
  return isCPressed;
}

bool Display::initPollen()
{
  return isPollen;
}