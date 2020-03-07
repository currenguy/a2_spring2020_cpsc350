#include "ReadFile.h"

ReadFile:: ReadFile()
{

}

ReadFile:: ~ReadFile()
{

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

  int iteration_count = 0;
  //board creation variables
  height_of_board_in_file = 0;
  width_of_board_in_file = 0;

	while(getline(myfile, line))
  {
    if (iteration_count == 0)
    {
      height_of_board_in_file = stoi(line);
    }
    if (iteration_count == 1)
    {
      width_of_board_in_file = stoi(line);
      m_boardToReturn = new Board(height_of_board_in_file, width_of_board_in_file);
    }
    else
    {
      for (int i = 0; i < width_of_board_in_file; ++i)
      {
        if (line.at(i) == 'X')
        {
          m_boardToReturn->writeAtIndex(iteration_count-2, i, 'X');
        }
      }
    }
    iteration_count++;
	}

  return m_boardToReturn;
}
