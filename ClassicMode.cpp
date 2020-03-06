#include "ClassicMode.h"

ClassicMode::ClassicMode(int height, int width, double pop_density)
{
  cout << "Made Classic Game!" << endl;
  m_currentGen = new Board(height, width);
  m_currentGen->populate(pop_density);
  m_currentGen->print();
  m_nextGen = new Board(height, width);
  m_nextGen->write_char_at_index(3,3,'X');
  m_nextGen->print();
}

ClassicMode::~ClassicMode()
{
  //delete m_nextGen;
  //delete m_currentGen;
}

void ClassicMode::evolve()
{
  m_nextGen->print();
  cout << "printed!" << endl;

  m_nextGen->write_char_at_index(3,3,'X');

  m_nextGen->print();
}

bool ClassicMode::isDone()
{

}
