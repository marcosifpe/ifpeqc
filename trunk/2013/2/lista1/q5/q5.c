/*
 * q5.c
 *
 *  Created on: 06/11/2013
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num_prod, quant_prod, quant_itens = 0;
	double precos[] = {0.0, 2.90, 5.90, 12.90, 16.75, 27.50}, total_compra = 0.0;

	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);

	scanf("%d %d", &num_prod, &quant_prod);

	do {
		total_compra += precos[num_prod] * quant_prod;
		quant_itens += quant_prod;

		scanf("%d %d", &num_prod, &quant_prod);
	} while (num_prod != 0 && quant_prod != 0);

	printf("total de itens: %d\n", quant_itens);
	printf("preco total: %.2lf\n", total_compra);

	fclose(stdin);
	fclose(stdout);
	return 0;
}




