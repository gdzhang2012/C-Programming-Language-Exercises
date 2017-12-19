#include "utils.h"
#include <stdio.h>

double expand_atof(char s[]);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: expand_atof <string>\n");

    return -1;
  }

  //printf("The number: %f\n", Atof(argv[1]));
  printf("The number: %f\n", expand_atof(argv[1]));

  return 0;
}

/* Atof: convert strings to double */
double expand_atof(char s[])
{
  double val, power;
  int i, sign;

  /* skip white space */
  for (i = 0; isspace(s[i]); i++)
  {
    //do nothing
  }

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
  {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.')
  {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++)
  {
     val = 10.0 * val + (s[i] - '0');
     power = 10.0 * power;
  }

  if (s[i] == 'e' || s[i] == 'E')
  {
    if (s[++i] = '-')
    {
      power = power * (10.0 * (s[++i] - '0'));
    }
    else
    {
      //TODO
    }
  }

  return sign * val / power;
}
