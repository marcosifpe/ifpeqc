/*
 * q1.c
 *
 *  Created on: 15/09/2013
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
//comentario
int main(void) {
	int n, i = 0, num;
	double soma_inversos = 0.0;
	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);
	scanf("%d", &n);

	while (i != n) {
		scanf("%d", &num);
		soma_inversos += (1.0/num);
		++i;
	}

	printf("%.4lf\n", n/soma_inversos);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

