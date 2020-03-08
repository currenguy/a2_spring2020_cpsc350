#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

//This class is used to make a Board object

class Board
{
  public:
    Board();
    Board(int h, int w);
    ~Board();
    void print(); // Prints the board to cout
    string write(); // Writes the board to the input file
    void populate(double density); // Populates board based on density input
    bool isEmpty(); //Checks if board is empty
    void writeAtIndex(int height, int width, char z); //Writes to board
    char readAtIndex(int height, int width); //Reads from board
    void setArray(char** input_array); //Sets this board array to input
    char** getArray(); //Returns the board array
    bool isEqual(char** input_array); //Checks equality of arrays
    void zero(); //Removes all 'X' from an array
    int getHeight();
    int getWidth();

  private:
    char** m_array; // 2D array dynamically allocated during runtime
    int m_height;
    int m_width;
};

#endif
