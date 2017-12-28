#include "utils.h"
#include <stdio.h>
#include <ctype.h>

static double _Atof(char s[]);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: atof_expand <string>\n");
    
    return -1;
  }

  printf("The result: %f\n", _Atof(argv[1]));

  return 0;
}

/* _Atof: convert strings to double, support scientific notation */
static double _Atof(char s[])
{
  double val, power;
  int i, sign, exp;

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

  val = sign * val / power;

  printf("s[%d]: %c\n", i, s[i]);
  if (s[i] == 'e' || s[i] == 'E')
  {
    sign = (s[++i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+')
    {
     i++; 
    }

    for (exp = 0; isdigit(s[i]); i++)
    {
      exp = 10 * exp + (s[i] - '0'); 
      printf("exp: %d\n", exp);
    }

    printf("sign: %d\n", sign);
    if (sign == -1)
    {
      while (exp-- > 0)
      {
        val = val / 10;
      }
    }
    else
    {
      while (exp-- > 0)
      {
        val = val * 10;
      }
    }
  }

  printf("[%s] [line %d] val: %f\n", __FUNCTION__, __LINE__, val);
  return val;
}
