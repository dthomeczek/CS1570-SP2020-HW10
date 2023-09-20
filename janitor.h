#ifndef JANITOR_H
#define JANITOR_H
// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: janitor.h
// Purpose: Janitor class and Janitor class function prototypes

#include <iostream>
using namespace std;

// The Janitor() creates a janitor object
// Pre: N/A
// Post: A janitor object is created with either a default name and character
// or a chosen name and character

// The get_capt() gets whether the lunch has or hasn't been caught
// Pre: N/A
// Post: Returns capt_lun

// The get_wind() gets whether the janitor has or hasn't fallen out a window
// Pre: N/A
// Post: Returns fell_wind

// The get_alive() gets whether the janitor has or hasn't died
// Pre: N/A
// Post: Returns alive

// The get_bruises() gets the number of bruises the janitor has for that day
// Pre: N/A
// Post: Returns bruises

// The get_sobriety() gets the blood alcohol content of the janitor
// Pre: N/A
// Post: Returns sobriety

// The place_jan() finds and places a janitor into the middle of the school
// Pre: A valid, reference to a constructed school object is required
// Post: A janitor is placed into the school

// The place_traps() randomly places traps throughout the school
// Pre: A valid, reference to a constructed school object is required
// Post: Traps are randomly distributed throughout the school

// The rand_walk() causes the janitor to move intelligently if he's sober,
// or randomly if he is drunk
// Pre: A valid reference to a constructed school, a valid reference to a
// placed lunch object, an array of drinks, and the amount of drinks on the 
// map
// Post: The janitor moves one step in any immediate direction, or fails to
// move if he/she hits a wall

// The operator<<() overloads the insertion operator for the Janitor class
// Pre: A janitor object must exist with all member variables accounted for
// Post: Allows the janitor's stats to be printed through the ostream

class Janitor
{
  private:
    double sobriety;
    int bruises;
    int jan_row;
    int jan_col;
    char jan_symb;
    string jan_name;
    bool sober;
    bool alive;
    bool capt_lun;
    bool fell_wind;

  public:
    Janitor(string name = "Willie", char jan_var = 'J'); 
    bool get_capt();
    bool get_wind();
    bool get_alive();
    int get_bruises();
    double get_sobriety();
    void place_jan(School &a);
    void place_traps(School &a);
    void rand_walk(School &a, Lunch &l, Drink arr[], const int drink_amnt);
    friend ostream & operator<<(ostream & output, const Janitor& j);
};

#endif