// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

#include "MirrorMode.h"

MirrorMode::MirrorMode()
{
  m_boardHeight = 0;
  m_boardWidth = 0;
}

MirrorMode::~MirrorMode()
{
  delete m_currentGen;
  delete m_nextGen;
  delete m_loopChecker;
}

void MirrorMode::setFileBoard(string path)
{
  ReadFile* x = new ReadFile();

  m_currentGen = x->return_board(path);
  m_nextGen = new Board(m_currentGen->getHeight(), m_currentGen->getWidth());
  m_loopChecker = new Board(m_boardHeight, m_boardWidth);

  m_boardHeight = m_currentGen->getHeight();
  m_boardWidth = m_currentGen->getWidth();
}

void MirrorMode::setRandomBoard(int height, int width, double density)
{
  m_boardHeight = height;
  m_boardWidth = width;
  m_currentGen = new Board(m_boardHeight, m_boardWidth);
  m_currentGen->populate(density);
  m_nextGen = new Board(m_boardHeight, m_boardWidth);
  m_loopChecker = new Board(m_boardHeight, m_boardWidth);
}

Board* MirrorMode::getCurrentBoard()
{
  return m_currentGen;
}

void MirrorMode::evolve(char m, ofstream& o, int g)
{

  if (m == 'a' || m == 'm')
  {
    cout << m_currentGen->write();
    cout << endl << endl << endl;
  }
  else if (m == 'o')
  {
    o << m_currentGen->write();
    o << endl << endl << endl;
  }

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

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;


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

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;


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

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;


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

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;


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

        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount += 3;

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

        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i,j+1)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount += 3;


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

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i+1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount += 3;


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

        if (m_currentGen->readAtIndex(i,j-1)=='X') neighborCount++;
        if (m_currentGen->readAtIndex(i-1,j)=='X') neighborCount++;

        if (m_currentGen->readAtIndex(i,j)=='X') neighborCount += 3;


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
  //Switches the current and next boards, allowing check for no movement
  Board* temp = new Board(m_boardHeight, m_boardWidth);
  temp->setArray(m_currentGen->getArray());
  m_currentGen->setArray(m_nextGen->getArray());
  m_nextGen->setArray(temp->getArray());

  //Sets m_loopChecker to next generation only on odd generations
  if (g % 10 == 0)
  {
    m_loopChecker->setArray(m_nextGen->getArray());
  }
  delete temp;
  // cout << "CURRENT:" << endl << m_currentGen->write() << endl;
  // cout << "NEXT:" << endl << m_nextGen->write() << endl;

}

bool MirrorMode::isDone()
{
  if (m_currentGen->isEmpty() || (m_currentGen->isEqual(m_nextGen->getArray())) || (m_currentGen->isEqual(m_loopChecker->getArray())))
  {
    return true;
  }
  else
  {
    return false;
  }
}
