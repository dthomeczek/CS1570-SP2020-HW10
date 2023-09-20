// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: drink.cpp
// Purpose: Function definitions for the Drink class

#include "school.h"
#include "drink.h"

// A constructor for the Drink class
Drink::Drink()
{
  int num;
  num = (rand() % 2);
  if (num == 0)
  {
    effect = static_cast<float>((rand() % 10) + 1) / -1000.0;
    description = "coffee";
  }
  else
  {
    effect = static_cast<float>((rand() % 5) + 5) / 100.0;
    description = "whiskey";
  }
}

// Places the drink on the map
void Drink::place_drink(School &a)
{
  int rand_row;
  int rand_col;

  do
  {
    rand_row = (rand() % (a.get_arr() - 2) + 1);
    rand_col = (rand() % (a.get_arr() - 2) + 1);
  } while (a.school_grid[rand_row][rand_col] != ' ');

  drink_row = rand_row;
  drink_col = rand_col;

  a.school_grid[rand_row][rand_col] = 'D';

  return;
}

// Used to get the effect in other functions outside the drink class
float Drink::get_effect()
{
  return effect;
}