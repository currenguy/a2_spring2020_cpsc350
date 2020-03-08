#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "Board.h"
#include "Mode.h"
#include "ReadFile.h"

class ClassicMode: public Mode
{
  public:
    ClassicMode();
    ~ClassicMode();
    void setFileBoard(string path);
    void setRandomBoard(int height, int width, double density);
    Board* getCurrentBoard();
    void evolve();
    bool isDone();
    void init_current_board_from_file(string path);

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    int m_boardHeight;
    int m_boardWidth;


};

#endif
