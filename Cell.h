#include "Board.h"

//This class is used to make a Cell object

class Cell
{
  public:
    Cell();
    ~Cell();
    bool is_populated();
    int get_cell_type();
    void set_cell_type(int new_type);
    char get_cell_value();
    void set_cell_value(char new_value);

  private:
    char value;
    int cell_type;

};
