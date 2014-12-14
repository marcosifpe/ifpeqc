#include <stdbool.h>
#include <stdio.h>
#define T 10

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

int main(void) {
	int a, b, v[T], i;

	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);

	for (i = 0; i < T; i++) {
		scanf("%i %i", &a, &b);
		v[i] = somaPrimos(a, b);
	}

	shellSort(v, T);

	for (i = 0; i < T; i++) {
		printf("%i", v[i]);
		if (i != T - 1)
			printf(", ");
	}
	printf("\n");

	fclose(stdin);
	fclose(stdout);
	return 0;
}
