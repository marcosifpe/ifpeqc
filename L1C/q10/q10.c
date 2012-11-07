/*
 * q10.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int idade, livros, l1 = 0, l2 = 0, l3 = 0, contL3 = 0, l4 = 0, contTotal = 0;
	char sexo;
	freopen("e10.txt", "r", stdin);
	freopen("s10.txt", "w", stdout);

	while (1) {
		scanf("%d", &idade);
		if (idade < 0)
			break;

		contTotal += 1;
		scanf(" %c %d", &sexo, &livros);

		//a quantidade total de livros lidos pelos entrevistados menores de 10 anos
		if (idade < 10)
			l1 += livros;

		//a quantidade de mulheres que leram 5 livros ou mais
		if (sexo == 'F' && livros >= 5)
			l2 += 1;

		//a média de idade dos homens que leram menos de 5 livros (com 1 casa decimal)
		if (sexo == 'M' && livros < 5) {
			l3 += idade;
			contL3 += 1;
		}

		//o percentual de pessoas que não leram livros (com 1 casa decimal).
		if (livros == 0) {
			l4 += 1;
		}
	}

	printf("%d\n%d\n%.1f\n%.1f%%", l1, l2, (float) l3/contL3, (float)100*l4/contTotal);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
