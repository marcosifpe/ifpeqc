/*
 * q15.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define TAM 20

void trocarElementosVetor(double v[], int n) {
	int i = 0, j = n - 1;
	double temp;

	while (i < j) {
		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		i++;
		j--;
	}
}

int main(void) {
	double v[TAM];
	int i;

	freopen("e15.txt", "r", stdin);
	freopen("s15.txt", "w", stdout);

	for (i = 0; i < TAM; i++) {
		scanf("%lf", &v[i]);
	}

	trocarElementosVetor(v, TAM);

	printf("[");
	for (i = 0; i < TAM; i++) {
		if (i)
			printf(", ");
		printf("%.1lf", v[i]);
	}

	printf("]");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


