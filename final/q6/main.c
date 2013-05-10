#include <stdio.h>

enum letras {A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

int main(void) {
  enum letras letra = A;
  int i;

  while (letra < W) {
        if (letra % 2 == 0) {
           letra++;
        } else {
           letra += 7;
        }

        printf("%c ", (char) letra);
  }

  printf("\n");
  return 0;
}
