#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Masina Masina;
typedef struct Nod Nod;

struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* marca;
	unsigned char serie;
};
struct Nod {
	Masina masina;
	Nod* next;
	Nod* prev;
};
void afisareMasina(Masina masina) {
	printf("ID: %d\n", masina.id);
	printf("Nr. usi: %d\n", masina.nrUsi);
	printf("Pret: %f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Marca: %s\n", masina.marca);
	printf("Serie: %c\n", masina.serie);
}
Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = "\n,";
	fgets(buffer, 100, file);
	char* aux;
	aux = strtok(buffer, sep);
	Masina m;
	m.id = atoi(aux);
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m.model = malloc(strlen(aux) + 1);
	strcpy_s(m.model, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	m.marca = malloc(strlen(aux) + 1);
	strcpy_s(m.marca, strlen(aux) + 1, aux);
	m.serie = *strtok(NULL, sep);
	return m;
}
void adaugaMasinaInArbore(Nod** arbore, Masina masinaNoua) {
	if (*arbore == NULL) {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->masina = masinaNoua;
		nou->prev = NULL;
		nou->next = NULL;
		(*arbore) = nou;
	}
	else if ((*arbore)->masina.id > masinaNoua.id) {
		adaugaMasinaInArbore(&((*arbore)->prev), masinaNoua);
	}
	else if ((*arbore)->masina.id <= masinaNoua.id) {
		adaugaMasinaInArbore(&(*arbore)->next, masinaNoua);
	}
}
Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");
	Nod* arbore = NULL;
	while (!feof(f)) {
		adaugaMasinaInArbore(&arbore, citireMasinaDinFisier(f));
	}
	fclose(f);
	return arbore;
}
void afisareMasiniDinArbore(Nod* arbore) {
	if (arbore) {
		afisareMasina(arbore->masina);
		afisareMasiniDinArbore(arbore->prev);
		afisareMasiniDinArbore(arbore->next);
	}
}

void dezalocareDeArboreDeMasini(Nod** arbore) {
	if (*arbore) {
		dezalocareDeArboreDeMasini(&(*arbore)->prev);
		dezalocareDeArboreDeMasini(&(*arbore)->next);
		free((*arbore) -> prev);
		free((*arbore)->next);
		free(*arbore);
		*arbore = NULL;
	}
}

int main (){

	Nod* arbore = citireArboreDeMasiniDinFisier("masiniArbore.txt");
	afisareMasiniDinArbore(arbore);
	
	Masina m = (Masina){ 100,2,70000,"A6","Audi",'A'};
	adaugaMasinaInArbore(&arbore, m);
	afisareMasiniDinArbore(arbore);
	dezalocareDeArboreDeMasini(&arbore);

}