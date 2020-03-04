#include "Board.h"
#include "Mode.h"

class MirrorMode: public Mode
{
  public:
    MirrorMode();
    ~MirrorMode();
    Board evolve();
    bool isDone();

  private:
    Board m_currentGen;
    Board m_nextGen;

};
