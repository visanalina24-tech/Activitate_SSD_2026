//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Masina Masina;
//
//struct Masina {
//	int id;
//	char* denumire;
//	char marca;
//	int caiPutere;
//	float pret;
//};
//struct Masina initializare(int id, const char* denumire, char marca, int caiPutere, float pret)
//{
//	struct Masina m;
//	m.id = id;
//	//m.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
//	m.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
//	strcpy_s(m.denumire, strlen(denumire) + 1, denumire);
//	m.marca = marca;
//	m.caiPutere = caiPutere;
//	m.pret = pret;
//
//	return m;
//}
//struct Masina copiaza(struct Masina m)
//{
//	return (initializare(m.id, m.denumire, m.marca, m.caiPutere, m.pret));
//}
//void afiseaza(struct Masina m)
//{
//	printf("%d. Masina %s de marca %c are %d cai putere si costa %5.2f euro.\n", m.id, m.denumire, m.marca, m.caiPutere, m.pret);
//}
//void afisareVector(struct Masina* vector, int nrElemente)
//{
//	if (vector != NULL && nrElemente > 0) {
//		for (int i = 0; i < nrElemente; i++) {
//			afiseaza(vector[i]);
//		}
//	}
//}
//struct Masina* copiazaPrimeleNElemente(struct Masina* vector, int nrElemente, int nrElementeCopiate)
//{
//	struct Masina* vectorNou = NULL;
//	vectorNou = (struct Masina*)malloc(sizeof(Masina) * nrElementeCopiate);
//
//	for (int i = 0; i < nrElementeCopiate; i++)
//	{
//
//		vectorNou[i] = vector[i];
//		vectorNou[i].denumire = (char*)malloc(strlen(vector[i].denumire) + 1); //pt ca am char*
//		strcpy_s(vectorNou[i].denumire, strlen(vector[i].denumire) + 1, vector[i].denumire);
//	}
//	return vectorNou;
//
//}
//void dezalocare(struct Masina** vector, int* nrElemente)
//{
//	for (int i = 0; i < (*nrElemente); i++)
//	{
//		free((*vector)[i].denumire);
//
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//void copiazaMasiniScumpe(struct Masina* vector, int nrElemente, float pretMinim, struct Masina** vectorNou, int* dimensiune)
//{
//	*dimensiune = 0;
//	for (int i = 0; i < nrElemente; i++)
//	{
//		if (vector[i].pret >= pretMinim)
//		{
//			(*dimensiune)++;
//		}
//
//	}
//	if (*vectorNou != NULL)
//	{
//		free(*vectorNou);
//	}
//	*vectorNou = (struct Masina*)malloc(sizeof(struct Masina) * (*dimensiune));
//	int k = 0;
//	for (int i = 0; i < nrElemente; i++)
//	{
//		if (vector[i].pret >= pretMinim)
//		{
//			(*vectorNou)[k] = vector[i];
//			(*vectorNou)[k].denumire = (char*)malloc(strlen(vector[i].denumire) + 1);
//			strcpy_s((*vectorNou)[k].denumire, strlen(vector[i].denumire) + 1, vector[i].denumire);
//			k++;
//		}
//
//	}
//}
//struct Masina getPrimaDenumireMasina(struct Masina* vector, int nrElemente, const char* denumire)
//
//{
//
//	struct Masina m;
//
//	m.denumire = NULL;
//
//	for (int i = 0; i < nrElemente; i++)
//
//	{
//
//		if (strcmp(vector[i].denumire, denumire) == 0)
//
//		{
//
//			m = vector[i];
//
//			m.denumire = (char*)malloc(strlen(vector[i].denumire) + 1);
//
//			strcpy_s(m.denumire, strlen(vector[i].denumire) + 1, vector[i].denumire);
//
//			return m;
//
//		}
//
//	}
//
//}
//
//
//
//int main()
//{
//	struct Masina masina = initializare(1, "Sandero", 'D', 100, 16000);
//	afiseaza(masina);
//
//	int nrMasini = 3;
//	struct Masina* masini = (struct Masina*)malloc(sizeof(struct Masina) * nrMasini);
//	masini[0] = initializare(2, "BMW", 'B', 200, 200000);
//	masini[1] = initializare(3, "Golf", 'W', 50, 1000);
//	masini[2] = initializare(4, "Octavia", 'S', 100, 2100);
//	
//	afisareVector(masini, nrMasini);
//
//	struct Masina* primeleMasini = NULL;
//	int nrPrimeleMasini = 2;
//	primeleMasini = copiazaPrimeleNElemente(masini, nrMasini, nrPrimeleMasini);
//	printf("\n");
//	printf("\nPrimele masini:\n");
//	afisareVector(primeleMasini, nrPrimeleMasini);
//
//	dezalocare(&primeleMasini,& nrPrimeleMasini);
//	afisareVector(primeleMasini, nrPrimeleMasini);
//	
//	struct Masina* masiniScumpe = NULL;
//	int nrMasiniScumpe = 0;
//	copiazaMasiniScumpe(masini, nrMasini, 3000, &masiniScumpe, &nrMasiniScumpe);
//	printf("\n");
//	printf("\n Masinile scumpe sunt: \n");
//	afisareVector(masiniScumpe, nrMasiniScumpe);
//
//	dezalocare(&masiniScumpe, &nrMasiniScumpe);
//
//
//	struct Masina masina1 = getPrimaDenumireMasina(masini, nrMasini, "BMW");
//
//	printf("\n");
//
//	printf("\n Prima masina gasita:\n");
//
//	afiseaza(masina1);
//
//	if (masina1.denumire != NULL)
//
//	{
//
//		free(masina1.denumire);
//
//		masina1.denumire = NULL;
//
//	}
//	free(masina.denumire);
//	dezalocare(&masini, &nrMasini);
//
//	return 0;
//}
//
//
////typedef struct Depozit Depozit;
////
////struct Depozit {
////	int id;
////	float suprafata;
////	int volum;
////	char* denumire;
////	char clasa;
////};
////struct Depozit initializare(int id, float suprafata, int volum, const char* denumire, char clasa) {
////	struct Depozit s;
////	s.id = id;
////	s.suprafata = suprafata;
////	s.volum = volum;
////	s.denumire = (char*)malloc(sizeof(char)*(strlen(denumire)+1));
////	strcpy(s.denumire, denumire);
////	s.clasa = clasa;
////	return s;
////}
////
////Depozit copiaza(Depozit d) {
////	return initializare(d.id,d.suprafata,d.volum,d.denumire,d.clasa);
////}
////
////void afisare(struct Depozit s) {
////	printf("%d. Depozitul %s de clasa %c are o suprafata de %5.2f si un volum de %d.\n",
////		s.id, s.denumire, s.clasa, s.suprafata, s.volum);
////	// %d - int, %c - char, %s - string, %f -float
////}
//
////void afisareVector(struct Depozit* vector, int nrElemente) {
////	for (int i = 0; i < nrElemente; i++) {
////		afisare(*(vector+i));		
////	}
////}
////
////struct Depozit* copiazaPrimeleNElemente(Depozit* vector, int nrElemente, int nrElementeCopiate) {
////	if (nrElementeCopiate < nrElemente) {
////		struct Depozit* vectorNou = malloc(sizeof(Depozit) * nrElementeCopiate);
////		for (int i = 0; i < nrElementeCopiate; i++) {
////			vectorNou[i] = copiaza(vector[i]);
////		}
////		return vectorNou;
////	}
////	else {
////		return NULL;
////	}
////}
////
////void dezalocare(struct Depozit** vector, int* nrElemente) {
////	for (int i = 0; i < *nrElemente; i++) {
////		free((*vector)[i].denumire);
////	}
////	free(*vector);
////	*nrElemente = 0;
////	*vector = NULL;
////}
////
////void copiazaAnumiteElemente(struct Depozit* vector, char nrElemente, float prag, struct Depozit** vectorNou, int* dimensiune) {
////	*dimensiune = 0;
////	for (int i = 0; i < nrElemente; i++) {
////		if (vector[i].suprafata < prag) {
////			(*dimensiune)++;
////		}
////	}
////	*vectorNou = malloc(sizeof(Depozit) * (*dimensiune));
////	*dimensiune = 0;
////	for (int i = 0; i < nrElemente; i++) {
////		if (vector[i].suprafata < prag) {
////			(*vectorNou)[*dimensiune] = copiaza(vector[i]);
////			(*dimensiune)++;
////		}
////	}
////}
////
////struct Depozit getPrimulElementConditionat(struct Depozit* vector, int nrElemente, const char* numeCautat) {
////	Depozit s;
////	s.id = -1;
////	s.denumire = NULL;
////	for (int i = 0; i < nrElemente; i++) {
////		if (strcmp(numeCautat, vector[i].denumire)==0) {
////			s = copiaza(vector[i]);
////		}
////	}
////	return s;
////}
////	
////
////
////	int main() {
//	//	struct Depozit depozit = initializare(1, 34.3, 70, "Emag", 'A');
//		//afisare(depozit);
//	//}
//
////	int nrDepozite = 4;
////	Depozit* vector = (Depozit*)malloc(sizeof(Depozit)*nrDepozite);
////	vector[0] = initializare(2, 34, 45, "DPD", 'B');
////	vector[1] = initializare(3, 56, 89, "Amazon", 'A');
////	vector[2] = initializare(4, 45, 96, "DSC", 'A');
////	vector[3] = initializare(5, 34, 67, "Emag", 'A');
////	
////	afisareVector(vector, nrDepozite);
////	printf("\n\n");
////	int nrCopiate=2;
////	Depozit* scurt = copiazaPrimeleNElemente(vector, nrDepozite, nrCopiate);
////
////	afisareVector(scurt, nrCopiate);
////	dezalocare(&scurt, &nrCopiate);
////	Depozit* filtrat = NULL;
////	int dimensiune = 0;
////	copiazaAnumiteElemente(vector, nrDepozite, 50, &filtrat, &dimensiune);
////	printf("\nVector filtrat:\n");
////	afisareVector(filtrat, dimensiune);
////	dezalocare(&filtrat, &dimensiune);
////
////	Depozit depozitCautat = getPrimulElementConditionat(vector, nrDepozite, "Amazon");
////	printf("\nDepozit cautat:\n");
////	afisare(depozitCautat);
////	if (depozitCautat.id != -1) {
////		free(depozitCautat.denumire);
////	}
////	free(depozit.denumire);
////	dezalocare(&vector, &nrDepozite);
////	return 0;
//////}