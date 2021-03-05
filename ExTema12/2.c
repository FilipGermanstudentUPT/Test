#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct telefon // Definirea structurii si a elementelor sale
{
	char marca[20];
	int pret;
}T;

void citire(T *telefon, int *n) // Adaugarea unui telefon nou
{
	(*n)++;
	int i, corect = 0, dim = strlen((telefon + *n)->marca);
	while (!corect)
	{
		printf("Marca: "); scanf("%s", (telefon + *n)->marca);
		if ((telefon + *n)->marca[0] >= 'A' && (telefon + *n)->marca[0] <= 'Z')
		{
			corect = 1;
			for (i = 1; i < dim; i++)
			{
				if (!(((telefon + *n)->marca[i] >= 'a' && (telefon + *n)->marca[i] <= 'z') || ((int)(telefon + *n)->marca[i] >= 48 && (int)(telefon + *n)->marca[i] <= 57) || (telefon + *n)->marca[i] >= 'A' && (telefon + *n)->marca[i] <= 'Z'))
				{
					printf("Cerintele nu sunt respectate. Va rog introduceti datele din nou\n");
					corect = 0;
				}
			}
		}
		else
		{
			printf("Prima litera trebuie sa fie majuscula. Va rog introduceti datele din nou.\n");
			corect = 0;
		}
		if (corect)
			printf("Pret: "); scanf("%d", &(telefon + *n)->pret);
	}
}

void afisareTelefon(T *telefon, int n) // afisarea unui singur telefon
{
	printf("%s %d\n", (telefon + n)->marca, (telefon + n)->pret);
}

void afisareToateTelefoane(T *telefon, int *n)// afisarea tuturor telefoanelor
{
	int i;
	for (i = 0; i <= (*n); i++)
		afisareTelefon(telefon, i);
}

void salvareFisier(T *telefon, int *n) // salvarea telefoanelor in fisier
{
	FILE *f = fopen("telefoane_ieftine.txt", "wt");
	int i, pret1, k = 0;
	printf("Pret: "); scanf("%d", &pret1);
	for (i = 0; i <= (*n); i++)
	{
		if ((telefon + i)->pret < pret1)
		{
			k = 1;
			fprintf(f, "%d", (telefon + i)->pret);
		}
	}
	if (k)
		printf("Datele s-au salvat cu succes.\n");
	else
		printf("Nu exista telefoane cu pretul mai mic decat %d ", pret1);
	fclose(f);
}

int main()
{
	T telefon[50];
	int n = -1, optiune, continuare = 1;

	printf("0. Iesire\n");
	printf("1. Adaugarea unui nou telefon in stocul magazinului(forma: prima litera mare, urmatoarele caractere sunt litere sau numere!)\n");
	printf("2. Afisarea telefoanelor din magazin\n");
	printf("3. Salvarea telefoanelor cu pretul mai mic decat un pret citit de la tastatura, intr-un fisier text\n\n");

	while (continuare)
	{
		printf("Optiunea dvs: "); scanf("%d", &optiune);
		switch (optiune)
		{
			case 0:
			{
				continuare = 0;
				break;
			}
			case 1:
			{
				citire(&telefon[0], &n);
				printf("\n");
				continuare = 1;
				break;
			}
			case 2:
			{
				afisareToateTelefoane(telefon, &n);
				printf("\n");
				continuare = 1;
				break;
			}
			case 3:
			{
				salvareFisier(telefon, &n);
				printf("\n");
				continuare = 1;
				break;
			}
			default:
			{
				printf("Optiune invalida.\n\n");
				continuare = 1;
				break;
			}
		}
	}
	_getch();
	return 0;
}

// mic bug la citire, afiseaza "Marca: " dupa citirea elementului nou
// de facut: salvareFisier()
// terminat: citire() ; afisare()
