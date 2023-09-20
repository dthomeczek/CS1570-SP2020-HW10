// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: lunch.cpp
// Purpose: Function definitions for the Lunch class

#include "school.h"
#include "lunch.h"

// A constructor for the Lunch class
Lunch::Lunch(int lun_r, int lun_c, bool trap): 
  lun_row(lun_r),lun_col(lun_c), trapped(trap)
{
  lun_char = 'L';
}

// Gets the row value of the lunch
int Lunch::get_row()
{
  return lun_row;
}

// Gets the column value of the lunch
int Lunch::get_col()
{
  return lun_col;
}

// Randomly places the lunch in the school
void Lunch::place_lun(School &a)
{
  int rand_row;
  int rand_col;
  
  do
  {
    rand_row = (rand() % (a.get_arr() - 2) + 1);
    rand_col = (rand() % (a.get_arr() - 2) + 1);
  } while (a.school_grid[rand_row][rand_col] != ' ');
  lun_row = rand_row;
  lun_col = rand_col;
  
  a.school_grid[lun_row][lun_col] = lun_char;
  
  return;
}

// Randomly moves the lunch
void Lunch::lun_move(School &a)
{
  const int MOVE = 1;
  const int NEG_MOVE = -1;
  int dir;
  int row;
  int col;
  int new_row;
  int new_col;
  bool no_move;

  if (trapped != true)
  {
    dir = (rand() % 8);
    new_row = 0;
    new_col = 0;
    row = 0;
    col = 0;
    no_move = false;

    switch (dir)
    {
      case 0:
        row = NEG_MOVE;
        break;

      case 1:
        row = NEG_MOVE;
        col = MOVE;
        break;

      case 2:
        col = MOVE;
        break;

      case 3:
        row = MOVE;
        col = MOVE;
        break;

      case 4:
        row = MOVE;
        break;

      case 5:
        row = MOVE;
        col = NEG_MOVE;
        break;

      case 6:
        col = NEG_MOVE;
        break;

      case 7:
        col = NEG_MOVE;
        row = NEG_MOVE;
        break;
    }
    new_row = lun_row + row;
    new_col = lun_col + col;

    if (a.school_grid[new_row][new_col] == 'T')
    {
      a.school_grid[lun_row][lun_col] = ' ';
      lun_row = new_row;
      lun_col = new_col;
      trapped = true;
    }
    else if ((a.school_grid[new_row][new_col] != ' '))
    {
      no_move = true;
    }
    else
    {
      a.school_grid[lun_row][lun_col] = ' ';
      lun_row = new_row;
      lun_col = new_col;
    }
  }
  else
  {
    no_move = true;
  }
  
  if (no_move != true)
  {
    a.school_grid[lun_row][lun_col] = lun_char;
  }

  return;
}