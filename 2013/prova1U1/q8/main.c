/*
 * main.c
 *
 *  Created on: 10/11/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
    int i = 3, j, k;
    freopen("e8.txt", "r", stdin);
    while (i) {
        for (j = 3; j > 0; --j) {
            scanf("%d", &k);
            if (!(k % i)) {
                printf("break ");
                break;
            } else if (k % j == 0) {
                printf("continue ");
                continue;
            }
            printf("%d ", k + i - j);
        }
        --i;
    }

    fclose(stdin);
    return 0;
}

