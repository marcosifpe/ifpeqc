/*
 * q4.c
 *
 *  Created on: 20/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int soma_divisores(int n) {
	int s = 0, i;

	for (i = 1; i <= n; ++i) {
		if (n % i == 0)
			s += i;
	}

	return s;
}

int main(void) {
	int n, num;
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &num);
		printf("%d ", soma_divisores(num));
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}
