#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

unsigned invert(unsigned x, unsigned p, unsigned n)
{
  x = x ^ (~((~0 << (p + 1)) + ~(~0 << ((p + 1 - n)))));

  return x;
}

int main()
{
  printf("The result: %d\n", invert(255, 4, 3));

  return 0;
}
