#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "Board.h"
#include "Mode.h"

class ClassicMode: public Mode
{
  public:
    ClassicMode(int height, int width, double density);
    ~ClassicMode();
    Board* getCurrentBoard();
    void evolve();
    bool isDone();

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    int m_boardHeight;
    int m_boardWidth;


};

#endif
