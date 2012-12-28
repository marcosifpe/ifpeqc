/*
 * q8.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */

#include <stdio.h>
#include <stdlib.h>

enum semana {
	DOMINGO = 1, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO
};

struct vendaStr {
	enum semana dia;
	int hambuger;
	int cheeseburger;
	int refrigerante;
};

typedef struct vendaStr venda;

struct precoStr {
	double hambuger;
	double cheeseburger;
	double refrigerante;
};

typedef struct precoStr preco;

int main(void) {
	enum semana i;
	int d;
	double total = 0, soma_dia;
	preco p;
	venda v[7];
	char *dias[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);

	scanf("%lf %lf %lf", &p.hambuger, &p.cheeseburger, &p.refrigerante);

	for (i = 0; i < SABADO; i++) {
		scanf("%i %i %i %i", &d, &v[i].hambuger, &v[i].cheeseburger, &v[i].refrigerante);
		v[i].dia = d;
		soma_dia = v[i].hambuger * p.hambuger
				+ v[i].cheeseburger * p.cheeseburger
				+ v[i].refrigerante * p.refrigerante;
		printf("%s: %.2lf\n", dias[i], soma_dia);
		total += soma_dia;
	}

	printf("%s: %.2lf\n", "Total", total);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
