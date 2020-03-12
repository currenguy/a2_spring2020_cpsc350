// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

/* This is an abstract class that ClassicMode, DoughnutMode, and MirrorMode
   all inherit from. It includes mutators and accessors that each game type
   should have and most importantly, an "evolve" function that each subclass
   overloads. */

#ifndef MODE_H
#define MODE_H

#include "Board.h"

class Mode
{
  public:
    //Constructor and Destructor
    Mode();
    ~Mode();

    //Sets a board from a file
    virtual void setFileBoard(string path);
    //Sets a board from dimensions and a random density
    virtual void setRandomBoard(int height, int width, double density);
    //Returns the current board
    virtual Board* getCurrentBoard();
    //Changes current board by one generation
    virtual void evolve(char m, ofstream& o, int g);
    //Checks if the board is done changing
    virtual bool isDone();

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    Board* m_loopChecker;
    int m_boardHeight;
    int m_boardWidth;

};

#endif
