#include "ClassicMode.h"

ClassicMode::ClassicMode(int height, int width, double pop_density)
{

  board_height = height;
  board_width = width;

  cout << "Made Classic Game!" << endl;
  m_currentGen = new Board(height, width);
  m_currentGen->populate(pop_density);

  m_nextGen = new Board(height, width);
}

ClassicMode::~ClassicMode()
{
  //delete m_nextGen;
  //delete m_currentGen;
}

void ClassicMode::evolve()
{
  for (int i = 0; i < board_height; ++i)
  {
    for (int j = 0; j < board_width; ++j)
    {
      //reset neighboar count for each space
      int neighbor_count = 0;

      if (i == 0 && j != 0 && j != board_width-1)
      {
        cout << "Top_middle" << endl;

        if (m_currentGen->read_char_at_index(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j+1)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }
      else if (i == board_height-1 && j != 0 && j != board_width-1)
      {
        cout << "bottom_middle" << endl;

        if (m_currentGen->read_char_at_index(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j+1)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }
      else if (i > 0 && i < board_height-1 && j == 0)
      {
        cout << "left_middle" << endl;

        if (m_currentGen->read_char_at_index(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j+1)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }

      else if (i > 0 && i < board_height-1 && j == board_width-1)
      {
        cout << "right_middle" << endl;

        if (m_currentGen->read_char_at_index(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }

      else if (i == 0 && j == 0)
      {
        cout << "top_left_corner" << endl;

        if (m_currentGen->read_char_at_index(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }
      else if (i == board_height-1 && j == 0)
      {
        cout << "bottom_left_corner" << endl;

        if (m_currentGen->read_char_at_index(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }
      else if (i == 0 && j == board_width-1)
      {
        cout << "top_right_corner" << endl;

        if (m_currentGen->read_char_at_index(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }
      else if (i == board_height-1 && j == board_width-1)
      {
        cout << "bottom_right_corner" << endl;

        if (m_currentGen->read_char_at_index(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');
      }

      else
      {
        cout << "Middle" << endl;

        if (m_currentGen->read_char_at_index(i-1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i-1,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i,j+1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j-1)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j)=='X') neighbor_count++;
        if (m_currentGen->read_char_at_index(i+1,j+1)=='X') neighbor_count++;

        cout << neighbor_count << endl;

        if (neighbor_count <= 1) m_nextGen->write_char_at_index(i,j,'-');
        if (neighbor_count == 2) ;
        if (neighbor_count == 3) m_nextGen->write_char_at_index(i,j,'X');
        if (neighbor_count >= 4) m_nextGen->write_char_at_index(i,j,'-');

      }

    }
  }

  m_currentGen->print();
  cout << "----------------" << endl;
  m_nextGen->print();

  m_currentGen = m_nextGen;
}

bool ClassicMode::isDone()
{

}
