// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

#include "Board.h"

//Default constructor
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

//Overloaded constructor
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

//Destructor
Board::~Board()
{
  for (int i = 0; i < this->m_height; ++i)
  {
    delete[] this->m_array[i];
  }
  delete[] this->m_array;
}

// Prints the board to cout
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

//Returns a string of the board
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

// Populates board based on density input
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

//Checks if board is empty
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

//Writes to board
void Board:: writeAtIndex(int height, int width, char z)
{
  m_array[height][width] = z;
  //cout << "Wrote" << endl;
}

//Reads from board
char Board:: readAtIndex(int height, int width)
{
  return m_array[height][width];
  //cout << "read" << endl;
}

//Sets this board array to input
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

 //Returns the board array
char** Board::getArray()
{
  return m_array;
}

//Checks equality of arrays
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

//Removes all 'X' from an array
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

//Returns the height of the board
int Board::getHeight()
{
  return m_height;
}

//Returns the width of the board
int Board::getWidth()
{
  return m_width;
}
