/*
 * q5.c
 *
 *  Created on: 24/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void multiplica(int x, int y, int *resultado) {
	*resultado = 0;

	for (; x; x--) {
		*resultado += y;
	}
}

void calculaExponenciacao(int base, int expoente, int *resultado) {
	*resultado = 1;

	for(; expoente; expoente--) {
		multiplica(base, *resultado, resultado);
	}
}

int main(void) {
	int n, a, b, r;

	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);
	scanf("%d", &n);

	while(n--) {
		scanf("%d %d", &a, &b);
		calculaExponenciacao(a, b, &r);
		printf("%d\n", r);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
