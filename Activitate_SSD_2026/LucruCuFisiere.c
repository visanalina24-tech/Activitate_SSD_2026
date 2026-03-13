#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Masina Masina;

struct Masina
{
	int id;
	float pret;
	char* denumire;
	char marca;
};
void afisareMasina(Masina masina)
{
	printf("\n Id: %d", masina.id);
	printf("\n Pret:%5.2f euro", masina.pret);
	printf("\n Denumire:%s", masina.denumire);
	printf("\n Marca:%c", masina.marca);
}
Masina citireMasiniDinFisier(FILE* file)
{
	char buffer[100];
	char sep[4] = ",\n";
	fgets(buffer, 100, file);
	Masina m;
	m.id = atoi(strtok(buffer, sep));
	m.pret = atof(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);
	m.denumire = (char*)malloc(sizeof(char*) * (strlen(aux) + 1));
	strcpy_s(m.denumire, strlen(aux) + 1, aux);
	m.marca = *strtok(NULL, sep);
	return m;
}
void afisareVectorMasini(Masina* masini, int* nrMasini)
{
	for (int i = 0; i < *nrMasini; i++)
	{
		afisareMasina(masini[i]);
	}
}
Masina adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua)
{
	Masina* aux = (Masina*)malloc(sizeof(Masina) * (*nrMasini + 1));
	for (int i = 0; i < *nrMasini; i++)
	{
		aux[i] = (*masini)[i];
	}
	free(*masini);
	aux[(*nrMasini)] = masinaNoua;
	(*masini) = aux;
	(*nrMasini)++;

}
Masina* citireVectorMasiniFisier(const char* numeFisiser, int* nrMasiniCitite)
{
	FILE* file = fopen("masini.txt", "r");
	Masina* masini = NULL;
	(*nrMasiniCitite) = 0;
	while (!feof(file))
	{
		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasiniDinFisier(file));
	}
	fclose(file);
	return masini;
}
void dezalocareVector(Masina** masini, int* nrMasini)
{
	for (int i = 0; i < *nrMasini; i++)
	{
		if ((*masini)[i].denumire != 0) {
			free((*masini)[i].denumire);
		}
	}
	free(*masini);
	*masini = NULL;
	*nrMasini = 0;
}



int main()
{
	int nrMasini = 0;
	Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
	afisareVectorMasini(masini, &nrMasini);
	dezalocareVector(&masini, &nrMasini);

	return 0;
}


