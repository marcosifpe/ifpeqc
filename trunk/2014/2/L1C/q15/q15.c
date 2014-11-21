/*
 * q15.c
 *
 *  Created on: 18/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOME 30
#define MELHORES 3

int main(void) {
	int i, pontos_jogador, pontos_melhores[] = { 0, 0, 0 }, numero_jogadores;
	char nome_jogador[MAX_NOME], nomes_melhores[MELHORES][MAX_NOME];
	freopen("e15.txt", "r", stdin);
	freopen("s15.txt", "w", stdout);

	scanf("%d", &numero_jogadores);

	while (numero_jogadores--) {
		scanf("%d", &pontos_jogador);
		getchar();
		gets(nome_jogador);

		for (i = MELHORES - 1; i >= 0; --i) {
			if (pontos_jogador > pontos_melhores[i]
					|| (pontos_jogador == pontos_melhores[i]
							&& strcmp(nome_jogador, nomes_melhores[i]) == -1)) {
				if (i != 2) {
					pontos_melhores[i + 1] = pontos_melhores[i];
					strcpy(nomes_melhores[i + 1], nomes_melhores[i]);
				}

				pontos_melhores[i] = pontos_jogador;
				strcpy(nomes_melhores[i], nome_jogador);
			}
		}
	}

	for (i = 0; i < MELHORES; ++i) {
		printf("%d. %s\n", i + 1, nomes_melhores[i]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

