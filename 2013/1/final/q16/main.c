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
    freopen("e.txt", "r", stdin);
    scanf("%d %d", &x, &y);
    f1(x);
    f2(y);
    printf("%d, ", x++);
    printf("%d", --y);
    return 0;
}
