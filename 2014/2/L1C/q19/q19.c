#include <stdio.h>
#include <stdlib.h>

double k_fatorial(int n, int k) {
       if (n >= 0 && n < k)
          return 1.0;
       else
          return n * k_fatorial(n - k, k);
}

int main(int argc, char *argv[])
{
  int i, k, x;
  freopen("e19.txt", "r", stdin);
  freopen("s19.txt", "w", stdout);
  scanf("%d %d", &k, &x);

  for (i = 0; i < x; i++) {
      if (i)
         printf(", ");
      printf("%.0lf", k_fatorial(i, k));
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
