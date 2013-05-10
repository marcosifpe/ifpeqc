/*
 * main.c
 *
 *  Created on: 10/05/2013
 *      Author: masc
 */

#include <stdio.h>

int x, y = 5;

void f1(int x) {
    x += y++;
    printf("%d, ", ++x);
}

void f2(int y) {
    y %= 5;
    printf("%d, ", y++);
}

int main(void) {
    int y = 12;
    x = 4;
    f1(x);
    f2(y);
    printf("%d, ", x++);
    printf("%d", --y);
    return 0;
}
