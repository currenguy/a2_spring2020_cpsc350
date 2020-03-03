#include "Cell.h"

//This is the driver file for Game of Life

int main(int argc, char** argv)
{
  //Testing Game Object
  // Game* g = new Game();
  // g->start();
  // delete g;

  //Testing Board Object
  Board* b = new Board(7, 7);
  b->populate_board(0.1);
  b->print();
  delete b;

  return 0;
}
