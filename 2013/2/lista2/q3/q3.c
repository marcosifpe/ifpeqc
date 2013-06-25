/*
 * q3.c
 *
 *  Created on: 24/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define T 3

void ler(int a[T][T]) {
	int i, j;
	for (i = 0; i < T; i++) {
		for (j = 0; j < T; j++) {
			scanf("%d", &a[i][j]);
		}
	}

}

int somaDiagonalPrincipal(int a[T][T]) {
	int res;
	res = a[0][0]*a[1][1]*a[2][2];
	res += a[0][1]*a[1][2]*a[2][0];
	res += a[0][2]*a[1][0]*a[2][1];
	return res;
}

int somaDiagonalSecundaria(int a[T][T]) {
	int res;
	res = a[0][2]*a[1][1]*a[2][0];
	res += a[0][0]*a[1][2]*a[2][1];
	res += a[0][1]*a[1][0]*a[2][2];
	return res;
}


int main(void) {
	int m[T][T], n, det;
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);

	scanf("%d", &n);

	while(n--) {
		ler(m);
		det = 0;
		det += somaDiagonalPrincipal(m);
		det -= somaDiagonalSecundaria(m);
		printf("%d\n", det);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

