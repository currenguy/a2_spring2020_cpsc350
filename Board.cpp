#include "Board.h"

Board::Board()
{
  m_height = 1;
  m_width = 1;
  m_array = new char* [m_height];
  for (int i = 0; i < m_height; ++i)
  {
    m_array[i] = new char[m_width];
    for (int j = 0; j < m_width; ++j)
    {
      m_array[i][j] = '-';
    }
  }
}

Board::Board(int h, int w)
{
  m_height = h;
  m_width = w;
  m_array = new char* [m_height];
  for (int i = 0; i < m_height; ++i)
  {
    m_array[i] = new char[m_width];
    for (int j = 0; j < m_width; ++j)
    {
      m_array[i][j] = '-';
    }
  }
}

Board::~Board()
{

}

void Board::print()
{
  for (int i = 0; i < this->m_height; ++i)
  {
    for (int j = 0; j < this->m_width; ++j)
    {
      cout << this->m_array[i][j] << " ";
    }
    cout << endl;
  }
}

void Board:: populate(double density)
{
  //seeding rand with time
  srand(time(NULL));
  int totalCells = this->m_height * this->m_width;
  int cellsToFill = round(totalCells * density);
  int cellsFilled = 0;

  for (int i = 0; i < cellsToFill; ++i)
  {
    int randomRow = rand() % this->m_height;
    int randomColumn = rand() % this->m_width;

    this->m_array[randomRow][randomColumn] = 'X';
  }
}

bool Board:: isEmpty()
{
  int populated_cell_count = 0;
  for (int i = 0; i < this->m_height; ++i)
  {
    for (int j = 0; j < this->m_width; ++j)
    {
      if (this->m_array[i][j] == 'X') populated_cell_count++;
    }
  }
  if (populated_cell_count == 0) return true;
  else return false;
}
