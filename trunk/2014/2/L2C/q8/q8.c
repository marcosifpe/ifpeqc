#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define T 5
#define L 26

struct {
	char letra;
	int quantidade;
} typedef alfabeto;

char* realocar(char* v, int t) {
	char *novo = (char*) realloc(v, sizeof(char) * t);
	if (novo == NULL && t != 0)
		exit(EXIT_FAILURE);

	return novo;
}

int main(void) {
	char c, *v = realocar(NULL, T);
	int i, el = 0, max_el = T;
	alfabeto mai[L], min[L];
	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);

	while (scanf("%c", &c) != EOF) {
		if (isspace(c))
			continue;
		v[el++] = c;

		if (el == max_el) {
			max_el *= 2;
			v = realocar(v, max_el);
		}
	}

	for (c = 'A', i = 0; i < L; i++, c++) {
		mai[i].letra = c;
		mai[i].quantidade = 0;
	}

	for (c = 'a', i = 0; i < L; i++, c++) {
		min[i].letra = c;
		min[i].quantidade = 0;
	}

	for (i = 0; i < el; i++) {
		if (v[i] == tolower(v[i])) {
			min[v[i]-'a'].quantidade++;
		} else {
			mai[v[i]-'A'].quantidade++;
		}
	}

	for (i = 0; i < L; i++) {
		if (mai[i].quantidade > 1) {
			printf("%c: %d\n", mai[i].letra, mai[i].quantidade);
		}
	}

	for (i = 0; i < L; i++) {
		if (min[i].quantidade > 1) {
			printf("%c: %d\n", min[i].letra, min[i].quantidade);
		}
	}

	realocar(v, 0);
	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
