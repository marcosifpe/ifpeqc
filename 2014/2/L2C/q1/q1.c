#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool primo(int n) {
	int i;
	bool p = (n == 1) ? false : true;

	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			p = false;
			break;
		}

	}

	return p;
}

int somaPrimos(int a, int b) {
	int i, s = 0;

	for (i = a; i <= b; i++) {
		if (primo(i)) {
			s += i;
		}
	}

	return s;
}

void shellSort(int vet[], int size) {
	int i, j, value;
	int gap = 1;
	while (gap < size) {
		gap = 3 * gap + 1;
	}
	while (gap > 1) {
		gap /= 3;
		for (i = gap; i < size; i++) {
			value = vet[i];
			j = i - gap;
			while (j >= 0 && value < vet[j]) {
				vet[j + gap] = vet[j];
				j -= gap;
			}
			vet[j + gap] = value;
		}
	}
}

int * criarVetor(int * p, int elementos) {
	p = (int *) realloc(p, elementos * sizeof(int));

	if (p == NULL) //aborta execução caso não haja memória disponível
		exit(EXIT_FAILURE);

	return p;
}

int main(void) {
	int a, b, i, max = 5, tam = 0;
	int * v;
	FILE * in, *out;

	v = criarVetor(NULL, max);

	in = fopen("e1.txt", "r");
	out = fopen("s1.txt", "w");

	for (i = 0; !feof(in); i++) {
		if (i == max) {
			max *= 2;
			v = criarVetor(v, max);
		}

		fscanf(in, "%i %i", &a, &b);
		v[i] = somaPrimos(a, b);
		tam += 1;
	}

	shellSort(v, tam);

	for (i = 0; i < tam; i++) {
		fprintf(out, "%i", v[i]);
		if (i != tam - 1)
			fprintf(out, ", ");
	}

	fprintf(out, "\n");

	fclose(in);
	fclose(out);
	return 0;
}
