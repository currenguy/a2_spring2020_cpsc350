#include "ClassicMode.h"

ClassicMode::ClassicMode(int height, int width, double pop_density)
{

  m_boardHeight = height;
  m_boardWidth = width;

  cout << "Made Classic Game!" << endl;
  m_currentGen = new Board(m_boardHeight, m_boardWidth);
  m_currentGen->populate(pop_density);

  m_nextGen = new Board(m_boardHeight, m_boardWidth);
}

ClassicMode::~ClassicMode()
{
  //delete m_nextGen;
  //delete m_currentGen;
}

void ClassicMode::evolve()
{
  for (int i = 0; i < m_boardHeight; ++i)
  {
    for (int j = 0; j < m_boardWidth; ++j)
    {
      //reset neighboar count for each space
      int neighbor_count = 0;

      if (i == 0 && j != 0 && j != m_boardWidth-1)
      {
        //cout << "Top_middle" << endl;

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }
      else if (i == m_boardHeight-1 && j != 0 && j != m_boardWidth-1)
      {
        //cout << "bottom_middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }
      else if (i > 0 && i < m_boardHeight-1 && j == 0)
      {
        //cout << "left_middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      else if (i > 0 && i < m_boardHeight-1 && j == m_boardWidth-1)
      {
        //cout << "right_middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      else if (i == 0 && j == 0)
      {
        //cout << "top_left_corner" << endl;

        if (m_currentGen->readAtIndex(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }
      else if (i == m_boardHeight-1 && j == 0)
      {
        //cout << "bottom_left_corner" << endl;

        if (m_currentGen->readAtIndex(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }
      else if (i == 0 && j == m_boardWidth-1)
      {
        //cout << "top_right_corner" << endl;

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }
      else if (i == m_boardHeight-1 && j == m_boardWidth-1)
      {
        //cout << "bottom_right_corner" << endl;

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighbor_count++;


        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      else
      {
        //cout << "Middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighbor_count++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighbor_count++;

        if (neighbor_count <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighbor_count == 2) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighbor_count == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->writeAtIndex(i,j,'-');

      }

    }
  }

  m_currentGen->print();
  cout << "----------------" << endl;
  m_nextGen->print();

  m_currentGen->setArray(m_nextGen->getArray());

}

bool ClassicMode::isDone()
{
  if (m_currentGen->isEmpty() || (m_currentGen->isEqual(m_nextGen->getArray())))
  {
    return true;
  }
  else return false;
}
