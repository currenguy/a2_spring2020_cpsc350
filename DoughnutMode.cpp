#include "DoughnutMode.h"

DoughnutMode::DoughnutMode()
{
  cout << "Made Doughnut Game!" << endl;
  Board* m_currentGen = new Board();
  Board* m_nextGen = new Board();
}

DoughnutMode::DoughnutMode(string path)
{
  cout << "Made Doughnut Game!" << endl;
  ReadFile* x = new ReadFile();

  m_currentGen = x->return_board(path);
  m_nextGen = new Board(m_currentGen->getHeight(), m_currentGen->getWidth());

  m_boardHeight = m_currentGen->getHeight();
  m_boardWidth = m_currentGen->getWidth();
}

DoughnutMode::~DoughnutMode()
{
  //delete m_currentGen;
  //delete m_nextGen;
}

void DoughnutMode::evolve()
{
  this->m_currentGen->print();
  cout << endl << endl << "----------------" << endl << endl;
  for (int i = 0; i < m_boardHeight; ++i)
  {
    for (int j = 0; j < m_boardWidth; ++j)
    {
      //reset neighboar count for each space
      int neighborCount = 0;

      //This is for top middle cells
      if (i == 0 && j != 0 && j != m_boardWidth-1)
      {
        //cout << "Top_middle" << endl;

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(m_boardHeight-1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(m_boardHeight-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(m_boardHeight-1,j+1)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This is for bottom middle cells
      else if (i == m_boardHeight-1 && j != 0 && j != m_boardWidth-1)
      {
        //cout << "bottom_middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(0,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(0,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(0,j+1)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This is for left middle cells
      else if (i > 0 && i < m_boardHeight-1 && j == 0)
      {
        //cout << "left_middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i-1,m_boardWidth-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,m_boardWidth-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,m_boardWidth-1)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This is for right middle cells
      else if (i > 0 && i < m_boardHeight-1 && j == m_boardWidth-1)
      {
        //cout << "right_middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i-1,0)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,0)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,0)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This is for top left corner cell
      else if (i == 0 && j == 0)
      {
        //cout << "top_left_corner" << endl;

        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i,m_boardWidth-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,m_boardWidth-1)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(m_boardHeight-1,0)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(m_boardHeight-1,1)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(m_boardHeight-1,m_boardWidth-1)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This for bottom left corner cell
      else if (i == m_boardHeight-1 && j == 0)
      {
        //cout << "bottom_left_corner" << endl;

        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i, m_boardWidth-1) =='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1, m_boardWidth-1) =='X') neighborCount++;

        if (m_currentGen->readAtIndex(0, 0) =='X') neighborCount++;
        if (m_currentGen->readAtIndex(0, 1) =='X') neighborCount++;

        if (m_currentGen->readAtIndex(0,m_boardWidth-1)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This is for top right corner cell
      else if (i == 0 && j == m_boardWidth-1)
      {
        //cout << "top_right_corner" << endl;

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(m_boardHeight-1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(m_boardHeight-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(m_boardHeight-1,0)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(0,0)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(1,0)=='X') neighborCount++;


        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      //This is for bottom right corner cell
      else if (i == m_boardHeight-1 && j == m_boardWidth-1)
      {
        //cout << "bottom_right_corner" << endl;

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i,0)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,0)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(0,0)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(0,m_boardWidth-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(0,m_boardWidth-2)=='X') neighborCount++;

        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2 ) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');
      }

      else
      {
        //cout << "Middle" << endl;

        if (m_currentGen->readAtIndex(i-1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j+1)=='X') neighborCount++;

        if (neighborCount <= 1) m_nextGen->writeAtIndex(i,j,'-');
        if (neighborCount == 2) m_nextGen->writeAtIndex(i,j, m_currentGen->readAtIndex(i,j));
        if (neighborCount == 3) m_nextGen->writeAtIndex(i,j,'X');
        if (neighborCount >= 4) m_nextGen->writeAtIndex(i,j,'-');

      }
    }
  }

  m_currentGen->setArray(m_nextGen->getArray());
  m_nextGen->zero();
}

bool DoughnutMode::isDone()
{
  if (m_currentGen->isEmpty() || (m_currentGen->isEqual(m_nextGen->getArray())))
  {
    return true;
  }
  else
  {
    return false;
  }
}

Board* DoughnutMode::getCurrentBoard()
{
  return m_currentGen;
}
