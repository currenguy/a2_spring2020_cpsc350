#include "Cell.h"

//This is the driver file for Game of Life

int main(int argc, char** argv)
{
  Game* g = new Game();
  g->start();

  delete g;

  return 0;
}
