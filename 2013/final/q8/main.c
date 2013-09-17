#include <stdio.h>
#include <math.h>

void f1(int *p1, int *p2) {
    p1 = p2;
    *p2 = (int) powf(*p2, 2.0);
    *p1 = *p1 + 2;
}

void f2(int *p1, int *p2) {
    *p2 += (int) sqrtf(*p1 - *p2);
    p1 = p2;
}

int main(void) {
    int x = 2, y = 3, z = 4;
    f1(&x, &y);
    f2(&y, &z);
    printf("%d %d %d", x, y, z);
    return 0;
}
