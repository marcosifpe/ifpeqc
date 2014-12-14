/*
 * q10.c
 *
 *  Created on: 25/06/2013
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

/*
 * recebe um ponteiro para a estrutura aritm�tica, realiza os c�lculos, armazena o
 * resultado em calc->z e a opera��o em calc->op (nesse caso, o valor de op ser� '+'
 * e calc->erro = false).
 */
void soma(aritmetica * calc) {
	calc->op = '+';
	calc->erro = false;
	calc->z = calc->x + calc->y;
}

/*
 * recebe um ponteiro para a estrutura aritm�tica, realiza os c�lculos, armazena o
 * resultado em calc->z e a opera��o em calc->op (nesse caso, o valor de op ser� '-'
 * e calc->erro = false).
 */
void subtracao(aritmetica * calc) {
	calc->op = '-';
	calc->erro = false;
	calc->z = calc->x - calc->y;
}

/*
 * recebe um ponteiro para a estrutura aritm�tica, realiza os c�lculos, armazena o
 * resultado em calc->z e a opera��o em calc->op (nesse caso, o valor de op ser� '*'
 * e e calc->erro = false).
 */
void multiplicacao(aritmetica * calc) {
	calc->op = '*';
	calc->erro = false;
	calc->z = calc->x * calc->y;
}

/*
 * recebe um ponteiro para a estrutura aritm�tica, realiza os c�lculos, armazena o
 * resultado em calc->z e a opera��o em calc->op (nesse caso, o valor de op ser�
 * '/'). Caso calc->y = 0, calc->erro = true. Caso contr�rio, calc->erro = false.
 */
void divisao(aritmetica * calc) {
	calc->op = '/';
	if (calc->y) {
		calc->erro = false;
		calc->z = calc->x / calc->y;
	} else {
		calc->erro = true;
	}
}

int main(void) {
	int i, n, opcao;
	aritmetica * v;
	void (*f[]) (aritmetica *) = {soma, subtracao, multiplicacao, divisao};

	freopen("e9.txt", "r", stdin);
	freopen("s9.txt", "w", stdout);

	scanf("%d", &n);
	v = (aritmetica*) malloc(sizeof(aritmetica)*n);

	if (v == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < n; ++i) {
		scanf("%d %d %d", &opcao, &v[i].x, &v[i].y);
		f[opcao](&v[i]);
		if (!v[i].erro)
			printf("%d %c %d = %d\n", v[i].x, v[i].op, v[i].y, v[i].z);
		else
			printf("%d %c %d = erro\n", v[i].x, v[i].op, v[i].y);
	}

	free(v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

