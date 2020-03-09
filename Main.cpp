#include "Game.h"

//This is the driver file for Game of Life

int main(int argc, char** argv)
{


  // Board* b = new Board(5, 5);
  // b->writeAtIndex(0, 0, 'X');
  // b->print();
  //
  //
  //
  // cout << endl << endl;
  //
  //
  //
  // Board* c = new Board(5, 5);
  // c->writeAtIndex(0, 0, 'X');
  // c->print();
  //
  //
  //
  // cout << "EQUAL? : " << b->isEqual(c->getArray()) << endl;
  //
  // delete b;
  // delete c;




  // ClassicMode* c = new ClassicMode();
  // c->setFileBoard("test.txt");
  //
  // cout << endl << endl << endl;
  // cout << "Simulation Started" << endl << endl;
  //
  //
  // ofstream outFile;
  // int gen = 0;
  // while (!c->isDone())
  // {
  //   cout << "Generation " << gen << endl;
  //   c->evolve('a', outFile, gen);
  //   ++gen;
  //   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  // }
  //
  // cout << "Generation " << gen << endl;
  // cout << c->getCurrentBoard()->write();
  // cout << endl << endl << "Simulation Finished" << endl;








  // Testing Game Object
  Game* g = new Game();
  g->start();
  delete g;



  return 0;
}
