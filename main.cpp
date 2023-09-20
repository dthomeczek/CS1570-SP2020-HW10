// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/2/2020
// Filename: main.cpp
// Purpose: To have a janitor search for a rogue lunch throughout a school

#include <cstdlib>
#include <fstream>
#include <unistd.h>

#include "school.h"
#include "lunch.h"
#include "drink.h"
#include "janitor.h"
#include "simulation.h"

int main()
{
  srand(time(NULL));
  const int NONE = 0;
  const float FULL_PERC = 100.0;

  results values;
  
  values.m_total_bac = NONE;
  values.m_total_bruises = NONE;
  values.m_total_captures = NONE;
  values.m_total_windows = NONE;
  values.m_alive = NONE;

  int days;
  int school_size;
  int drinks;
  int traps;
  int windows;
  int day_count;

  float avg_bac = NONE;
  float avg_bruise = NONE;
  float perc_capt = NONE;
  float perc_window = NONE;
  float perc_deaths = NONE;

  ifstream fin;
  fin.open("config.dat");
  fin >> days;
  fin >> school_size;
  fin >> drinks;
  fin >> traps;
  fin >> windows;

  do
  {
    values = simulations(day_count, school_size, drinks, traps, windows, values);
    day_count++;
  } while (day_count < days);

  avg_bac = values.m_total_bac / day_count;
  avg_bruise = values.m_total_bruises / static_cast<float>(day_count);
  perc_capt = (values.m_total_captures / static_cast<float>(day_count)) 
  * FULL_PERC;
  perc_window = (values.m_total_windows / static_cast<float>(day_count)) 
  * FULL_PERC;
  perc_deaths = ((static_cast<float>(day_count)) - values.m_alive) / 
  (static_cast<float>(day_count)) * FULL_PERC;

  cout << "Average BAC over " << day_count << " days: " << avg_bac << endl;
  cout << "Average bruises over " << day_count << " days: " << avg_bruise 
  << endl;
  cout << "Percentage of captures over " << day_count << " days: " 
  << perc_capt << "%" << endl;
  cout << "Percentage of window exits over " << day_count << " days: " 
  << perc_window << "%" << endl;
  cout << "Percentage of deaths over " << day_count << " days: " 
  << perc_deaths << "%" << endl;

  return 0;
}