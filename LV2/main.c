#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 5000000


struct oe_ {
	int x;
	struct oe_* sljedeci;
};

typedef struct oe_ oe;

void generirajNiz(int* v) {
	for (int i = 0; i < N; i++) {
		v[i] = rand() % 1000;
	}
}

oe* dodajElement(int v) {
	oe* rez = malloc(sizeof(oe));

	rez->x = v;
	rez->sljedeci = NULL;

	return rez;
}

void sekvencijalnoPretrazivanjeNiza(int *v, int trazeni) {

	for (int i = 0; i < N; i++) {
		if (v[i] == trazeni) {
			continue;
		}
	}
}

void sekvencijalnoPretrazivanjeListe(oe* prvi, int trazeni) {
	oe* trenutni = prvi;

	while (trenutni != NULL) {
		if (trenutni->x == trazeni) {
			continue;
		}
		trenutni = trenutni->sljedeci;
	}
}

void obrisiListu(oe* prvi)
{
	oe* trenutni = prvi;
	oe* next;

	while (trenutni != NULL)
	{
		next = trenutni->sljedeci;
		free(trenutni);
		trenutni = next;
	}

	prvi = NULL;
}

void ispisiListu(oe* prvi) {
	oe* trenutni = prvi;

	while (trenutni != NULL) {
		printf("%d\n", trenutni->x);
		trenutni = trenutni->sljedeci;
	}
}

oe* prvi = NULL;

int main() {
	srand(time(NULL));
	
	int* v = (int*)malloc(N * sizeof(int));

	if (v == NULL) {
		exit(1);
	}

	time_t t2, t1;


	t1 = clock();
	generirajNiz(v);
	t2 = clock();
	printf("Formiranje niza: %lldms\n", t2 - t1);

	
	t1 = clock();
	oe* trenutni;
	for (int i = 0; i < N; i++) {
		trenutni = dodajElement(v[i]);
		trenutni->sljedeci = prvi;
		prvi = trenutni;
	}
	t2 = clock();
	
	printf("Formiranje PP: %lldms\n", t2 - t1);

	t1 = clock();
	sekvencijalnoPretrazivanjeNiza(v, -1);
	t2 = clock();
	printf("Pretrazivanje niza: %lldms\n", t2 - t1);

	t1 = clock();

	sekvencijalnoPretrazivanjeListe(prvi, -1);
	t2 = clock();
	printf("Pretrazivanje PP: %lldms\n", t2 - t1);
	obrisiListu(prvi);

	
	free(v);

	return 0;
}