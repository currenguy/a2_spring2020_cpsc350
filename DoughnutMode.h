#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include "Board.h"
#include "Mode.h"

class DoughnutMode: public Mode
{
  public:
    DoughnutMode();
    ~DoughnutMode();
    void evolve();
    bool isDone();

  private:
    Board* m_currentGen;
    Board* m_nextGen;

};

#endif
