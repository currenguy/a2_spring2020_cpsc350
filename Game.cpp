// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

#include "Game.h"

//Inits the vars needed for play
Game::Game()
{
  m_inputMode = INPUT;
  m_viewMode = AUTO;
  m_boundMode = CLASSIC;
  m_height = 0;
  m_width = 0;
  m_density = 0.0;
  m_fileName = "";
}

//Destructor
Game::~Game()
{

}

//Prints input options
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

//Prints view options
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

//Prints boandary options
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

//Prints input file options
string Game::getInputFile()
{
  string s = "";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "Type an input file name, then press [ENTER]: ";
  return s;
}

//Prints height options
string Game::getInputHeight()
{
  string s = "";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "Type the board height, then press [ENTER]: ";
  return s;
}

//Prints density options
string Game::getInputDensity()
{
  string s = "";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "\n\n\n\n";
  s += "Type the board density (0,1], then press [ENTER]: ";
  return s;
}

//Starts the game
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

  string userFile = "";
  isValid = false;
  cout << this->getInputFile();

  //Asking user for board input file
  if (userInput == INPUT)
  {
    ifstream myFile;
    while (isValid == false)
    {
      cin >> userFile;
      myFile.open(userFile);
      if (myFile.is_open())
      {
        isValid = true;
      }
      else
      {
        cout << "INVALID FILE. Type an input file name, then press [ENTER]: ";
      }
    }
    myFile.close();
  }

  //Asking user for random board settings
  else if (userInput == RANDOM)
  {
    cout << this->getInputHeight();
    while (isValid == false)
    {
      cin >> userInput;
      if (userInput > 0)
      {
        isValid = true;
        this->m_height = userInput;
      }
      else
      {
        cout << "INVALID INPUT. Type the board height, then press [ENTER]: ";
      }
    }

    isValid = false;
    userInput = -1;
    cout << "Type the board width, then press [ENTER]: ";
    while (isValid == false)
    {
      cin >> userInput;
      if (userInput > 0)
      {
        isValid = true;
        this->m_width = userInput;
      }
      else
      {
        cout << "INVALID INPUT. Type the board height, then press [ENTER]: ";
      }
    }

    isValid = false;
    double userDensity = 0.0;
    cout << "Type the board density (0,1], then press [ENTER]: ";
    while (isValid == false)
    {
      cin >> userDensity;
      if (userDensity > 0 && userDensity <= 1)
      {
        isValid = true;
        this->m_density = userDensity;
      }
      else
      {
        cout << "INVALID INPUT. Type the board density (0,1], then press [ENTER]: ";
      }
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

  //initializes modes based on choices
  if (this->m_boundMode == CLASSIC)
  {
    ClassicMode* c = new ClassicMode();

    if (m_inputMode == INPUT)
    {
      c->setFileBoard(userFile);
    }

    else if (m_inputMode == RANDOM)
    {
      c->setRandomBoard(m_height, m_width, m_density);
    }

    cout << endl << endl << endl;
    cout << "Simulation Started" << endl << endl;

    int gen = 0;
    ofstream outFile;
    outFile.open("output.txt");
    while (!c->isDone() && gen < 2000)
    {
      if (m_viewMode == AUTO)
      {
        cout << "Generation " << gen << endl;
        c->evolve('a', outFile, gen);
        ++gen;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
      else if (m_viewMode == MANUAL)
      {
        cout << "Generation " << gen << " (Press [ENTER] to continue)" << endl;
        c->evolve('m', outFile, gen);
        ++gen;
        cin.ignore();
      }
      else if (m_viewMode == OUTPUT)
      {
        outFile << "Generation " << gen << endl;
        c->evolve('o', outFile, gen);
        ++gen;
      }
    }

    //Outputs the final generation to output or file
    if (m_viewMode == AUTO || m_viewMode == MANUAL)
    {
      cout << "Generation " << gen << endl;
      cout << c->getCurrentBoard()->write();
      cout << endl << endl << "Simulation Finished" << endl;
    }
    else if (m_viewMode == OUTPUT)
    {
      outFile << "Generation " << gen << endl;
      outFile << c->getCurrentBoard()->write();
      cout << endl << endl << "Simulation Finished" << endl << endl;
      cout << "Contents written to \"output.txt\"" << endl << endl;
    }
    outFile.close();
    delete c;
  }
  //Initializes to doughnut mode based on choices
  else if (this->m_boundMode == DOUGHNUT)
  {
    DoughnutMode* c = new DoughnutMode();

    if (m_inputMode == INPUT)
    {
      c->setFileBoard(userFile);
    }

    else if (m_inputMode == RANDOM)
    {
      c->setRandomBoard(m_height, m_width, m_density);
    }

    cout << endl << endl << endl;
    cout << "Simulation Started" << endl << endl;

    int gen = 0;
    ofstream outFile;
    outFile.open("output.txt");
    while (!c->isDone() && gen < 2000)
    {
      if (m_viewMode == AUTO)
      {
        cout << "Generation " << gen << endl;
        c->evolve('a', outFile, gen);
        ++gen;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
      else if (m_viewMode == MANUAL)
      {
        cout << "Generation " << gen << " (Press [ENTER] to continue)" << endl;
        c->evolve('m', outFile, gen);
        ++gen;
        cin.ignore();
      }
      else if (m_viewMode == OUTPUT)
      {
        outFile << "Generation " << gen << endl;
        c->evolve('o', outFile, gen);
        ++gen;
      }
    }

    //Outputs the final generation to output or file
    if (m_viewMode == AUTO || m_viewMode == MANUAL)
    {
      cout << "Generation " << gen << endl;
      cout << c->getCurrentBoard()->write();
      cout << endl << endl << "Simulation Finished" << endl;
    }
    else if (m_viewMode == OUTPUT)
    {
      outFile << "Generation " << gen << endl;
      outFile << c->getCurrentBoard()->write();
      cout << endl << endl << "Simulation Finished" << endl << endl;
      cout << "Contents written to \"output.txt\"" << endl << endl;
    }
    outFile.close();
    delete c;
  }
  //Initializes to mirror mode based on choices
  else if (this->m_boundMode == MIRROR)
  {
    {
      MirrorMode* c = new MirrorMode();

      if (m_inputMode == INPUT)
      {
        c->setFileBoard(userFile);
      }

      else if (m_inputMode == RANDOM)
      {
        c->setRandomBoard(m_height, m_width, m_density);
      }

      cout << endl << endl << endl;
      cout << "Simulation Started" << endl << endl;

      int gen = 0;
      ofstream outFile;
      outFile.open("output.txt");
      while (!c->isDone() && gen < 2000)
      {
        if (m_viewMode == AUTO)
        {
          cout << "Generation " << gen << endl;
          c->evolve('a', outFile, gen);
          ++gen;
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        else if (m_viewMode == MANUAL)
        {
          cout << "Generation " << gen << " (Press [ENTER] to continue)" << endl;
          c->evolve('m', outFile, gen);
          ++gen;
          cin.ignore();
        }
        else if (m_viewMode == OUTPUT)
        {
          outFile << "Generation " << gen << endl;
          c->evolve('o', outFile, gen);
          ++gen;
        }
      }

      //Outputs the final generation to output or file
      if (m_viewMode == AUTO || m_viewMode == MANUAL)
      {
        cout << "Generation " << gen << endl;
        cout << c->getCurrentBoard()->write();
        cout << endl << endl << "Simulation Finished" << endl;
      }
      else if (m_viewMode == OUTPUT)
      {
        outFile << "Generation " << gen << endl;
        outFile << c->getCurrentBoard()->write();
        cout << endl << endl << "Simulation Finished" << endl << endl;
        cout << "Contents written to \"output.txt\"" << endl << endl;
      }
      outFile.close();
      delete c;
    }
  }
}
