#include "Game.h"

//This is the driver file for Game of Life

int main(int argc, char** argv)
{

  //fix the array setting value cause it's broken
  ReadFile* read_ob = new ReadFile();
  cout << read_ob->return_board("./test.txt") << endl;

  //
  // Board* b = new Board(5, 5);
  // b->populate(0.5);
  // b->print();
  //
  // Board* c = new Board(5, 5);
  // c->print();
  //
  //
  //
  // cout << c->read_char_at_index(2,3) << endl;

  // Testing Game Object
  //Game* g = new Game();
  //g->start();
  //delete g;

  //Testing Board Object
  /*
  Board* b = new Board(5, 5);
  b->populate(0.5);
  b->print();
  cout << b->isEmpty()<< endl;
  delete b;
  */

  return 0;
}
