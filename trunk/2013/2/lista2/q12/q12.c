#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define T 20

char * lerLinha(FILE * in) {
	int max = T, el = 0;
	char *str = (char*) malloc(sizeof(char) * max), c;

	while ((c = getc(in)) != '\n') {
		if (el == max) {
			max *= 2;
			str = (char*) realloc(str, sizeof(char) * max);
		}

		str[el++] = c;
	}

	str[el] = '\0';

	return strcmp(str, "Fim") != 0 ? str : NULL;
}

void inverte(const char * orig, char * inv) {
	int i = 0;
	for (i = 0; i < strlen(orig); i++) {
		inv[i] = orig[strlen(orig) - (i + 1)];
	}

	inv[strlen(orig)] = '\0';
}

int main(void) {
	FILE *e = fopen("e12.txt", "r"), *s = fopen("s12.txt", "w");
	char *linha, *invertida = NULL;

	if (e == NULL || s == NULL)
		return EXIT_FAILURE;

	while(true) {
		linha = lerLinha(e);
		if (linha == NULL)
			break;

		invertida = realloc(invertida, sizeof(char) * (strlen(linha) + 1));
		if (invertida == NULL)
			return EXIT_FAILURE;

		inverte(linha, invertida);
		printf("%s\n", invertida);
		free(invertida);
	}

	free(linha);

	fclose(e);
	fclose(s);
	return EXIT_SUCCESS;
}
