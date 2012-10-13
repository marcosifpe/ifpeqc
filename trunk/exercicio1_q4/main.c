#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	unsigned int i, j, x, y, soma = 0;
	bool primo;
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	scanf("%u %u", &x, &y);

	for (i = x; i <= y; i++) {
		if (i == 1) //por definição, 1 não é primo
			continue;

		primo = true;

		for (j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				primo = false;
				break;
			}
		}

		if (primo) {
			soma += i;
			printf("%u ", i);
		}

	}

	printf("\nsoma: %u", soma);
	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
