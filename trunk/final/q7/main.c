#include <stdio.h>

int f1(int a, int b) {
    if (a == 1)
       return 0;
    else
       return (a * b) + f1(a - 1, b - 1);
}

main(void) {
  int a[] = {1, 2, 3, 4}, b[] = {1, 2, 2, 3};
  int i, j = 0;
  for (i = 3; i >= 0; i--) {
      printf("%d ", f1(a[i], b[j++]));
  }

  return 0;
}
