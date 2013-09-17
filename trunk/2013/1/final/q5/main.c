#include <stdio.h>

int main(void) {
    int i = 3, j, k;
    freopen("e.txt", "r", stdin);
    while (i) {
        for (j = 2; j > 0; --j) {
            scanf("%d", &k);
            if (!(k % i)) {
                printf("break ");
                break;
            } else if (k % j == 0) {
                printf("continue ");
                continue;
            }
            printf("%d ", k + (i * 2) - j);
        }
        --i;
    }

    fclose(stdin);
    return 0;
}
