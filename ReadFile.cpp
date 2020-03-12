// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

/* This class makes an object that takes in a path and returns
   a board object from the board design in the file. */

#include "ReadFile.h"

//Constructor
ReadFile:: ReadFile()
{
  m_path = "";
  m_fileBoardHeight = 0;
  m_fileBoardWidth = 0;
}

//Destructor
ReadFile:: ~ReadFile()
{
  delete m_boardToReturn;
}

//Takes in path and returns a board object that
//mirrors that of the one in the file.
Board* ReadFile:: return_board(string path)
{
  //Loop control vars
  string line;
  ifstream myfile;
  myfile.open(path);

  //Check if we can open the file
  if (!myfile.is_open()) {
     perror("Error open");
     exit(EXIT_FAILURE);
  }

  //Board creation variables
  int iterationCount = 0;
  m_fileBoardHeight = 0;
  m_fileBoardWidth = 0;

  //While loop to get every line from file
	while(getline(myfile, line))
  {
    //Use first 2 loops to get size
    if (iterationCount == 0)
    {
      m_fileBoardHeight = stoi(line);
    }
    if (iterationCount == 1)
    {
      m_fileBoardWidth = stoi(line);
      m_boardToReturn = new Board(m_fileBoardHeight, m_fileBoardWidth);
    }
    //Once the empty board is made, index through and clone the occupied cells
    else
    {
      for (int i = 0; i < m_fileBoardWidth; ++i)
      {
        if (line.at(i) == 'X')
        {
          m_boardToReturn->writeAtIndex(iterationCount-2, i, 'X');
        }
      }
    }
    iterationCount++;
	}
  myfile.close();

  return m_boardToReturn;
}
