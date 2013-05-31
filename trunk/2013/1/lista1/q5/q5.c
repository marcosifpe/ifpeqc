/*
 * q5.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CELSIUS 'C'
#define FAHRENHEIT 'F'
#define KELVIN 'K'
#define RANKINE 'R'


int main(void) {
	double temperatura, temperaturaConvertida;
	char unidadeOrigem, unidadeDestino;
	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);

	do {
		//Leitura da unidade de origem
		do {
			unidadeOrigem = getchar();
		} while(isspace(unidadeOrigem));

		unidadeOrigem = toupper(unidadeOrigem);

		if (unidadeOrigem == 'E')
			continue;

		//Leitura da unidade de destino
		if (unidadeOrigem == CELSIUS) {
			do {
				unidadeDestino = getchar();
			} while(isspace(unidadeDestino));

			unidadeDestino = toupper(unidadeDestino);

		}

		scanf("%lf", &temperatura);

		switch (unidadeOrigem) {
			case KELVIN:
				temperaturaConvertida = temperatura - 273.15;
				break;
			case FAHRENHEIT:
				temperaturaConvertida = (temperatura - 32.0) / 1.8;
				break;
			case RANKINE:
				temperaturaConvertida = (temperatura / 1.8) - 273.15;
				break;
			case CELSIUS:
				if (unidadeDestino == FAHRENHEIT) {
					temperaturaConvertida = temperatura * 1.8 + 32.0;
				} else if (unidadeDestino == KELVIN) {
					temperaturaConvertida = temperatura + 273.15;
				} else if (unidadeDestino == RANKINE) {
					temperaturaConvertida = (temperatura + 273.15) * 1.8;
				}

				break;
		}

		printf("%.2lf\n", temperaturaConvertida);
	} while(unidadeOrigem != 'E');

	fclose(stdin);
	fclose(stdout);
	return 0;
}


