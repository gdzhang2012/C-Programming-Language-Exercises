#include <stdio.h>
#include "utils.h"

int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*pattern to search for*/

/*test empty function*/
dummy()
{
}

/*find all line matching pattern*/
int main()
{
  char line[MAXLINE]; 
  int found = 0;

  dummy();

  while(get_line(line, MAXLINE) > 0)
  {
    if(strindex(line, pattern) >= 0)
    {
      printf("%s\n", line);
      found++;
    }
  }

  return found;
}

/*strindex: return index of t in s, -1 if none*/
int strindex(char s[], char t[])
{
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++)
  {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
    {
      /*do nothing*/
    }

    if(k > 0 && t[k] == '\0')
    {
      return i;
    }
  }

  return -1;
}
