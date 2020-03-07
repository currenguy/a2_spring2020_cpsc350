#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include "Board.h"
#include "Mode.h"
#include "ReadFile.h"

class DoughnutMode: public Mode
{
  public:
    DoughnutMode();
    DoughnutMode(string path);
    ~DoughnutMode();
    void evolve();
    bool isDone();
    Board* getCurrentBoard();

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    int m_boardHeight;
    int m_boardWidth;

};

#endif
