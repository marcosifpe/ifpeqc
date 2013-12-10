#include <stdio.h>
#include <stdlib.h>
#define MAX 35
#define LIM 100
#define MED 10

struct {
	char nome[MAX];
	int tempo_trat;
	int hdl, ldl;
} typedef paciente;

paciente* criar(paciente * anteriores, int max) {
	paciente* atuais = (paciente*) realloc(anteriores, sizeof(paciente) * max);
	if (atuais == NULL) {
		exit(EXIT_FAILURE);
	}

	return atuais;
}

paciente * shellSort(paciente *vet, int size) {
	paciente * p = criar(NULL, size);
    int i , j , value;
    int gap = 1;

    while(gap < size) {
        gap = 3*gap+1;
    }

    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i].tempo_trat;
            j = i - gap;

            while (j >= 0 && value < vet[j].tempo_trat) {
                p[j + gap] = vet[j];
                j -= gap;
            }

            p[j + gap] = vet[i];
        }
    }

    return p;
}

int main(void) {
	FILE *in = fopen("e10.txt", "r"), *out = fopen("s10.txt", "w");
	int i, n = 0, max = 4, dif;
	paciente * pacientes = criar(NULL, max);
	paciente * ordenados;

	while(!feof(in)) {
		fscanf(in, "%d %d", &pacientes[n].hdl, &pacientes[n].ldl);
		fgetc(in); //ignorar espaço em branco
		fgets(pacientes[n].nome, MAX, in);

		for (i = 0; i < MAX; i++) {
			if (pacientes[n].nome[i] == '\n')
				pacientes[n].nome[i] = '\0';
		}

		pacientes[n].tempo_trat = 0;

		//calculando hdl
		if ((dif = LIM - pacientes[n].hdl) > 0) {
			while (dif > 0) {
				pacientes[n].tempo_trat++;
				dif -= MED;
				pacientes[n].hdl += MED;
			}
		}

		//calculando ldl
		if ((dif = pacientes[n].ldl - LIM) > 0) {
			while (dif > 0) {
				pacientes[n].tempo_trat++;
				dif -= MED;
				pacientes[n].ldl -= MED;
			}
		}

		n += 1;
		if (n == max) {
			max *= 2;
			pacientes = criar(pacientes, max);
		}
	}

	ordenados = shellSort(pacientes, n);

	for (i = 0; i < n; ++i) {
		fprintf(out, "%s, HDL: %d, LDL: %d, tempo: %d semanas\n", ordenados[i].nome, ordenados[i].hdl, ordenados[i].ldl, ordenados[i].tempo_trat);
	}

	free(pacientes);
	free(ordenados);
	fclose(in);
	fclose(out);
	return EXIT_SUCCESS;
}
