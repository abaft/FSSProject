#include "truthtable.h"

char* minimise(const truthtable* t)
{
  for(int i = 0; i < t->states; ++i)
    min_state(t, i);
}

int min_state(const truthtable* t, int state)
{
  // Implementation of QM algorithm
  int num_vars = t->states + t->ins;

  int num_minterms = 0;
  int num_dontcare = 0;

  char** dontcare = malloc(sizeof(char*) * t->rows);
  char** minterms = malloc(sizeof(char*) * t->rows);
  char** dcp = dontcare;
  char** mtp = minterms;

  for(int i = 0; i < t->rows; ++i)
    if(t->table[i][states + ins + state + 1])
    {
      num_minterms++;
      *mtp = t->table[i];
      mtp++;
      //Check don't care
      if(t->table[i][states + ins + state + 1] - 1)
      {
        *dcp = t->table[i];
        dcp++;
        ++num_dontcare;
      }

      //number of ones
      t->table[i][states + ins + state + 1] = 0;
      for (int j = 0; j < states + ins; ++j)
        ++t->table[i][states + ins + state + 1];
    }
}
