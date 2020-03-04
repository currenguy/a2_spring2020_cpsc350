// #include "Mode.h"
//#include "MirrorMode.h"
#include "ClassicMode.h"


enum inputMode {INPUT = 1, RANDOM = 2};
enum viewMode {AUTO = 1, MANUAL = 2, OUTPUT = 3};
enum boundMode {CLASSIC = 1, DOUGHNUT = 2, MIRROR = 3};

//This class is used to make a Game object

class Game
{

  public:
    Game();
    ~Game();

    string getInputOptions();
    string getViewOptions();
    string getBoundOptions();

    // 1. Ask if providing a map, or random map (requires w, h, and decimal)
    // 2. Ask for the boundary mode
    // 3. Ask for the viewing mode
    // 4. Run the simulation
    void start();

  private:
    inputMode m_inputMode;
    viewMode m_viewMode;
    boundMode m_boundMode;
    float m_decimal;

};
