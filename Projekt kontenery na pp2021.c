#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listy.h"


void spis(FILE* plikfunc, ADRES pierwsza, lista **adres1, lista* nowy)     //funkcja spisujaca liste z pliku
{
	ADRES pom = pierwsza;
	if (pom==NULL) pom = pom->next;
	while (pom)
	{
		pom = pom->next;
	}

	
	while (*adres1 != NULL) adres1 = &((*adres1)->next);
	*adres1 = nowy;
	nowy->next = NULL;
	}
	
	
	
	

}

int main()
{
	ADRES pierwszy = NULL, ostatni = NULL, pom = NULL;
	pom = (ADRES)malloc(sizeof(LISTA));

	int obj;

	FILE* plik = fopen("kontenery.txt", "r");

	printf("Wpisz objetosc metryczna ladunku: ");
	if(scanf("%d", &obj)<=0)printf("nieprawidlowa objetosc");
	printf("\n");

	spis(plik, pierwszy);
	printf("%d %d %d %d", pom->d, pom->s, pom->h, pom->yop);
}
