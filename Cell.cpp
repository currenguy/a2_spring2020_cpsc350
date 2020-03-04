#include "Cell.h"

Cell::Cell()
{
  char value = '-';
  int cell_type = 1;
}

Cell::~Cell()
{

}

bool Cell::is_populated()
{
  if (value == '-') return false;
  else return true;
}

int Cell::get_cell_type()
{
  return cell_type;
}
void Cell::set_cell_type(int new_type)
{
  cell_type = new_type;
}

char Cell::get_cell_value()
{
  return value;
}

void Cell::set_cell_value(char new_value)
{
  value = new_value;
}

/*
complete cell class, variblaes, method, accessors, getters setters
add cell code to board class
*/
