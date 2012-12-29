/*
 * q4.c
 *
 *  Created on: 29/12/2012
 *      Author: masc
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MIN 'a'
#define MAX 'm'
#define FIM 's'

double converteGrausParaRadianos(double n) {
	return n * M_PI / 180.0;
}

double fazNada(double n) {
	return n;
}

int main(void) {
	char opcao;
	double n;
	double (*conv[])(double) = {
			fazNada, fazNada, fazNada, converteGrausParaRadianos, converteGrausParaRadianos,
			converteGrausParaRadianos, fazNada, fazNada, fazNada, fazNada, fazNada, fazNada, fazNada
			};
	double (*func[])(double) = {
			ceil, fabs, floor, cos, sin, tan, acos, asin, atan, exp, log, log10, sqrt
			};
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	do {
		do {
			opcao = getchar();
		} while (isspace(opcao));

		if (opcao == FIM)
			break;
		else if (opcao < MIN || opcao > MAX)
			continue;

		opcao -= MIN;
		scanf("%lf", &n);
		printf("%.2lf\n", func[(int) opcao](conv[(int) opcao](n)));
	} while (1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
