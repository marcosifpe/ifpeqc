/*
 * q9.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct aritmeticaStr {
	int x, y, z;
	char op;
	bool erro;
};

typedef struct aritmeticaStr aritmetica;

void soma(aritmetica * calc) {
	calc->z = calc->x + calc->y;
	calc->op = '+';
	calc->erro = false;
}

void subtracao(aritmetica * calc) {
	calc->z = calc->x + calc->y;
	calc->op = '-';
	calc->erro = false;
}

void multiplicacao(aritmetica * calc) {
	calc->z = calc->x * calc->y;
	calc->op = '*';
	calc->erro = false;
}

void divisao(aritmetica * calc) {
	if (calc->y != 0) {
		calc->z = calc->x / calc->y;
		calc->erro = false;
	} else {
		calc->erro = true;
	}

	calc->op = '/';
}

void resto(aritmetica * calc) {
	if (calc->y != 0) {
		calc->z = calc->x % calc->y;
		calc->erro = false;
	} else {
		calc->erro = true;
	}

	calc->op = '%';
}

int main(void) {
	int i, n, op;
	void (*f[])(aritmetica *) = {soma, subtracao, multiplicacao, divisao, resto};
	aritmetica *v;
	freopen("e9.txt", "r", stdin);
	freopen("s9.txt", "w", stdout);

	scanf("%d", &n);
	v = (aritmetica*) malloc(sizeof(aritmetica) * n);

	if (v == NULL )
		exit(EXIT_FAILURE);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &op, &v[i].x, &v[i].y);
		f[op](v + i);

		if (v[i].erro == false)
			printf("%d %c %d = %d\n", v[i].x, v[i].op, v[i].y, v[i].z);
		else
			printf("%d %c %d = erro\n", v[i].x, v[i].op, v[i].y);
	}

	free(v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
