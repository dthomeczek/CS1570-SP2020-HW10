// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: school.cpp
// Purpose: Function definitions for the School class 

#include "school.h"

// Clears the array used for the school
void School::clear()
{
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      school_grid[i][j] = ' ';
    }
  }
  return;
}

// Builds the walls and windows of the school
void School::build(const int num_wind)
{
  const int SUBTRACT = 1; // used to subtract one for walls
  const int FIRST = 0; // first col or row
  int counter_row = 0;
  int counter_col = 0;
  
  for (int i = FIRST; i < school_size; i++)
  {
    for (int j = FIRST; j < school_size; j++)
    {
      if (i == FIRST)
      {
        school_grid[i][j] = '=';
      }
      else if (i == school_size - SUBTRACT) 
      {
        school_grid[i][j] = '=';
      }
      else if (j == FIRST)
      {
        school_grid[i][j] = '=';
      }
      else if (j == school_size - SUBTRACT)
      {
        school_grid[i][j] = '=';
      }
    }
  }
  
  for (int i = FIRST; i < school_size; i++)
  {
    counter_row = FIRST;
    counter_col++;
    for (int j = FIRST; j < school_size; j++)
    {
      counter_row++;
      if (counter_row == num_wind && i == FIRST && j != (school_size - SUBTRACT))
      {
        school_grid[i][j] = '+';
        counter_row = FIRST;
      }
       if (counter_row == num_wind && i == (school_size - SUBTRACT) 
         && j != (school_size - SUBTRACT))
      {
        school_grid[i][j] = '+';
        counter_row = FIRST;
      }
      if (counter_col == num_wind && j == FIRST && i != (school_size - SUBTRACT))
      {
        school_grid[i][j] = '+';
      }
      if (counter_col == num_wind && j == (school_size - SUBTRACT)
        && i != (school_size - SUBTRACT))
      {
        school_grid[i][j] = '+';
        counter_col = FIRST;
      }
    }
  }
  return;
}

// A constructor for the School class
School::School(short arr_size, const int num_wind): school_size(arr_size) 
{
  clear();
  build(num_wind);
}

// Gets the school array size
short School::get_arr()
{
  return school_size;
}

// Overloads the insertion operator for a school
ostream &operator<<(ostream &output, const School &a)
{
  const int START = 0;
  for (int i = START; i < a.school_size; i++)
  {
    for (int j = START; j < a.school_size; j++)
    {
      output << '-' << '-';
    }
    output << '-' << endl;
    for (int j = START; j < a.school_size; j++)
    {
      if (j == START)
      {
        output << '|' << a.school_grid[i][j] << '|';
      }
      else
      {
        output << a.school_grid[i][j] << '|';
      }
    }
    output << endl;
  }
  for (int j = START; j < a.school_size; j++)
    {
      output << '-' << '-';
    }
    output << '-' << endl;
  return output;
}