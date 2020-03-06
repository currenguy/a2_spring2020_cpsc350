#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "Board.h"
#include "Mode.h"

class ClassicMode: public Mode
{
  public:
    ClassicMode(int height, int width, double pop_density);
    ~ClassicMode();
    void evolve();
    bool isDone();

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    int board_height;
    int board_width;

};

#endif
