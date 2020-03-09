#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include "Board.h"
#include "Mode.h"
#include "ReadFile.h"


class MirrorMode: public Mode
{
public:
  MirrorMode();
  ~MirrorMode();
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
