#include "DoughnutMode.h"

DoughnutMode::DoughnutMode()
{
  cout << "Made Doughnut Game!" << endl;
  Board* m_currentGen = new Board();
  Board* m_nextGen = new Board();
}

DoughnutMode::~DoughnutMode()
{
  //delete m_currentGen;
  //delete m_nextGen;
}

Board DoughnutMode::evolve()
{

}

bool DoughnutMode::isDone()
{

}
