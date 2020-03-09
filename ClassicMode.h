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
    void evolve(char m, ofstream& o, int g);
    bool isDone();
    void init_current_board_from_file(string path);

  private:
    Board* m_currentGen;
    Board* m_nextGen;
    Board* m_loopChecker;
    int m_boardHeight;
    int m_boardWidth;


};

#endif
