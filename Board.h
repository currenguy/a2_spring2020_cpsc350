#include "Game.h"

//This class is used to make a Board object

class Board
{
  public:
    Board();
    Board(int h, int w);
    ~Board();
    void print(); // Prints the board to cout
    void write(string filename); // Writes the board to the input file
    void populate_board(double population_density); // Populates board based on density input
    bool is_empty(); //Checks if board is empty

  private:
    char** m_array; // 2D array dynamically allocated during runtime
    int m_height;
    int m_width;

};
