#include <stdio.h>

/*
将x中从右边数第p位开始的n个（二进制）位设置为y中最右边n为的值，
x的其余各位保持不变。
*/
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);
unsigned _setbits(unsigned x, unsigned p, unsigned n, unsigned y);

/*方法1*/
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
  x = x & ((~0 << (p + 1)) + ~(~0 << ((p + 1 - n))));

  y = ((y & (~(~0 << n))) << (p + 1 -n));

  return x + y;
}

/*方法2*/
unsigned _setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
  return (x & (~((~(~0 << n)) << (p + 1 -n))))
        | ((y & (~(~0 << n))) << (p + 1 -n));
}

int main()
{
  printf("The result: %d\n", setbits(255, 3, 2, 2));
  printf("The result: %d\n", _setbits(255, 3, 2, 2));

  return 0;
}
