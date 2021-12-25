#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listy.h"


void spis(FILE* plikfunc, ADRES pierwsza)     //funkcja spisujaca liste z pliku
{
	ADRES pom = pierwsza;
	while (pom)
	{
		fscanf(plikfunc, "%d", pom->d);
		pom = pom->next;
	}
}

int main()
{
	ADRES pierwszy = NULL, ostatni = NULL, pom=NULL;
	pom = (ADRES)malloc(sizeof(LISTA));

	int obj;

	FILE * plik = fopen("kontenery.txt", "r");
	printf("Wpisz objetosc metryczna ladunku: "); 

	printf("\n");
	spis(plik, pierwszy);
	printf("%d %d %d %d", pom->d, pom->s, pom->h, pom->yop);
}
