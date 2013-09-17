#include <stdio.h>

int main(void) {
    int a, b, c = 0, m[3][3];
    int v1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (a = 2; a >= 0; --a) {
        for (b = 0; b <= 2; ++b) {
            m[b][a] = v1[c] * v2[c];
            c += 1;
        }
    }

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
             printf("%d ", m[a][b]);
        }
    }
    return 0;
}
