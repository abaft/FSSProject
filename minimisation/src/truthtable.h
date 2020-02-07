#ifndef _TRUTHTABLE_H__
#define _TRUTHTABLE_H__

typedef struct 
{
  int states;
  int ins;
  char** table;
  size_t rows;
}
truthtable;

int
new_truthtable(truthtable* out, int states, int ins, char* things);

int
print_truthtable(truthtable* t);

int
read_truthtable(FILE* f, truthtable* out);

unsigned int
row_to_unit(const truthtable* t, int row);

#endif
