#include <stdio.h>
#include <stdlib.h>
#define T 10

int main(void) {
	FILE * in = fopen("e4.txt", "r"), *out = fopen("s4.txt", "w");
	int i, j, matriz[T][T], costa;
	int sair = 0;

	if (in == NULL || out == NULL)
		exit(EXIT_FAILURE);

	while (1) {
		for (i = 0; i < T; ++i) {
			for (j = 0; j < T; ++j) {
				if (fscanf(in, "%d", &matriz[i][j]) == EOF) {
					sair = 1;
					break;
				}
			}
		}

		if (sair)
			break;

		for (costa = 0, i = 0; i < T; ++i) {
			for (j = 0; j < T; ++j) {
				if (matriz[i][j]) {
					if (!matriz[i - 1][j] || !matriz[i + 1][j]
							|| !matriz[i][j + 1] || !matriz[i][j - 1]) {
						costa += 1;
					}
				}
			}
		}

		fprintf(out, "%d\n", costa);
	}

	fclose(in);
	fclose(out);
	return EXIT_SUCCESS;
}
