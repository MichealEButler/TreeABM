// to compile-> g++ main.cpp Display.cpp World.cpp Tree.cpp -o main -lSDL2 -std=gnu++0x

#include <iostream>
#include <cmath>
#include <ctime>
#include <time.h>
#include <fstream>
#include <SDL2/SDL.h>
#include <vector>
#include "Display.h"
#include "Tree.h"
#include "Patch.h"

using namespace std;

const float PI = 3.14159265358979f;

//Pine
const float b2 = 67.26;
const float b3 = 0.34;
const float HMAX = 35; // m's
const float DMAX = 100; //cm's
const float S = 1;
const float G = 140;
const float c_rate = 0.1;

float getHeight(float DBH);
float expHeight(float DBH);
float growth(float DBH);
float crownRadius(float DBH);
float crownArea(float radius);
float intersectArea(float Ax, float Ay, float Bx, float By, float Ar, float Br);
void fillCircle(SDL_Renderer * renderer, int x, int y, int radius, int color);
void drawCircle(SDL_Renderer * renderer, int x, int y, int radius, int color);
void drawRect(SDL_Renderer * renderer, int x, int y, int width, int height, int color);

Display * display;
vector<Tree*> trees;
Patch **patches;

int main(int argc, char ** argv)
{
  srand(time(NULL));

  display = new Display();
  trees = vector<Tree*>(8);
  patches = new Patch*[400];

  for(int i = 0; i < trees.size(); i++)
  {
    trees[i] = new Tree(i+1);
  }

  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)
    {
      int patchNo = (20 * i) + j;
      patches[patchNo] = new Patch();
      patches[patchNo]->setID(patchNo);
      patches[patchNo]->setX(i);
      patches[patchNo]->setY(j);
      cout << "Patch " << patchNo << " x = " << patches[patchNo]->getX() << " y = " << patches[patchNo]->getY() << endl;
    }
  }

  float Ax, Ay, Bx, By, Ar, Br;

  Ax = 2.0f;
  Ay = 6.0f;
  Bx = 5.0f;
  By = 6.0f;
  Ar = 2.0f;
  Br = 2.0f;

/*
  float radius;
  cout << "Enter Radius: ";
  cin >> radius;
  cout << endl;
  float outArea;
  outArea = crownArea(radius);

  cout << "Crown Area = " << outArea << endl;
*/
  float outint = intersectArea(Ax,Ay,Bx,By,Ar,Br);

  cout << "Intersect area = " << outint << endl;

  display->initDisplay("Light Climate", 0,0,400,400,true);

  while(display->running())
  {
    display->updateDisplay();
    display->renderDisplay();
    for(int i = 0; i < trees.size(); i++)
    {
      trees[i]->resetPatches();
      trees[i]->setNeighbors(trees);
      trees[i]->getDominance();
      drawCircle(display->renderer, (trees[i]->getX())*20, (trees[i]->getY())*20, (trees[i]->getCRadius())*20, 2);
      //fillCircle(display->renderer, (trees[i]->getX())*20, (trees[i]->getY())*20, (trees[i]->getCRadius())*20, 2);
    }

    for(int i = 0; i < 400; i++)
    {
      patches[i]->setTreeCover(trees);
      cout << "Patch " << patches[i]->getX() << " " << patches[i]->getY() << " tree cover = " << patches[i]->getNumCover() << endl;
    }

    for(int i = 0; i < trees.size(); i++)
    {
      if(trees[i]->getDominance() != true)
      {
        for(int j = 0; j < 400; j++)
        {
          if(patches[j]->getNumCover() == 1)
          {
            drawRect(display->renderer, patches[j]->getX()*20, patches[j]->getY()*20, 20, 20, 1);
          }

          if(patches[j]->getX() >= trees[i]->getX() - trees[i]->getCRadius() && patches[j]->getX() < trees[i]->getX() + trees[i]->getCRadius()
            && patches[j]->getY() >= trees[i]->getY() - trees[i]->getCRadius() && patches[j]->getY() < trees[i]->getY() + trees[i]->getCRadius())
            {
              trees[i]->setTCover();
              trees[i]->referencePatches(patches[j]->getNumCover());
            }

            if(patches[j]->getNumCover() > 1)
            {
              drawRect(display->renderer, patches[j]->getX()*20, patches[j]->getY()*20, 20, 20, 3);
            }
          }
        }
      }

    display->renderPresent();
    display->clearRenderer();
    display->handleEvents();
  }

  display->cleanDisplay();

  delete display;

  for(int i = 0; i < trees.size(); i++)
  {
    trees[i]->outData();
    delete trees[i]; // calls each ~Agent()
  }

  for(int i = 0; i < 400; i++)
  {
    delete patches[i];
  }

  return 0;
}

float getHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = 137 + ((b2 * _dbh) - (b3 * (_dbh * _dbh)));

  return currentHeight;
}

float expHeight(float DBH)
{
  float _dbh = DBH;

  float currentHeight = (HMAX * (1 - exp(-(S / HMAX) * DBH)) * 100);

  return currentHeight;
}

float growth(float DBH)
{
  float _dbh = DBH;

  float part1 = G * _dbh;
  float part2 = b2 * _dbh;
  float part3 = (b3 * (_dbh * _dbh));
  float part4 = 137 + part2 - part3;
  float part5 = (_dbh * part4) / (DMAX *(HMAX * 100));
  float part6 = (1 - part5);
  float part7 = part1 * part6;

  float part8 = (3 * (b2 * _dbh));
  float part9 = (4 * (b3 * (_dbh * _dbh)));
  float part10 = 274 + part8 - part9;

  // optimal growth
  float part11 = part7 / part10;

  float currentDBH = _dbh + part11;

  return currentDBH;
}

float crownRadius(float DBH)
{
  float _dbh = DBH;

  float _crownradius = (c_rate * _dbh) / 2;

  return _crownradius;
}

float crownArea(float radius)
{
  float crownArea = PI * (pow(radius, 2));
  return crownArea;
}

float intersectArea(float Ax, float Ay, float Bx, float By, float Ar, float Br)
{
  //taken from https://www.xarg.org/2016/07/calculate-the-intersection-area-of-two-circles/

  float a, b, d, x, z, y;

  d = hypot(Bx - Ax, By - Ay);

  if(d < (Ar + Br))
  {
    a = Ar * Ar;
    b = Br * Br;

    x = (a - b + d * d) / (2 * d);
    z = x * x;
    y = sqrt(a - z);

    if(d < abs(Br - Ar))
    {
      return PI * min(a,b);
    }
    return a * asin(y / Ar) + b * asin(y / Br) - y * (x + sqrt(z + b - a));
  }
  return 0;
}

void fillCircle(SDL_Renderer * renderer, int x, int y, int radius, int color)
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
    case 4:
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

void drawCircle(SDL_Renderer * renderer, int x, int y, int radius, int color)
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
    case 4:
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      break;
    default:
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  }

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

void drawRect(SDL_Renderer * renderer, int x, int y, int width, int height, int color)
{
  int _color = color;

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
    case 4:
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      break;
    default:
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  }

  SDL_RenderDrawLine(renderer, x, y, x+width, y);
  SDL_RenderDrawLine(renderer, x+width, y, x+width, y+height);
  SDL_RenderDrawLine(renderer, x+width, y+height, x, y+height);
  SDL_RenderDrawLine(renderer, x, y+height, x, y);
}
