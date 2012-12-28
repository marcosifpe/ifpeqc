/*
 * q3.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fatorial(double i, double * resultado) {
	double f = 1;
	int n;

	for (n = 1; n <= i; n++) {
		f *= n;
	}

	*resultado = f;
}

void exponencial(double x, int t, double * resultado) {
	int i;
	double fat;
	*resultado = 0;

	for (i = 0; i < t; i++) {
		fatorial(i, &fat);
		*resultado += pow(x, i) / fat;
	}
}

void erro(double x, double e, double * resultado) {
	*resultado = 100.0 * (e - exp(x)) / exp(x);
	if (*resultado < 0)
		*resultado *= -1.0;
}

int main(void) {
	double x, expo, err;
	int t;
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);
	scanf("%lf %d", &x, &t);
	exponencial(x, t, &expo);
	erro(x, expo, &err);
	printf("exp(%.2lf): %.2lf\nerro relativo: %.2lf%%", x, expo, err);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
