#include "Board.h"

class Mode
{
  public:
    Mode();
    ~Mode();
    virtual Board evolve();
    virtual bool isDone();

  private:
    Board m_currentGen;
    Board m_nextGen;

};
