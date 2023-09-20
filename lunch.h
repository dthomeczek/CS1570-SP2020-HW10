#ifndef LUNCH_H
#define LUNCH_H
// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: lunch.h
// Purpose: Lunch class and Lunch class function prototypes

#include <iostream>
using namespace std;

// The Lunch() creates a lunch object
// Pre: N/A
// Post: Creates a lunch object with default coordinates of (-1, -1) and
// trapped status of false

// The get_row() gets the row value of the lunch
// Pre: Lunch must be in the school
// Post: Returns lun_row

// The get_col() gets the col value of the lunch
// Pre: Lunch must be in the school
// Post: Returns lun_col

// The place_lun() randomly places a lunch object within the school
// Pre: A valid, reference to a constructed school object is required
// Post: Randomly places the lunch in the school

// The lun_move() randomly moves the lunch
// Pre: A valid, reference to a constructed school object is required
// Post: Moves the lunch depending on whether it is trapped or if it tries
// moving into another object other than a trap

class Lunch
{
  private:
    int lun_row;
    int lun_col;
    char lun_char;
    bool trapped;

  public:
    Lunch(int lun_r = -1, int lun_c = -1, bool trap = false);
    int get_row();
    int get_col();
    void place_lun(School &a);
    void lun_move(School &a);
};

#endif