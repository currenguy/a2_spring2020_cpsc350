#include "Board.h"
#include "Mode.h"

class DoughnutMode: public Mode
{
  public:
    DoughnutMode();
    ~DoughnutMode();
    Board evolve();
    bool isDone();

  private:
    Board m_currentGen;
    Board m_nextGen;

};
