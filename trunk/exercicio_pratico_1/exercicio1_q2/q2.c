#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	int i, x, y, soma;

	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);

	do {
		scanf("%d %d", &x, &y);

		if (!x && !y)
			break;

		soma = 0;
		for (i = 0; i < y; i++) {
			soma += x;
		}

		printf("%d\n", soma);
	} while (true);

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
