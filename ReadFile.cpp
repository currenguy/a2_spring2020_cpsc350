#include "ReadFile.h"

ReadFile:: ReadFile()
{
  m_path = "";
  m_fileBoardHeight = 0;
  m_fileBoardWidth = 0;
}

ReadFile:: ~ReadFile()
{
  delete m_boardToReturn;
}

Board* ReadFile:: return_board(string path)
{
  //loop control vars
  string line;
  ifstream myfile;
  myfile.open(path);

  if (!myfile.is_open()) {
     perror("Error open");
     exit(EXIT_FAILURE);
  }

  int iterationCount = 0;
  //board creation variables
  m_fileBoardHeight = 0;
  m_fileBoardWidth = 0;

	while(getline(myfile, line))
  {
    if (iterationCount == 0)
    {
      m_fileBoardHeight = stoi(line);
    }
    if (iterationCount == 1)
    {
      m_fileBoardWidth = stoi(line);
      m_boardToReturn = new Board(m_fileBoardHeight, m_fileBoardWidth);
    }
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
