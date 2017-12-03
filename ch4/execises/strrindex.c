#include <stdio.h>
#include "utils.h"
#include <string.h>

/* 
  strrindex: return right index of t in s, -1 if none
*/
/* solution 1 */
int strrindex(char s[], char t[]);
/* solution 2 */
int _strrindex(char s[], char t[]);
/* my solution */
int __strrindex(char s[], char t[]);

char pattern[] = "ould"; /*pattern to search for*/

int main()
{
  char line[MAXLINE]; 
  int rindex = 0;

  while(get_line(line, MAXLINE) > 0)
  {
    /* best solution */
    if((rindex = _strrindex(line, pattern)) >= 0)
    {
      printf("The right index: %d\n", rindex);
    }
    else
    {
      printf("No matched\n");
    }
  }

  return rindex;
}

/* solution 1 */
int strrindex(char s[], char t[])
{
  int i, j, k, pos;

  pos = -1;
  for(i = 0; s[i] != '\0'; i++)
  {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
    {
      //do nothing
    }

    if(k > 0 && t[k] == '\0')
    {
      pos = i;
    }
  }

  return pos;
}

/* solution 1 */
int _strrindex(char s[], char t[])
{
  int i, j, k;

  for(i = strlen(s) - strlen(t); i >= 0; i--)
  {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
    {
      //do nothing
    }

    if(k > 0 && t[k] == '\0')
    {
      return i;
    }
  }

  return -1;
}

/* my solution */
int __strrindex(char s[], char t[])
{
  int i, j, k, len_s, len_t;

  len_s = strlen(s);
  len_t = strlen(t);
  for(i = len_s - 1; i >= 0; i--)
  {
    for(j = i, k = len_t -1; k >= 0 && j >= 0 && s[j] == t[k]; j--, k--)
    {
      /*do nothing*/
    }

    if(k < 0)
    {
      return j + 1;
    }
  }

  return -1;
}
