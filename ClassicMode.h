// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

//this is the game mode that does't count the cells that are outside the 8
//neighhbors, even if they are the border and are 'off grid'

#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "Board.h"
#include "Mode.h"
#include "ReadFile.h"



class ClassicMode: public Mode
{
  public:
    ClassicMode(); //Default constructor
    ~ClassicMode(); //Destructor

    //sets the current board from an external file
    void setFileBoard(string path);
    //creates a random board given user params
    void setRandomBoard(int height, int width, double density);
    //returns current board
    Board* getCurrentBoard();
    //evolves a board by a single generation by the rules of the specific mode
    void evolve(char m, ofstream& o, int g);
    //checks if the boards justify quitting the evolution loop
    bool isDone();

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    Board* m_loopChecker;
    int m_boardHeight;
    int m_boardWidth;


};

#endif
