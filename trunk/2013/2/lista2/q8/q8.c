/*
 * q8.c
 *
 *  Created on: 27/06/2013
 *      Author: masc
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define VALOR_A 97

double fazNada(double n) {
	return n;
}

double converteGrausParaRadianos(double n) {
	return (n * M_PI) / 180.0;
}

int main(void) {
	char c;
	double n;
	double (*f[])(double) = {ceil, fabs, floor, cos, sin, tan, acos, asin, atan, exp, log, log10, sqrt};
	double (*g[])(double) = {fazNada, fazNada, fazNada, converteGrausParaRadianos, converteGrausParaRadianos, converteGrausParaRadianos, fazNada, fazNada, fazNada, fazNada, fazNada, fazNada, fazNada};
	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);

	do {
		do {
			scanf("%c", &c);
		} while (isspace(c));

		if (c == 's')
			break;

		if (c >= 'a' && c <= 'm') {
			scanf("%lf", &n);
			n = g[c - VALOR_A](n);
			printf("%.2lf\n", f[c - VALOR_A](n));
		}

	} while (true);

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
