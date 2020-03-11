#include "Game.h"

//This is the driver file for Game of Life

int main(int argc, char** argv)
{
  // Testing Game Object
  Game* g = new Game();
  g->start();
  delete g;

  return 0;
}
