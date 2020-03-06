#include "MirrorMode.h"

MirrorMode::MirrorMode()
{
  cout << "Made Mirror Game!" << endl;
  m_currentGen = new Board();
  m_nextGen = new Board();
}

MirrorMode::~MirrorMode()
{
  //delete m_currentGen;
  //delete m_nextGen;
}

void MirrorMode::evolve()
{

}

bool MirrorMode::isDone()
{

}
