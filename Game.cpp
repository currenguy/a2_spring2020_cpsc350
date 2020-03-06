#include "Game.h"

Game::Game()
{
  m_inputMode = INPUT;
  m_viewMode = AUTO;
  m_boundMode = CLASSIC;
  m_decimal = 0.0;
}

Game::~Game()
{

}

string Game::getInputOptions()
{
  string s = "";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "--- THE GAME OF LIFE ---\n\n";
  s += "Select a map mode, then press [ENTER].\n\n";
  s += "[1] Provide a map\n";
  s += "[2] Generate random map\n";
  s += "\n\n";
  return s;
}

string Game::getViewOptions()
{
  string s = "";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "Select a view mode, then press [ENTER].\n\n";
  s += "[1] Automatic (pauses, then displays next generation)\n";
  s += "[2] Manual (press [ENTER] for next generation)\n";
  s += "[3] File Output (outputs all generations to a file)\n";
  s += "\n\n";
  return s;
}

string Game::getBoundOptions()
{
  string s = "";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "Select a boundary mode, then press [ENTER].\n\n";
  s += "[1] Classic\n";
  s += "[2] Doughnut\n";
  s += "[3] Mirror\n";
  s += "\n\n";
  return s;
}

void Game::start()
{
  int userInput = -1;
  bool isValid = false;
  cout << this->getInputOptions();

  //Asking user if they want to provide a game map
  while (isValid == false)
  {
    cin >> userInput;
    switch (userInput)
    {
      case INPUT:
        this->m_inputMode = INPUT;
        isValid = true;
        break;
      case RANDOM:
        this->m_inputMode = RANDOM;
        isValid = true;
        break;
      default:
        cout << this->getInputOptions() << endl;
        cout << "INVALID INPUT. Try again." << endl;
        break;
    }
  }

  userInput = -1;
  isValid = false;
  cout << this->getBoundOptions();

  //Asking user for a view mode
  while (isValid == false)
  {
    cin >> userInput;
    switch (userInput)
    {
      case CLASSIC:
        this->m_boundMode = CLASSIC;
        isValid = true;
        break;
      case DOUGHNUT:
        this->m_boundMode = DOUGHNUT;
        isValid = true;
        break;
      case MIRROR:
        this->m_boundMode = MIRROR;
        isValid = true;
        break;
      default:
        cout << this->getBoundOptions() << endl;
        cout << "INVALID INPUT. Try again." << endl;
        break;
    }
  }

  userInput = -1;
  isValid = false;
  cout << this->getViewOptions();

  //Asking user for boundary mode
  while (isValid == false)
  {
    cin >> userInput;
    switch (userInput)
    {
      case AUTO:
        this->m_viewMode = AUTO;
        isValid = true;
        break;
      case MANUAL:
        this->m_viewMode = MANUAL;
        isValid = true;
        break;
      case OUTPUT:
        this->m_viewMode = OUTPUT;
        isValid = true;
        break;
      default:
        cout << this->getViewOptions() << endl;
        cout << "INVALID INPUT. Try again." << endl;
        break;
    }
  }

  cout << "Choice: " << this->m_boundMode << endl;

  if (this->m_boundMode == CLASSIC)
  {
    int height = 5;
    int width = 5;
    double pop_density = 0.55;
    ClassicMode* c = new ClassicMode(height,width,pop_density);
    for (int i = 0; i < 5; ++i)
    {
      cout << "Iteration: " << i <<endl;
      c->evolve();
      
    }

    delete c;
  }
  else if (this->m_boundMode == DOUGHNUT)
  {
    DoughnutMode* c = new DoughnutMode();
    delete c;

  }
  else if (this->m_boundMode == MIRROR)
  {
    MirrorMode* c = new MirrorMode();
    delete c;
  }
}
