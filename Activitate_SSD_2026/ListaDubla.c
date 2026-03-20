#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct Masina Masina;
typedef struct Nod Nod;
typedef struct ListaDubla ListaDubla;

struct Masina
{
	int id;
	float pret;
	char* denumire;
	char marca;
};

struct Nod
{
	Masina info;
	Nod* next;
	Nod* prev;
};

struct ListaDubla
{
	Nod* first;
	Nod* last;
	int nrNoduri;
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
	m.denumire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy_s(m.denumire, strlen(aux) + 1, aux);
	m.marca = *strtok(NULL, sep);
	return m;
}

//void afisareMasinaLista(Nod*cap)
//{
//	Nod* nou = cap;
//	while (nou != 0)
//	{
//		afisareMasina(nou->info);
//		nou = nou->next;
//	}
//}
void afisareListaMasiniInceput(ListaDubla lista)
{
	Nod* nou = lista.first;
	while (nou != 0)
	{
		afisareMasina(nou->info);
		nou=nou->next;
	}
}
void afisareListaMasiniSfarsit(ListaDubla lista)
{
	Nod* nou = lista.last;
	while (nou)
	{
			afisareMasina(nou->info);
			nou = nou->prev;
	}
}
void adaugaMasinaInListaLaSfarsit(ListaDubla* lista, Masina masinaNoua )
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = NULL;
	nou->prev = lista->last;
	if (lista->last != 0)
	{
		lista->last->next = nou;
	}
	else
	{
		lista->first= nou;
	}
	lista->last = nou;
	lista->nrNoduri++;
}

void adaugaMasinaInListaLaInceput(ListaDubla* lista, Masina masinaNoua)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->prev = NULL;
	nou->next = lista->first;
	if (lista->first != 0)
	{
		lista->first->prev = nou;
	}
	else
	{
		lista->last=nou;
	}
	lista->first = nou;
	lista->nrNoduri++;
}

ListaDubla citireMasiniDinFisierInLista(const char* numeFisier)
{
	FILE* file = fopen("masini", "r");
	ListaDubla* lista = NULL;
		while (!feof(file))
		{
				adaugaMasinaInListaLaInceput(&lista, citireMasiniDinFisier(file));
		}
		fclose(file);
		return* lista;
}
void initializareListaNULL(ListaDubla* lista)
{
	lista->first = NULL;
	lista->last = NULL;
	lista->nrNoduri = 0;
}

void dezalocareLista(ListaDubla** lista)
{
	Nod* nou = (*lista)->first;
	while (nou)
	{
		Nod* aux = nou;
		nou = nou->next;
		free(aux->info.denumire);
		free(aux);
	}
	free(*lista);
	*lista = NULL;
}

int main()
{
	ListaDubla lista;
	lista = citireMasiniDinFisierInLista("masini.txt");
	afisareListaMasiniInceput(lista);
	dezalocareLista(&lista);
	return 0;
}