#include "Board.h"

class Mode
{
  public:
    Mode();
    ~Mode();
    Board evolve();
    bool isDone();

  private:
    Board m_currentGen;
    Board m_nextGen;

};
