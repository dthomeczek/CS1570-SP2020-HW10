#ifndef SIMULATION_H
#define SIMULATION_H
// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: simulation.h
// Purpose: Simulation function prototype

#include <unistd.h>
#include <iostream>
using namespace std;

struct results
{
  double m_total_bac;
  int m_total_bruises;
  int m_total_captures;
  int m_total_windows;
  int m_alive;
};

// The simulations() runs a simulation of one day worth of the janitor trying
// to catch the lunch
// Pre: Requires positive values for days, school size, num_drinks, num_traps,
// and windows, and also requires a valid results object
// Post: Returns values

results simulations(const int days, const int school_size, const int num_drinks,
const int num_traps, const int windows, results values);

#endif