#include "utils.h"
#include <stdio.h>

/* rudimentary calculator */
int main()
{
  double sum;
  char line[MAXLINE] = "";

  sum = 0;
  
  while (Getline(line, MAXLINE) > 0)
  {
    printf("\t%g\n", sum += Atof(line));
  }

  return 0;
}
