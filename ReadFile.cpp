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
  int height_of_board_in_file = 0;
  int width_of_board_in_file = 0;

	while(getline(myfile, line))
  {
    if (iteration_count == 0)
    {
      cout << line << endl;
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
          cout << "iT " << iteration_count<< endl;
          m_boardToReturn->writeAtIndex(iteration_count-2, i, 'X');
        }
      }
    }
    iteration_count++;
	}

  m_boardToReturn->print();
  return m_boardToReturn;
}
