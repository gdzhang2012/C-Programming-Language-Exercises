#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int Input_bufp = 0;
char Input_buf[BUFSIZE];

/*get_line: get line into s, return length*/
int get_line(char s[], int lim)
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

int getch(void)
{
  return (Input_bufp > 0) ? Input_buf[--Input_bufp] : getchar();
}

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
