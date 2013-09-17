/*
 * q7.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	char id;
	int numero_votos;
	double percentual_total;
	double percentual_validos;
} candidato;

void ordena(candidato * candidatos, const int num_candidatos) {
	int i, j;
	char id;
	int gap = 1;
	do {
		gap = 3 * gap + 1;
	} while (gap < num_candidatos);
	do {
		gap /= 3;
		for (i = gap; i < num_candidatos; i++) {
			id = candidatos[i].id;
			j = i - gap;
			while (j >= 0 && id < candidatos[j].id) {
				candidatos[j + gap].id = candidatos[j].id;
				j -= gap;
			}
			candidatos[j + gap].id = id;
		}
	} while (gap > 1);
}

candidato* getCandidato(char id, candidato * candidatos,
		const int num_candidatos) {
	int i;
	candidato* cand = NULL;

	for (i = 0; i < num_candidatos; i++) {
		if (candidatos[i].id == id) {
			cand = &candidatos[i];
			break;
		}
	}

	return cand;
}

candidato* lerCandidatos(int num_candidatos) {
	int i;
	candidato* candidatos = malloc(sizeof(candidato) * num_candidatos);

	if (candidatos == NULL )
		exit(EXIT_FAILURE);

	for (i = 0; i < num_candidatos - 2; ++i) {
		scanf(" %c", &candidatos[i].id);
	}

	candidatos[num_candidatos - 2].id = 'B';
	candidatos[num_candidatos - 1].id = 'N';

	ordena(candidatos, num_candidatos - 2);

	for (i = 0; i < num_candidatos; ++i) {
		candidatos[i].numero_votos = 0;
		candidatos[i].percentual_total = 0.0;
		candidatos[i].percentual_validos = 0.0;
	}

	return candidatos;
}

candidato * getVencedor(candidato * candidatos, const int num_candidatos) {
	candidato * vencedor = &candidatos[0];
	int i, votos = candidatos[0].numero_votos;

	for (i = 1; i < num_candidatos; i++) {
		if (candidatos[i].numero_votos > votos) {
			votos = candidatos[i].numero_votos;
			vencedor = &candidatos[i];
		}
	}

	return vencedor;
}

char segundoTurno(candidato * vencedor, int num_votos_validos) {
	char st = 'S';
	int minimo = 1 + num_votos_validos / 2;

	if (vencedor->numero_votos >= minimo) {
		st = 'N';
	}

	return st;
}

int main(void) {
	int i, num_candidatos, num_votos, num_votos_validos = 0;
	candidato *candidatos, *vencedor;
	char *votos;

	freopen("e7.txt", "r", stdin);
	freopen("s7.txt", "w", stdout);
	scanf("%i", &num_candidatos);
	num_candidatos += 2; //adicionar 2 devido aos votos brancos e nulos

	candidatos = lerCandidatos(num_candidatos);
	scanf("%i", &num_votos);
	votos = (char*) realloc(NULL, sizeof(char)*num_votos);

	for (i = 0; i < num_votos; i++) {
		do {
			votos[i] = getchar();
		} while (isspace(votos[i]));

		getCandidato(votos[i], candidatos, num_candidatos)->numero_votos += 1;

		if (votos[i] != 'B' && votos[i] != 'N') {
			num_votos_validos += 1;
		}
	}

	vencedor = getVencedor(candidatos, num_candidatos - 2); //apenas candidatos válidos
	printf("Vencendor: %c\n", vencedor->id);
	printf("Segundo Turno: %c\n", segundoTurno(vencedor, num_votos_validos));

	for (i = 0; i < num_candidatos; ++i) {
		candidatos[i].percentual_total = 100.0 * candidatos[i].numero_votos
				/ num_votos;

		printf("%c: %.2lf%%", candidatos[i].id, candidatos[i].percentual_total);

		if (candidatos[i].id != 'B' && candidatos[i].id != 'N') {
			candidatos[i].percentual_validos = 100.0
					* candidatos[i].numero_votos / num_votos_validos;
			printf(" %.2lf%%", candidatos[i].percentual_validos);
		}

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
