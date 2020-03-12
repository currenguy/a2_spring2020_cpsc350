// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

//this class contains the board object, which is the main data storage object
//in this assignment

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
    Board(); //Default constructor
    Board(int h, int w); //Overloaded constructor
    ~Board(); //Destructor
    void print(); // Prints the board to cout
    string write(); // Returns a string of the board
    void populate(double density); // Populates board based on density input
    bool isEmpty(); //Checks if board is empty
    void writeAtIndex(int height, int width, char z); //Writes to board
    char readAtIndex(int height, int width); //Reads from board
    void setArray(char** input_array); //Sets this board array to input
    char** getArray(); //Returns the board array
    bool isEqual(char** input_array); //Checks equality of arrays
    void zero(); //Removes all 'X' from an array
    int getHeight(); //Returns the height of the board
    int getWidth(); //Returns the width of the board

  private:
    char** m_array; // 2D array dynamically allocated during runtime
    int m_height;
    int m_width;
};

#endif
