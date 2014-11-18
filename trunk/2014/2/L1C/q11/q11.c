/*
 * q11.c
 *
 *  Created on: 18/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

unsigned calcular_numero_digitos(unsigned n) {
	unsigned div = 10, dig = 1;

	while (div <= n) {
		div *= 10;
		dig += 1;
	}

	return dig;
}

int main(void) {
	int n, num, dig;
	freopen("e11.txt", "r", stdin);
	freopen("s11.txt", "w", stdout);

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &num);
		dig = calcular_numero_digitos(num);
		while (dig) {
			printf("%d", num % 10);
			num /= 10;
			--dig;
		}

		printf("\n");
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}
