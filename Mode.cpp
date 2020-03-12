// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

/* This is an abstract class that ClassicMode, DoughnutMode, and MirrorMode
   all inherit from. It includes mutators and accessors that each game type
   should have and most importantly, an "evolve" function that each subclass
   overloads. */

#include "Mode.h"

Mode::Mode()
{

}

Mode::~Mode()
{

}

void Mode::setFileBoard(string path)
{

}

void Mode::setRandomBoard(int height, int width, double density)
{

}

Board* Mode::getCurrentBoard()
{

}

void Mode::evolve(char m, ofstream& o, int g)
{

}

bool Mode::isDone()
{

}
