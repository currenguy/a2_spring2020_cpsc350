#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"

using namespace std;

class ReadFile
{
  public:
    ReadFile();
    ~ReadFile();
    Board* return_board(string path);

  private:
    string m_path;
    Board* m_boardToReturn;
    int height_of_board_in_file;
    int width_of_board_in_file;
};

#endif
