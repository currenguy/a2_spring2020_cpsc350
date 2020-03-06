#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//This class is used to make a Board object

class Board
{
  public:
    Board();
    Board(int h, int w);
    ~Board();
    void print(); // Prints the board to cout
    void write(string filename); // Writes the board to the input file
    void populate(double density); // Populates board based on density input
    bool isEmpty(); //Checks if board is empty
    void write_char_at_index(int height, int width, char z);
    char read_char_at_index(int height, int width);
    void set_array(char** input_array);
    char** get_array();
    bool check_for_equality(char** input_array);

  private:
    char** m_array; // 2D array dynamically allocated during runtime
    int m_height;
    int m_width;
};

#endif
