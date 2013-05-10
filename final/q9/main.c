#include <stdio.h>

int f(int x) {
   int i = 0, s = 0;

   for (; i <= x; ++i) {
       if (i % 2 && i % 5)
          continue;
       s += i;
   }

   return s;
}

int main(void) {
  printf("%d", f(10));
  return 0;
}
