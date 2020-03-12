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

//allows us to use number options to correspond to game options
enum inputMode {INPUT = 1, RANDOM = 2};
enum viewMode {AUTO = 1, MANUAL = 2, OUTPUT = 3};
enum boundMode {CLASSIC = 1, DOUGHNUT = 2, MIRROR = 3};

class Game
{

  public:
    //constructors and destructors
    Game();
    ~Game();

    //methods for printing the
    //input option
    //view option
    //boundary/mode option
    //file to read from option
    //board height
    //density option
    string getInputOptions();
    string getViewOptions();
    string getBoundOptions();
    string getInputFile();
    string getInputHeight();
    string getInputDensity();
    //begins the while loop where the game
    //is played
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
