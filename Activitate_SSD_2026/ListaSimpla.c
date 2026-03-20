//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#include<stdlib.h>
//
//typedef struct Masina Masina;
//
//struct Masina
//{
//	int id;
//	float pret;
//	char* denumire;
//	char marca;
//};
//
//typedef struct Nod Nod;
//
//struct Nod
//{
//	Masina info;
//	Nod* next; // un contor pentru a retine primul nod din lista cu tot cu adresa+ info
//};
//
//void afisareMasina(Masina masina)
//{
//	printf("\n Id: %d", masina.id);
//	printf("\n Pret:%5.2f euro", masina.pret);
//	printf("\n Denumire:%s", masina.denumire);
//	printf("\n Marca:%c", masina.marca);
//}
//Masina citireMasiniDinFisier(FILE* file)
//{
//	char buffer[100];
//	char sep[4] = ",\n";
//	fgets(buffer, 100, file);
//	Masina m;
//	m.id = atoi(strtok(buffer, sep));
//	m.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	m.denumire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy_s(m.denumire, strlen(aux) + 1, aux);
//	m.marca = *strtok(NULL, sep);
//	return m;
//}
//
//void afisareMasinaLista(Nod* cap)
//{
//
//	while(cap != NULL)
//	{
//		afisareMasina(cap->info);
//		cap = cap->next;
//	}
//}
//void adaugaMasinaInLista(Nod** cap, Masina masinaNoua)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//	if (*cap == NULL)
//	{
//		*cap = nou;
//	}
//	else
//	{
//		Nod* p = *cap;
//		while (p->next != NULL)
//		{
//			p = p->next;
//		}
//		p->next = nou;
//	}
//}
//void adaugaMasinaLaInceputDeLista(Nod** cap, Masina masinaNoua)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier)
//{
//	FILE* file = fopen("masini.txt", "r");
//	Nod* cap = NULL;
//		while (!feof(file))
//		{
//			Masina m = citireMasiniDinFisier(file);
//			if (m.id != 0) // Validare simplă
//				adaugaMasinaInLista(&cap, m);
//		}
//		fclose(file);
//		return cap;
//}
//void dezalocareLista(Nod** cap)
//{
//	while (*cap != NULL)
//	{
//		Nod* aux = *cap;
//		*cap = (*cap)->next;
//		free(aux->info.denumire); //DE RETINUT SA PUN FREE SI LA CHAR* DIN STRUCTUTRA
//		free(aux);
//	}
//	free(*cap);
//	*cap = NULL;
//}
//
//int main()
//{
//	Nod* listaMasini = citireListaMasiniDinFisier("masini.txt");
//	afisareMasinaLista(listaMasini);
//	return 0;
//}