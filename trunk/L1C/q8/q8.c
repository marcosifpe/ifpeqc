/*
 * q8.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>
#include <math.h>

double termoPI(double n) {
	return pow(-1.0, n)/(2*n + 1.0);
}

double calculaPI(int n) {
	int i;
	double res;
	for (i = 0, res = 0; i <= n; ++i) {
		res += termoPI((double)i);
	}

	return 4.0 * res;
}

double calculaErro(double pi) {
	return (M_PI >= pi) ? (M_PI - pi) / M_PI : (pi - M_PI) / M_PI;
}

int main(void) {
	int a;
	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);
	scanf("%d", &a);
	printf("PI: %.12lf\n", calculaPI(a));
	printf("Erro: %.15lf", calculaErro(calculaPI(a)));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

