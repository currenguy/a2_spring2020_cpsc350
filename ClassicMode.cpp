#include "ClassicMode.h"

ClassicMode::ClassicMode()
{
  cout << "Made Classic Game!" << endl;
  Board* m_currentGen = new Board();
  Board* m_nextGen = new Board();
}

ClassicMode::~ClassicMode()
{
  //delete m_nextGen;
  //delete m_currentGen;
}

Board ClassicMode::evolve()
{

}

bool ClassicMode::isDone()
{

}
