/*
 * q18.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTOES 150
#define TAM_CPF 14

int calcula_acertos(char gabarito_oficial[], char gabarito_candidato[], int num_questoes) {
	int i, acertos;

	for (i = 0, acertos = 0; i < num_questoes; ++i) {
		if (gabarito_oficial[i] == gabarito_candidato[i]) {
			++acertos;
		}
	}

	return acertos;
}

int main(void) {
	char gabarito_oficial[MAX_QUESTOES + 1], gabarito_candidato[MAX_QUESTOES + 1],
			cpf_candidato[TAM_CPF + 1];
	int i, num_questoes, num_candidatos, numero_acertos;
	freopen("e18.txt", "r", stdin);
	freopen("s18.txt", "w", stdout);
	scanf("%d %d", &num_questoes, &num_candidatos);
	getchar();
	scanf("%s", gabarito_oficial);

	for (i = 0; i < num_candidatos; ++i) {
		scanf("%s %s", cpf_candidato, gabarito_candidato);
		numero_acertos = calcula_acertos(gabarito_oficial, gabarito_candidato, num_questoes);
		printf("%s %.3lf\n", cpf_candidato, numero_acertos * 10.0 / num_questoes);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

