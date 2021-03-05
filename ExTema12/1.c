#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define cit(a) scanf("%s", a);

typedef struct imprimanta
{
	char model[30];
	int pret;
	struct imprimanta *urm;
}nod;

nod *citire(nod *prim) // Inserarea unui nod la inceput
{
	char model[30];
	int pret = 0;
	nod *p;
	printf("Model: "); cit(model);
	int i, dim = strlen(model);
	for (i = 0; i < dim; i++)
		pret = pret + (int)model[i];
	p = (nod*)malloc(sizeof(nod));
	if (p == NULL)
	{
		printf("Eroare la alocare.");
		exit(0);
	}
	else
	{
		strcpy(p->model, model);
		p->pret = pret;
		p->urm = NULL;
		if (prim == NULL)
			return p;
		else
		{
			p->urm = prim;
			return p;
		}
	}
}

void afisare(nod *prim) // Afisarea nodurilor
{
	nod *p;
	for (p = prim; p != NULL; p = p->urm)
		printf("%s %d\n", p->model, p->pret);
}

nod *stergere(nod *prim) // Stergerea primului nod din lista simplu inlantuita
{
	nod *p, *q;
	if (prim != NULL)
	{
		q = prim;
		prim = prim->urm;
		q = NULL;
		return prim;
	}
	else
		return prim;
}

void salvareFisier(nod *prim) // Salvarea nodurilor ramase in fisier text
{
	FILE *f;
	f = fopen("imprimante.txt", "wt");
	nod *p;
	int k = 0;
	for (p = prim; p != NULL; p = p->urm)
	{
		fprintf(f, "%s %d", p->model, p->pret);
		k = 1;
	}
	if (k)
		printf("Datele s-au salvat cu succes.\n");
	else
		printf("Lista e eliberata. Nu mai sunt imprimante de salvat.\n");
	fclose(f);
}

int main()
{
	nod *prim = NULL;
	int continuare = 1, optiune;

	printf("0. Iesire\n");
	printf("1. Adaugarea unei noi imprimante in stocul magazinului\n");
	printf("2. Afisarea imprimantelor din magazin\n");
	printf("3. Stergerea primei imprimante si salvarea restul imprimantelor in fisier text\n\n");

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
				prim = citire(prim);
				printf("\n");
				continuare = 1;
				break;
			}
			case 2:
			{
				afisare(prim);
				printf("\n");
				continuare = 1;
				break;
			}
			case 3:
			{
				prim = stergere(prim);
				salvareFisier(prim);
				printf("\n");
				continuare = 1;
				break;

			}
			default:
			{
				printf("Optiune invalida.\n");
				continuare = 1;
				break;
			}
		}
	}
	_getch();
	return 0;
}