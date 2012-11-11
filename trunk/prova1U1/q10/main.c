/*
 * main.c
 *
 *  Created on: 10/11/2012
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
    int y;
    freopen("e10.txt", "r", stdin);
    scanf("%d %d", &x, &y);
    f1(x);
    f2(y);
    printf("%d, ", x++);
    printf("%d", --y);
    fclose(stdin);
    return 0;
}

