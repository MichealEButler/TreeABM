#ifndef AGENT_H
#define AGENT_H

#include "World.h"
#include "Object.h"
#include "DrawFunctions.h"
#include "Display.h"
#include <iostream>

using namespace std;

class Agent : public Object
{
protected:

  // allow agents to locate each within simulation space
  Agent **_agents;
  int _noOfAgents;


  int _size;
  int _x;
  int _y;

public:
  Agent();
  Agent(int _id, int x, int y);
  ~Agent();

  void setX(int x);
  void setY(int y);

  int getX();
  int getY();

  void renderAgent();

  // need drawing functions for SDL

  // get access to all agents in the world
  void getAgents(Agent **agents, int size);


private:

};

#endif
