/*
 * q20.c
 *
 *  Created on: 02/11/2012
 *      Author: Marcos Costa
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#define T 30

int main(void) {
	int i, n, v[T], soma;
	freopen("e20.txt", "r", stdin);
	freopen("s20.txt", "w", stdout);
	scanf("%d", &n);

	srand(time(NULL));

	while (n--) {
		for (i = 0, soma = 0; i < T; ++i) {
			v[i] = rand() % 100 + 1;
			soma += v[i];
		}

		printf("%d = ", soma);
		for (i = 0; i < T; ++i) {
			 printf("%d ", v[i]);
			 if (i != T - 1)
				 printf("+ ");
			 else
				 printf("\n");
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

