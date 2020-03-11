// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

#include "MirrorMode.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "ReadFile.h"


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
    string getInputFile();
    string getInputHeight();
    string getInputDensity();

    // 1. Ask if providing a map, or random map (requires w, h, and decimal)
    // 2. Ask for the boundary mode
    // 3. Ask for the viewing mode
    // 4. Run the simulation
    void start();

  private:
    inputMode m_inputMode;
    viewMode m_viewMode;
    boundMode m_boundMode;
    int m_height;
    int m_width;
    float m_density;
    string m_fileName;

};
