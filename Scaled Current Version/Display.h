// SDL functions to display at varified points during simulation
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Agent.h"

class Display
{
public:
  Display();
  ~Display();
  void initDisplay(const char* title, int x, int y, int w, int h, bool isShown);
  void handleEvents();
  void updateDisplay();
  void renderDisplay(int state);
  void showPollen(); // shows pollen catchment, and distribution
  void renderPresent();
  void clearRenderer();
  void cleanDisplay();

  void saveImage(SDL_Renderer* renderer, int tick, int currentFile);

  bool running();
  bool cPressed();
  bool initPollen();
  SDL_Renderer* renderer;

private:
  SDL_Window* window;
  SDL_Rect* srcR, destR;
  SDL_RendererInfo rendererInfo;

  bool isCPressed;
  bool isRunning;
  bool isPollen;

};

#endif