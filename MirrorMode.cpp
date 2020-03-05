#include "MirrorMode.h"

MirrorMode::MirrorMode()
{
  cout << "Made Mirror Game!" << endl;
  Board* m_currentGen = new Board();
  Board* m_nextGen = new Board();
}

MirrorMode::~MirrorMode()
{
  //delete m_currentGen;
  //delete m_nextGen;
}

Board MirrorMode::evolve()
{

}

bool MirrorMode::isDone()
{

}
