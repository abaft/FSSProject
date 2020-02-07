#include <config.h>
#include <stdio.h>

#include "truthtable.h"

  int
main (void)
{
  truthtable t;
  read_truthtable(stdin, &t);
  print_truthtable(&t);
  return 0;
}
