// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include "Board.h"
#include "Mode.h"
#include "ReadFile.h"


class DoughnutMode: public Mode
{
  public:
    DoughnutMode();
    ~DoughnutMode();
    void setFileBoard(string path);
    void setRandomBoard(int height, int width, double density);
    Board* getCurrentBoard();
    void evolve(char m, ofstream& o, int g);
    bool isDone();

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    Board* m_loopChecker;
    int m_boardHeight;
    int m_boardWidth;

};

#endif
