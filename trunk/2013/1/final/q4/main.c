#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main(void) {
    int v[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *px, **ppx, ***pppx;
    int *py, **ppy, ***pppy;
    px = v;
    ppx = &px;
    pppx = &ppx;
    py = &v[TAM - 1];
    ppy = &py;
    pppy = &ppy;
    printf("%d, ", *px++);
    printf("%d, ", py - px);
    printf("%d, ", **ppx - 2);
    printf("%d ", --(***pppy));
    return 0;
}
