#include <stdlib.h>
#include <stdio.h>
#include "truthtable.h"


int
new_truthtable(truthtable* out, int states, int ins, char* bytes)
{
  if (out == NULL)
    return 1;

  out->states = states;
  out->ins = ins;
  size_t max_number_of_rows = 1<<(states + ins);

  // Probably wise to set a sensible cap on the size of truthtables 
  out->table = malloc(sizeof(char*) * max_number_of_rows);
  char** p = out->table;
  
  for (int i = 0; i < max_number_of_rows; ++i, ++p)
    *p = malloc(sizeof(char*) * states + ins + states);

  p = out->table - 1;

  int i = 0;
  for (char* c = bytes; *c != 0; ++c)
  {
    int col = i%(states + ins + states);
    if (!col)
      *(++p) = malloc(sizeof(char) * states + ins + states);
    ++i;

    (*p)[col] = *c - 1;
  }

  out->rows = (p + 1) - out->table;
  //out->table = realloc(out->table, sizeof(char*) * out->rows);
}

int
print_truthtable(truthtable* t)
{

  printf("%i things and %i\n", t->states, t->ins);
  for(int i = 0; i < 1<<(t->states + t->ins); ++i)
  {
    printf("| ");
    for(int j = 0; j < t->states + t->ins + t->states; ++j)
    {
      printf("%i |", t->table[i][j]);
      if (j == t->states - 1 || j == t->states + t->ins - 1)
        printf("| ");
      else
        printf(" ");

    }
    printf("\n");
  }
}

int read_truthtable(FILE* f, truthtable* out)
{
  freopen(NULL, "rb", f);

  int states = fgetc(stdin);
  int ins = fgetc(stdin);

  // Always have a big enough buffer
  char* buffer =
    malloc(sizeof(char) * (1<<(states + ins) * (states + ins + states) + 1));
  
  char c;
  char* b = buffer;

  for (; (c = (char)fgetc(f)) != EOF; b++)
    *b = c + 1;
  *b = 0;


  new_truthtable(out, states, ins, buffer);
}

unsigned int
row_to_unit(const truthtable* t, int row)
{
  int size = t->states + t->rows;
  unsigned int final = 0;
  for(int i = 0; i < size; ++i)
  {
    if(t->table[row][i])
      final += 1<<i;
  }
  return final;
}
