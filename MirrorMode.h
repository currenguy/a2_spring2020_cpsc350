// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 3-11-2020
// Assignment: Game of Life

/* This is the game mode that reflects cells on the edges with themselves,
   in essence simulating a 'mirror' effect. */

#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include "Board.h"
#include "Mode.h"
#include "ReadFile.h"


class MirrorMode: public Mode
{
public:
  //Constructor and Destructor
  MirrorMode();
  ~MirrorMode();

  //Sets the current board from an external file
  void setFileBoard(string path);
  //Creates a random board given user params
  void setRandomBoard(int height, int width, double density);
  //Returns current board
  Board* getCurrentBoard();
  //Evolves a board by a single generation by the rules of the specific mode
  void evolve(char m, ofstream& o, int g);
  //Checks if the boards justify quitting the evolution loop
  bool isDone();

private:
  Board* m_currentGen;
  Board* m_nextGen;
  Board* m_loopChecker;
  int m_boardHeight;
  int m_boardWidth;

};

#endif
