/*
 * q6.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

#define E 24.55
#define M 38.62
#define D 62.40

int main(void) {
	int horas;
	char sexo, titulacao;
	double salario, somam = 0, somaf = 0, soma = 0, t = 0, tm = 0, tf = 0;
	freopen("e6.txt", "r", stdin);
	freopen("s6.txt", "w", stdout);

	scanf("%d %c %c", &horas, &sexo, &titulacao);

	while (horas != 0 && sexo != 'a' && titulacao != 'a') {
		if (titulacao == 'E') {
			salario = horas * E * 4;
		} else if (titulacao == 'M') {
			salario = horas * M * 4;
		} else {
			salario = horas * D * 4;
		}

		soma += salario;
		t++;

		if (sexo == 'm') {
			somam += salario;
			tm++;
		} else {
			somaf += salario;
			tf++;
		}

		printf("%.2lf\n", salario);
		scanf("%d %c %c", &horas, &sexo, &titulacao);
	}

	printf("Media m: %.2lf\n", somam / tm);
	printf("Media f: %.2lf\n", somaf / tf);
	printf("Media geral: %.2lf\n", soma / t);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
