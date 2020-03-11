// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

#include "Game.h"

//This is the driver file for Game of Life. The Game of Life simulates the
//growth of bacteria on a 2d grid.

int main(int argc, char** argv)
{
  // Testing Game Object
  Game* g = new Game();
  g->start();
  delete g;

  return 0;
}
