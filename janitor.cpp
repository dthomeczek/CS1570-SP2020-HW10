// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: janitor.cpp
// Purpose: Function definitions for the Janitor class

#include "school.h"
#include "lunch.h"
#include "drink.h"
#include "janitor.h"

// A constructor for the Janitor class
Janitor::Janitor(string name, char jan_var):jan_symb(jan_var), jan_name(name)
{
  sobriety = 0.05;
  bruises = 0;
  sober = true;
  alive = true;
  jan_row = -1;
  jan_col = -1;
  capt_lun = false;
  fell_wind = false;
}

// Gets whether the lunch has or hasn't been caught by the janitor
bool Janitor::get_capt()
{
  return capt_lun;
}

// Gets whether the janitor has or hasn't fallen out the window
bool Janitor::get_wind()
{
  return fell_wind;
}

// Gets whether the janitor is alive or not
bool Janitor::get_alive()
{
  return alive;
}

// Gets the number of bruises for a given day
int Janitor::get_bruises()
{
  return bruises;
}

// Gets the blood alcohol content of the janitor for a given day
double Janitor::get_sobriety()
{
  return sobriety;
}

// Places the janitor in the middle of the school
void Janitor::place_jan(School &a)
{
  int cord;

  cord = a.get_arr() / 2;
  if (jan_row == -1 && jan_col == -1 && a.school_grid[cord][cord] == ' ')
  {
    cord = a.get_arr() / 2;
    jan_row = cord;
    jan_col = cord;
  }
  else if (jan_row == -1 && jan_col == -1 && a.school_grid[cord][cord] != ' ')
  {
    a.school_grid[cord][cord + 1] = ' ';
    jan_row = cord;
    jan_col = cord + 1;
  }
  
  a.school_grid[jan_row][jan_col] = jan_symb;

  return;
}

// Places traps throughout the school
void Janitor::place_traps(School &a)
{
  int rand_row;
  int rand_col;

  do
  {
    rand_row = (rand() % (a.get_arr() - 2) + 1);
    rand_col = (rand() % (a.get_arr() - 2) + 1);
  } while (a.school_grid[rand_row][rand_col] != ' ');

  a.school_grid[rand_row][rand_col] = 'T';

  return;
}

// Moves the janitor in any direction depending on sobriety and whether there
// is a wall or not
void Janitor::rand_walk(School &a, Lunch &l, Drink arr[], const int drink_amnt)
{
  const int MOVE = 1;
  const int NEG_MOVE = -1;
  int dir;
  int row;
  int col;
  int new_row;
  int new_col;
  int l_row;
  int l_col;

  if (sobriety >= 0.08)
  {
    sober = false;
  }
  else
  {
    sober = true;
  }
  
  new_row = 0;
  new_col = 0;
  row = 0;
  col = 0;
  if (sober != true)
  {
    dir = (rand() % 8);
    
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
    new_row = jan_row + row;
    new_col = jan_col + col;

    if (a.school_grid[new_row][new_col] == 'L')
    {
      a.school_grid[jan_row][jan_col] = ' ';
      jan_row = new_row;
      jan_col = new_col;
      capt_lun = true;
    }
    else if (a.school_grid[new_row][new_col] == 'T')
    {
      a.school_grid[jan_row][jan_col] = ' ';
      jan_row = new_row;
      jan_col = new_col;
      bruises += 5;
    }
    else if (a.school_grid[new_row][new_col] == '+')
    {
      fell_wind = true;
    }
    else if (a.school_grid[new_row][new_col] == 'D')
    {
      for (int i = 0; i < drink_amnt; i++)
      {
        if (arr[i].drink_row == new_row && arr[i].drink_col == new_col)
        {
          float bac;
          bac = arr[i].get_effect();
          a.school_grid[jan_row][jan_col] = ' ';
          jan_row = new_row;
          jan_col = new_col;
          sobriety = bac + sobriety;
          if (sobriety >= 0.25)
          {
            alive = false;
          } 
        }
      }
    }
    
    else if (a.school_grid[new_row][new_col] != ' ')
    {
      jan_col = jan_col;
      jan_row = jan_row;
      bruises += 1;
    }
    else
    {
      a.school_grid[jan_row][jan_col] = ' ';
      jan_row = new_row;
      jan_col = new_col;
    }
  } 
  else // if janitor is sober
  {
    l_col = l.get_col();
    l_row = l.get_row();

    if (jan_row < l_row) // if l_row is greater
    {
      if (jan_col < l_col)
      {
        row = MOVE;
        col = MOVE;
      }
      else if (jan_col > l_col)
      {
        row = MOVE;
        col = NEG_MOVE;
      }
      else if (jan_col == l_col)
      {
        row = MOVE;
      }
    }
    else if (jan_row > l_row) // if jan_row is greater
    {
      if (jan_col < l_col)
      {
        row = NEG_MOVE;
        col = MOVE;
      }
      else if (jan_col > l_col)
      {
        row = NEG_MOVE;
        col = NEG_MOVE;
      }
      else if (jan_col == l_col)
      {
        row = NEG_MOVE;
      }
    }
    else if (jan_row == l_row) // if rows are equal
    {
      if (jan_col < l_col)
      {
        col = MOVE;
      }
      else if (jan_col > l_col)
      {
        col = NEG_MOVE;
      }
    }

    new_row = jan_row + row;
    new_col = jan_col + col;

    if (a.school_grid[new_row][new_col] == 'T')
    {
      a.school_grid[jan_row][jan_col] = ' ';
      jan_row = new_row;
      jan_col = new_col;
      bruises += 5;
    }
    else if (a.school_grid[new_row][new_col] == 'L')
    {
      capt_lun = true;
      a.school_grid[jan_row][jan_col] = ' ';
      jan_row = new_row;
      jan_col = new_col;
    }
    else if (a.school_grid[new_row][new_col] == 'D')
    {
      for (int i = 0; i < drink_amnt; i++)
      {
        if (arr[i].drink_row == new_row && arr[i].drink_col == new_col)
        {
          float bac;
          bac = arr[i].get_effect();
          a.school_grid[jan_row][jan_col] = ' ';
          jan_row = new_row;
          jan_col = new_col;
          sobriety = bac + sobriety;
          if (sobriety >= 0.25)
          {
            alive = false;
          }
        }
      } 
    }
    else
    {
      a.school_grid[jan_row][jan_col] = ' ';
      jan_row = new_row;
      jan_col = new_col;
    }
  }
  
  a.school_grid[jan_row][jan_col] = jan_symb;

  return;
}

// Overloads the insertion operator to print the janitor's stats
ostream& operator<<(ostream& output, const Janitor& j)
{
  string sob;
  string aliv;
  sob = (j.sober == true) ? "True":"False";
  aliv = (j.alive == true) ? "True":"False";
  output << "Name: " << j.jan_name << endl;
  output << "Rep Char: " << j.jan_symb << endl;
  output << "BAC: " << j.sobriety << endl;
  output << "Brusises: " << j.bruises << endl;
  output << "Location: (" << j.jan_col << "," << j.jan_row << ")" << endl;
  output << "Sober: " << sob;
  output << endl;
  output << "Alive: " << aliv;
  return output;
}