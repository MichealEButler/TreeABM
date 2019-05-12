#include "Agent.h"

DrawFunctions * drawFunctionsAgent = nullptr;

Agent::Agent(): Object(-1)
{

}

Agent::Agent(int _id, int x, int y) : Object(_id)
{

  x = _x = rand() % 1000;
  y = _y = rand() % 1000;
  //cout << "Agent created! " << endl;
  //cout << "x = " << x << ", y = " << y << endl;
  //cout << "x = " << _x << ", y = " << _y << endl;

}

Agent::~Agent()
{
  //_world = NULL;
  _agents = NULL;
  //cout << "Agent destroyed! " << endl; //add ID to this function
}

void Agent::setX(int x)
{
  _x = x;
}

void Agent::setY(int y)
{
  _y = y;
}

int Agent::getX()
{
  return _x;
}

int Agent::getY()
{
  return _y;
}

void Agent::renderAgent()
{
  drawFunctionsAgent = new DrawFunctions();

  drawFunctionsAgent->fillCircle(Display::renderer,_x,_y,10,1);
}

void Agent::getAgents(Agent **agents, int size)
{
  _noOfAgents = size;
  _agents = agents;
}
