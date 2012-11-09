#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //biblioteca que simula tipos booleanos (true e false)

int main(void) {
	unsigned int i, j, x, y, soma = 0;
	bool primo;
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	scanf("%u %u", &x, &y);

	for (i = x; i <= y; i++) {
		if (i == 1) //por defini��o, 1 n�o � primo
			continue;

		primo = true; //na verdade, true � uma constante com valor 1

		for (j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				primo = false; //false � uma constante com valor 0
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
