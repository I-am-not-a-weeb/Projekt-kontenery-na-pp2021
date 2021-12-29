#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listy.h"
#define K 4

int liczba_linii(FILE* plikfunc)   //zwraca liczbe linii w pliku
{
	int ch, lines = 0;
	while (!feof(plikfunc))
	{
		ch = fgetc(plikfunc);
		if (ch == '\n')
		{
			lines++;
		}
	}
	return lines+1;
}

void spis(FILE* plikfunc, ADRES pierwszafunc,ADRES ostatnifunc, ADRES pomfunc)     //funkcja spisujaca liste z pliku
{
	ADRES pom = pierwszafunc;
	if (pom == NULL) 
	{
		pierwszafunc = pom;
		ostatnifunc = pom;
	}
	else
	{
		ostatnifunc->next;
		ostatnifunc = pom;
	}

	while (pom)
	{
		fscanf(plikfunc, "%d", &pom->d);
		fscanf(plikfunc, "%d", &pom->s);
		fscanf(plikfunc, "%d", &pom->h);
		fscanf(plikfunc, "%d", &pom->yop);
		pom = pom->next;
	}
}

void WypiszListe(ADRES pierwszy)
{
	ADRES pom = pierwszy;
	while (pom)
	{
		printf("%d %d %d %d", pom->d, pom->s, pom->h, pom->yop);
		pom = pom->next;
	}
}

int main()
{
	//ADRES pierwszy = NULL, ostatni = NULL, pom;
	//pom = (ADRES)malloc(sizeof(LISTA));
	FILE *plik = fopen("kontenery.txt", "r");
	if (!plik) { printf("Plik nie mogl zostac otwarty."); return 1; }
	int w = liczba_linii(plik);
	int k = 5;

	int** tab = (int**)malloc(w * sizeof(int*));
	for (int i = 0; i < w; i++)
	{
		tab[i] = (int*)malloc(k * sizeof(int));      ///   C6386
	}

	for (int i = 0; i < w; i++)
	{
		fscanf(plik, "%d %d %d %d %d", &tab[i][0], &tab[i][1], &tab[i][2], &tab[i][3], &tab[i][4]);     ///     C6385
	}

	for (int i = 0; i < w; i++)
	{
		printf(plik, "%d %d %d %d %d", tab[i][0], tab[i][1], tab[i][2], tab[i][3], tab[i][4]);     ///wyjątek podczas kompilacji
	}
	//printf("Wpisz objetosc metryczna ladunku: ");

	//scanf("%d", &obj);
	//printf("\n");
		
	//spis(plik, pierwszy,ostatni,pom);
	//printf("%d %d %d %d", pom->d, pom->s, pom->h, pom->yop); 




}