/*
 * q3.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float a, b, c, delta, x1, x2;
	char continua;
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);

	do {
		scanf("%f %f %f %c", &a, &b, &c, &continua);
		delta = powf(b, 2) - 4*a*c;

		if (delta < 0) {
			printf("Nao existe solucao real para a equacao\n");
		} else {
			x1 = (-b + sqrtf(delta))/(2*a);
			x2 = (-b - sqrtf(delta))/(2*a);
			printf("%.2f %.2f %.2f\n", delta, x1, x2);
		}
	} while (continua == 'S');

	fclose(stdin);
	fclose(stdout);
	return 0;
}

