/*
 * q13.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(unsigned int a) {
	unsigned int i;
	bool primo = true;
	if (a == 1) {
		primo = false;
	} else {
		for (i = 2; i < a / 2 + 1; ++i) {
			if (a % i == 0) {
				primo = false;
				break;
			}
		}
	}

	return primo;
}

double fatorial(unsigned int a) {
	if (a == 0)
		return 1;
	else
		return a * fatorial(a - 1);
}

int main(void) {
	unsigned i, n, x;
	double soma;
	freopen("e13.txt", "r", stdin);
	freopen("s13.txt", "w", stdout);
	do {
		scanf("%u %u", &n, &x);
		if (!n && !x)
			break;
		for (i = 0, soma = 0; i < n; i++) {
			while (!ehPrimo(x)) {
				x++;
			}

			soma += fatorial(x++);
		}
		printf("%.0lf\n", soma);
	} while (true);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
