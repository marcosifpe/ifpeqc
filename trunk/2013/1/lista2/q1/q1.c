/*
 * q1.c
 *
 *  Created on: 24/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>

void ler(int a[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

}

void somarMatrizes(int a[3][3], int b[3][3]) {
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (j)
				printf(" ");
			printf("%d", a[i][j]+b[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);

	int m1[3][3], m2[3][3];
	ler(m1);
	ler(m2);
	somarMatrizes(m1, m2);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
