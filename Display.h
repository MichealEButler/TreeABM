// SDL functions to display at varified points during simulation
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "World.h"
#include "Agent.h"

class Display
{
public:
  Display();
  ~Display();
  void initDisplay(const char* title, int x, int y, int w, int h, bool isShown);
  void handleEvents();
  void updateDisplay();
  void renderDisplay();
  void cleanDisplay();

  bool running();

  static SDL_Renderer* renderer;
private:
  SDL_Window* window;
  SDL_RendererInfo rendererInfo;

  bool isRunning;

};

#endif
