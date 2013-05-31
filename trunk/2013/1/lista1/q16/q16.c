/*
 * q16.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double radiano(double graus) {
	return graus * M_PI / 180.0;
}

double fatorial(double n) {
	if (n == 0)
		return 1;
	else
		return n * fatorial(n - 1);
}

double seno(double x, int precisao) {
	int n;
	double rad = radiano(x), sen;

	for (sen = 0, n = 0; n < precisao; n++) {
		sen += (pow(-1.0, n) / fatorial(2.0 * n + 1)) * pow(rad, 2.0 * n + 1);
	}

	return sen;
}

double cosseno(double x, int precisao) {
	int n;
	double rad = radiano(x), cos;

	for (cos = 0, n = 0; n < precisao; n++) {
		cos += (pow(-1.0, n) / fatorial(2.0 * n)) * pow(rad, 2.0 * n);
	}

	return cos;
}

double tangente(double x, int precisao) {
	return seno(x, precisao) / cosseno(x, precisao);
}

int main(void) {
	double angulo;
	int precisao;
	freopen("e16.txt", "r", stdin);
	freopen("s16.txt", "w", stdout);

	scanf("%lf %d", &angulo, &precisao);

	while (angulo >= 0.0) {
		printf("sen(%.2lf): %.4lf, ", angulo, seno(angulo, precisao));
		printf("cos(%.2lf): %.4lf, ", angulo, cosseno(angulo, precisao));

		if (angulo != 90.0 && angulo != 270.0) {
			printf("tan(%.2lf): %.4lf", angulo, tangente(angulo, precisao));
		}

		printf("\n");
		scanf("%lf %d", &angulo, &precisao);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

