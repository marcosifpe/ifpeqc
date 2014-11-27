/*
 * q13.c
 *
 *  Created on: 06/05/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculaPI(int n) {
	double pi = 0.0;
	int k;

	for (k = 0; k <= n; ++k) {
		pi += (1.0 / pow(16.0, k)) * (4.0 / (8.0 * k + 1) - 2.0 / (8.0 * k + 4) - 1.0 / (8.0 * k + 5) - 1.0 / (8.0 * k + 6));
	}

	return pi;
}

int main(int argc, char **argv) {
	int n;
	freopen("e13.txt", "r", stdin);
	freopen("s13.txt", "w", stdout);
	scanf("%d", &n);
	printf("PI: %.15lf\n", calculaPI(n));
	printf("Erro: %.15lf\n", (M_PI - calculaPI(n)) / M_PI);
	return EXIT_SUCCESS;
}

