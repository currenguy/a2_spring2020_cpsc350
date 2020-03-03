#include "Game.h"

//This class is used to make a Board object

class Board
{
  public:
    void print(); // Prints the board to cout
    void write(string filename); // Writes the board to the input file

  private:
    char** m_array; // 2D array dynamically allocated during runtime
    int m_width;
    int m_height;
};
