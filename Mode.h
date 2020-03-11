#ifndef MODE_H
#define MODE_H

#include "Board.h"

class Mode
{
  public:
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
