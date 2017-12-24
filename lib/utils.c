#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int Input_bufp = 0;
char Input_buf[BUFSIZE];

/*get_line: get line into s, return length*/
int Getline(char s[], int lim)
{
  int c, i;

  i = 0;

  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }
  if(c == '\n')
  {
    s[i++] = c;
  }
  s[i] = '\0';

  return i;
}

/* get next character */
int getch(void)
{
  return (Input_bufp > 0) ? Input_buf[--Input_bufp] : getchar();
}

/* push character back */
void ungetch(int c)
{
  if(Input_bufp >= BUFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    Input_buf[Input_bufp++] = c;
  }
}

/* Atof: convert strings to double */
double Atof(char s[])
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

  return sign * val / power;
}

/* Atoi: convert string s to int */
int Atoi(char s[])
{
  return (int)Atof(s);
}

/* Debug output
Printf(char s[])
{
  printf("[%s] [%d] %s");
}
*/
