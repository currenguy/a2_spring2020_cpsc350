#include "Board.h"
#include <ctime>

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

void Board:: populate_board(double population_density)
{
  //seeding rand with time
  srand(time(NULL));
  for (int i = 0; i < this->m_height; ++i)
  {
    for (int j = 0; j < this->m_width; ++j)
    {
      double random_double = ((double)rand()/(double)RAND_MAX);
      if (random_double <= population_density) this->m_array[i][j] = 'X';
      else this->m_array[i][j] = '-';
    }
  }
}
