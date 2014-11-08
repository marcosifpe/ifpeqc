#include <stdio.h>
#include <stdlib.h>
#define N 100
#define MAX_DIGITOS 7

unsigned calcular_numero_digitos(unsigned n) {
	unsigned div = 10, dig = 1;

	while (div <= n) {
		div *= 10;
		dig += 1;
	}

	return dig;
}

int numero_valido(int numero[], int numero_digitos) {
	int i, valido = 1;

	for (i = 0; i < numero_digitos; ++i) {
		if (numero[i] == 4)
			valido = 0;
		if (i + 1 < numero_digitos) {
			if (numero[i] == 1 && numero[i + 1] == 3) {
				valido = 0;
			}
		}
	}

	return valido;
}

int main() {
	int n, i, j, num_andares, num_andar, numero_digitos, numero[MAX_DIGITOS],
			divisores[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000 };
	freopen("e27.txt", "r", stdin);
	freopen("s27.txt", "w", stdout);
	scanf("%d", &n);

	while (n) {
		num_andares = 0;
		num_andar = 1;

		while (num_andares < n) {
			for (numero_digitos = calcular_numero_digitos(num_andar), i = 0, j = num_andar;
					numero_digitos; numero_digitos--) {
				numero[i++] = j / divisores[numero_digitos];
				j %= divisores[numero_digitos];
			}

			if (numero_valido(numero, calcular_numero_digitos(num_andar))) {
				num_andares++;
			}

			num_andar++;
		}

		printf("%d\n", num_andar-1);
		scanf("%d", &n);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
