// Name: Devin Thomeczek, Jared Gardner
// MST Username: djtpfr, jtgx6f
// Section: 101
// Date: 5/6/2020
// Filename: simulation.cpp
// Purpose: Simulation function definitions

#include "school.h"
#include "lunch.h"
#include "drink.h"
#include "janitor.h"
#include "simulation.h"

// Creates a simulated day of the janitor trying to catch the lunch
results simulations(const int days, const int school_size, const int num_drinks,
const int num_traps, const int windows, results values)
{
  const int MAX_DRINKS = 20;
  School sch(school_size, windows);
  Janitor jan("Willie", 'W');
  Lunch lun;
  Drink dri[MAX_DRINKS];
  jan.place_jan(sch);
  lun.place_lun(sch);
  for (int i = 0; i < num_drinks; i++)
  {
    dri[i].place_drink(sch);
  }
  for (int i = 0; i < num_traps; i++)
  {
    jan.place_traps(sch);
  }
  if (days == 0)
  {
    do
    {
      lun.lun_move(sch);
      jan.rand_walk(sch, lun, dri, num_drinks);
      cout << sch << endl;
      usleep(200000);
    } while (jan.get_alive() == true && jan.get_wind() == false && 
    jan.get_capt() == false);
    values.m_total_bac += jan.get_sobriety();
    values.m_total_bruises += jan.get_bruises();
    values.m_total_captures += jan.get_capt();
    values.m_total_windows += jan.get_wind();
    values.m_alive += jan.get_alive();
  }
  else
  {
    do
    {
      lun.lun_move(sch);
      jan.rand_walk(sch, lun, dri, num_drinks);
    } while (jan.get_alive() == true && jan.get_wind() == false && 
    jan.get_capt() == false);
    values.m_total_bac += jan.get_sobriety();
    values.m_total_bruises += jan.get_bruises();
    values.m_total_captures += jan.get_capt();
    values.m_total_windows += jan.get_wind();
    values.m_alive += jan.get_alive();
  }

  return values;
}
