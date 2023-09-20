#ifndef SCHOOL_H
#define SCHOOL_H
// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: school.h
// Purpose: School class and School class function prototypes

#include <iostream>
using namespace std;

// The clear() clears the array
// Pre: N/A
// Post: An empty array

// The build() builds walls and windows for the school
// Pre: A positive value for window spacing
// Post: Builds a school with windows spaced accordingly

// The School() creates a school object
// Pre: A positive value for array size and window spacing
// Post: Creates a school object with a 2D array

// The get_arr() gets the array size
// Pre: N/A
// Post: Returns the array size

// The operator<<() overloads the insertion operator for the School class
// Pre: A school object must exist with all member variables accounted for
// Post: Allows for the map of the school to be output via the ostream

class School
{
  private:
    short school_size;
    void clear();
    void build(const int num_wind);
  public:
    static const int MAX = 25;
    char school_grid[MAX][MAX];
    School(short arr_size = MAX, const int num_wind = 4);
    short get_arr();
    friend ostream & operator<<(ostream & output, const School &a);
};

#endif