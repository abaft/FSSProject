#include <stdio.h>

#include "read.h"
#include "truthtable.h"

int read_truthtable(FILE* f, truthtable* out)
{
  freopen(NULL, "rb", f);

  int states = fgetc(stdin);
  int ins = fgetc(stdin);

  // Always have a big enough buffer
  char* buffer =
    malloc(sizeof(char) * 1<<(states + ins) * (state + ins + states));
  
  char c;
  char* b = buffer;

  for (; (c = (char)fgetc(f)) != EOF; b++)
    *b = c;


  new_truthtable(out, states, ins, b);
}
