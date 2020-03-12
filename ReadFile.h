// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

/* This class makes an object that takes in a path and returns
   a board object from the board design in the file. */

#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"

using namespace std;

class ReadFile
{
  public:
    //Constructors and Destructors
    ReadFile();
    ~ReadFile();

    //Takes in path and returns a board object that
    //mirrors that of the one in the file.
    Board* return_board(string path);

  private:
    string m_path;
    Board* m_boardToReturn;
    int m_fileBoardHeight;
    int m_fileBoardWidth;
};

#endif
