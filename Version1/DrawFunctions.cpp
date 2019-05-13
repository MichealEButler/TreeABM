#include "DrawFunctions.h"

DrawFunctions::DrawFunctions()
{

}

DrawFunctions::~DrawFunctions()
{

}

void DrawFunctions::drawCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
  int x0 = 0;
  int y0 = radius;
  int d = 3 - 2 * radius;
  if(!radius) return;

  while(y0 >= x0)
  {
    SDL_RenderDrawPoint(renderer, x - x0, y - y0);
    SDL_RenderDrawPoint(renderer, x - y0, y - x0);
    SDL_RenderDrawPoint(renderer, x + y0, y - x0);
    SDL_RenderDrawPoint(renderer, x + x0, y - y0);
    SDL_RenderDrawPoint(renderer, x - x0, y + y0);
    SDL_RenderDrawPoint(renderer, x - y0, y + x0);
    SDL_RenderDrawPoint(renderer, x + y0, y + x0);
    SDL_RenderDrawPoint(renderer, x + x0, y + y0);
    if(d < 0) d += 4 * x0++ + 6;
    else d+= 4 * (x0++ - y0--) + 10;
  }
}

void DrawFunctions::fillCircle(SDL_Renderer * renderer, int x, int y, int radius, int color)
{
  int _color = color;
  int x0 = 0;
  int y0 = radius;
  int d = 3 - 2 * radius;
  if(!radius) return;

  switch(_color){
    case 1:
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      break;
    case 2:
      SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
      break;
    case 3:
      SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
      break;
    default:
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  }

  auto drawline = [&](int sx, int ex, int ny)
  {
    for (int i = sx; i < ex; i++)
      SDL_RenderDrawPoint(renderer, i, ny);
  };

  while(y0 >= x0)
  {
    drawline(x - x0, x + x0, y - y0);
    drawline(x - y0, x + y0, y - x0);
    drawline(x - x0, x + x0, y + y0);
    drawline(x - y0, x + y0, y + x0);
    if(d < 0) d += 4 * x0++ + 6;
    else d+= 4 * (x0++ - y0--) + 10;
  }
}

void DrawFunctions::drawRect(SDL_Renderer * renderer, int x, int y, int width, int height)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderDrawLine(renderer, x, y, x+width, y);
  SDL_RenderDrawLine(renderer, x+width, y, x+width, y+height);
  SDL_RenderDrawLine(renderer, x+width, y+height, x, y+height);
  SDL_RenderDrawLine(renderer, x, y+height, x, y);
}
