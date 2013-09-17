/*
 * q12.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>
#include <math.h>

double termoPI(double k) {
	return (1/pow(16, k)) * ((4/(8*k+1))-(2/(8*k+4))-(1/(8*k+5))-(1/(8*k+6)));
}

double calculaPI(int n) {
	int i;
	double res;
	for (i = 0, res = 0; i <= n; ++i) {
		res += termoPI((double)i);
	}

	return res;
}

double calculaErro(double pi) {
	return M_PI > pi ? (M_PI - pi) / M_PI : (pi - M_PI) / M_PI;
}

int main(void) {
	int n;
	freopen("e12.txt", "r", stdin);
	freopen("s12.txt", "w", stdout);
	scanf("%d", &n);
	printf("PI: %.15lf\n", calculaPI(n));
	printf("Erro: %.15lf", calculaErro(calculaPI(n)));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
