#ifndef DRINK_H
#define DRINK_H
// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: drink.h
// Purpose: Drink class and Drink class function prototypes

#include <iostream>
using namespace std;

// The Drink() creates a drink object
// Pre: N/A
// Post: Creates a drink object

// The place_drink() places drinks into the school
// Pre: A valid, reference to a constructed school object is required
// Post: Places drinks on the school map

// The get_effect() gets the effect of a given drink on the map
// Pre: N/A
// Post: Returns the drink effect

class Drink
{
  private:
    string description;
    float effect;
  public:
    Drink();
    void place_drink(School &a);
    float get_effect();
    int drink_row;
    int drink_col;
};

#endif