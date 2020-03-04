#include "Board.h"
#include "Mode.h"

class ClassicMode: public Mode
{
  public:
    ClassicMode();
    ~ClassicMode();
    Board evolve();
    bool isDone();

  private:
    Board m_currentGen;
    Board m_nextGen;

};
