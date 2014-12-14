#include <stdio.h>
#include <stdlib.h>
#define T 10

int main(void) {
	FILE * in = fopen("e4.txt", "r"), *out = fopen("s4.txt", "w");
	int i, j, mapas, matriz[T][T], costa;

	if (in == NULL || out == NULL)
		exit(EXIT_FAILURE);

	fscanf(in, "%d", &mapas);

	while (mapas--) {
		for (i = 0; i < T; ++i) {
			for (j = 0; j < T; ++j) {
				fscanf(in, "%d", &matriz[i][j]);
			}
		}

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
