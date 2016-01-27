#include "stdio.h"

void swap(int *a,int *b)
{
   int c;
   c = *a;
   *a = *b;
   *b = c;
}

int main(void)
{
   int a ;
   int b ;
   int ret;
   a =16;
   b = 64;
   ret = 0;
   swap(&a,&b);
   ret = a - b;
   return ret;
}
