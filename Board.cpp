#include "Board.h"

//in board: make a fucntion that pulls from file

Board::Board()
{
  m_height = 1;
  m_width = 1;
  this->m_array = new char* [m_height];
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
  for (int i = 0; i < this->m_height; ++i)
  {
    delete[] this->m_array[i];
  }
  delete[] this->m_array;

  cout << "Destructed Board" << endl;
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

string Board::write()
{
  string s = "";
  for (int i = 0; i < this->m_height; ++i)
  {
    for (int j = 0; j < this->m_width; ++j)
    {
      s += this->m_array[i][j];
      s += " ";
    }
    s += '\n';
  }
  return s;
}

void Board:: populate(double density)
{
  //seeding rand with time
  srand(time(NULL));
  int totalCells = this->m_height * this->m_width;
  int cellsToFill = round(totalCells * density);
  int cellsFilled = 0;
  if (density == 1.0)
  {
    for (int i = 0; i < this->m_height; ++i)
    {
      for (int j = 0; j < this->m_width; ++j)
      {
        this->m_array[i][j] = 'X';
      }
    }
  }
  else
  {
    for (int i = 0; i < cellsToFill; ++i)
    {
      int randomRow = rand() % this->m_height;
      int randomColumn = rand() % this->m_width;

      this->m_array[randomRow][randomColumn] = 'X';
    }
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

void Board:: writeAtIndex(int height, int width, char z)
{
  m_array[height][width] = z;
  //cout << "Wrote" << endl;
}

char Board:: readAtIndex(int height, int width)
{
  return m_array[height][width];
  //cout << "read" << endl;
}

void Board::setArray(char** input_array)
{
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      this->m_array[i][j] = input_array[i][j];
    }
  }

}

char** Board::getArray()
{
  return m_array;
}

bool Board:: isEqual(char** input_array)
{
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      if (m_array[i][j] != input_array[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

void Board::zero()
{
  for (int i = 0; i < m_height; ++i)
  {
    for (int j = 0; j < m_width; ++j)
    {
      m_array[i][j] = '-';
    }
  }
}

int Board::getHeight()
{
  return m_height;
}

int Board::getWidth()
{
  return m_width;
}
