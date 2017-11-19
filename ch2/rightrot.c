#include <stdio.h>

/*wordlength: computes word length of the machine*/
int wordlength(void);
unsigned rightrot(unsigned x, unsigned n);
unsigned _rightrot(unsigned x, int n);
unsigned __rightrot(unsigned x, int n);

int wordlength(void)
{
  int i;
  unsigned v = (unsigned) ~0;

  for(i = 1; (v = v >> 1) > 0; i++)
  {
    //do nothing
  }

  return i;
}

/*solution-1 start*/
unsigned rightrot(unsigned x, unsigned n)
{
  x = (x >> n) + (x << ((sizeof(x) * 8) - n));

  return x;
}
/*solution-1 end*/

/*solution-2 start*/
/*_rightrot: rotate x to the right by n positions*/
unsigned _rightrot(unsigned x, int n)
{
  int rbit;

  while(n-- > 0)
  {
    rbit = (x & 1) << (wordlength() - 1);
    x = x >> 1;
    x = x | rbit;
  }

  return x;
}
/*solution-2 end*/

/*solution-3 start*/
unsigned __rightrot(unsigned x, int n)
{
  unsigned rbits;

  if((n = n % wordlength()) > 0)
  {
    rbits = ~(~0 << n) & x;
    rbits = rbits << (wordlength() -n);
    x = x >> n;
    x = x | rbits;
  }

  return x;
}
/*solution-3 end*/

int main()
{
  printf("The result: %02X\n", rightrot(255, 2));
  printf("The result: %02X\n", _rightrot(255, 3));
  printf("The result: %02X\n", __rightrot(255, 4));

  return 0;
}
