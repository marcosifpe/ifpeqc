/*
 * main.c
 *
 *  Created on: 11/12/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum enumTipoTelefone {
	FIXO = 1, MOVEL
} tipoTelefone;

typedef struct stNome {
	char primeiro[15];
	char ultimo[15];
} nomeContato;

typedef struct stTelefone {
	unsigned int ddd;
	unsigned int numero;
	char operadora[15];
	tipoTelefone tipo;
} telefoneContato;

typedef struct stContato {
	nomeContato nome;
	telefoneContato *telefone[2];
} contato;

void pularLinha(void) {
	char temp[20];
	scanf("%s", temp);
	scanf("%s", temp);
}

telefoneContato* lerTelefone(void) {
	char tipo;
	telefoneContato* telefone = (telefoneContato*) malloc(
			sizeof(telefoneContato));
	scanf("%u %u %s %c", &(telefone->ddd), &(telefone->numero),
			telefone->operadora, &tipo);
	if (tipo == 'F') {
		telefone->tipo = FIXO;
	} else {
		telefone->tipo = MOVEL;
	}

	return telefone;
}

void lerContatos(unsigned int n, contato* contatos) {
	unsigned int i;
	char outroNumero[4];

	for (i = 0; i < n; i++) {
		pularLinha(); //pulando "Contato i"
		scanf("%s %s", contatos[i].nome.primeiro, contatos[i].nome.ultimo);
		contatos[i].telefone[0] = lerTelefone();
		scanf("%s", outroNumero);

		if (strchr(outroNumero, 'S') != NULL) {
			contatos[i].telefone[1] = lerTelefone();
		} else {
			contatos[i].telefone[1] = NULL;
		}
	}
}

void procurar(tipoTelefone tipo, char nome[], unsigned int n, contato* contatos) {
	unsigned int i;
	bool found;

	for (i = 0; i < n; i++) {
		found = false;
		if (strstr(contatos[i].nome.primeiro, nome) != NULL ) {
			found = true;
		} else if (strstr(contatos[i].nome.ultimo, nome) != NULL ) {
			found = true;
		}

		if (found) {
			if (contatos[i].telefone[0]->tipo == tipo) {
				printf("%s %s %u %u\n", contatos[i].nome.primeiro,
						contatos[i].nome.ultimo, contatos[i].telefone[0]->ddd,
						contatos[i].telefone[0]->numero);
			}

			if (contatos[i].telefone[1] != NULL ) {
				if (contatos[i].telefone[1]->tipo == tipo) {
					printf("%s %s %u %u\n", contatos[i].nome.primeiro,
							contatos[i].nome.ultimo,
							contatos[i].telefone[1]->ddd,
							contatos[i].telefone[1]->numero);
				}
			}

		}
	}
}

void pesquisar(unsigned int p, unsigned int n, contato* contatos) {
	unsigned int i;
	char tipo;
	tipoTelefone tTelefone;
	char nome[15];

	for (i = 0; i < p; i++) {
		pularLinha(); //pulando "Pesquisa i"
		scanf("%s %c", nome, &tipo);

		if (tipo == 'F') {
			tTelefone = FIXO;
		} else {
			tTelefone = MOVEL;
		}

		printf("Resultado %d:\n", i + 1);
		procurar(tTelefone, nome, n, contatos);
	}
}

int main(void) {
	unsigned int n, p;
	contato *contatos;

	freopen("e10.txt", "r", stdin);
	freopen("s10.txt", "w", stdout);

	scanf("%u", &n);
	contatos = (contato*) malloc(sizeof(contato) * n);
	lerContatos(n, contatos);

	scanf("%u", &p);
	pesquisar(p, n, contatos);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
