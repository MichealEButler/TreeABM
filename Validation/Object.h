#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

using namespace std;

class Object
{
protected:
  int id;
public:

  Object(int _id): id(_id) { }

  // all inherited members will have the getID() function
  int getID() { return id; }


  ~Object() {  }
};

#endif
