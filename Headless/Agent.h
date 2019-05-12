#ifndef AGENT_H
#define AGENT_H

#include "World.h"
#include "Object.h"
#include <iostream>

using namespace std;

class Agent : public Object
{
protected:
  // interal reference to world array
  World *_world;

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

  void getWorld(World *world);
  // get access to all agents in the world
  void getAgents(Agent **agents, int size);


private:

};

#endif
