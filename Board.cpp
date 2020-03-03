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
