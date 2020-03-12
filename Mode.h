// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

//this is an abstract class that classicmode, doughnutmode, and mirror mode all inherit
//from, it includes setters and getters that each game type should have
//and most importantly, an "evolve" function that each subclass overloads

#ifndef MODE_H
#define MODE_H

#include "Board.h"

class Mode
{
  public:
    //constructors and destructors
    Mode();
    ~Mode();

    virtual void setFileBoard(string path); //Sets a board from a file
    virtual void setRandomBoard(int height, int width, double density); //Sets a board from random density
    virtual Board* getCurrentBoard(); //Returns the current board
    virtual void evolve(char m, ofstream& o, int g); //Changes current board by one generation
    virtual bool isDone(); //Checks if the board is done changing

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    Board* m_loopChecker;
    int m_boardHeight;
    int m_boardWidth;

};

#endif
