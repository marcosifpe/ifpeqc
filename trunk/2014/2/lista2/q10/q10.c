#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void buble(paciente *vet, int size) {
	paciente p;
	int i, j, min;

	for (i = 0; i < size; i++) {
        p.hdl = vet[i].hdl;
        p.ldl = vet[i].ldl;
        p.tempo_trat = vet[i].tempo_trat;
        strcpy(p.nome, vet[i].nome);
        min = i;

		for (j = i + 1; j < size; j++) {
			if (vet[j].tempo_trat < vet[min].tempo_trat) {
				min = j;
			}
		}

		vet[i].hdl = vet[min].hdl;
		vet[i].ldl = vet[min].ldl;
		vet[i].tempo_trat = vet[min].tempo_trat;
		strcpy(vet[i].nome, vet[min].nome);

		vet[min].hdl = p.hdl;
		vet[min].ldl = p.ldl;
		vet[min].tempo_trat = p.tempo_trat;
		strcpy(vet[min].nome, p.nome);

	}
}

int main(void) {
	FILE *in = fopen("e10.txt", "r"), *out = fopen("s10.txt", "w");
	int i, n = 0, max = 4, dif;
	paciente * pacientes = criar(NULL, max);

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

	buble(pacientes, n);

	for (i = 0; i < n; ++i) {
		fprintf(out, "%s, HDL: %d, LDL: %d, tempo: %d semanas\n", pacientes[i].nome, pacientes[i].hdl, pacientes[i].ldl, pacientes[i].tempo_trat);
	}

	free(pacientes);
	fclose(in);
	fclose(out);
	return EXIT_SUCCESS;
}
