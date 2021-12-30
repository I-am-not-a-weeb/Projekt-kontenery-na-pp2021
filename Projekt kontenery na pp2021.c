#pragma warning(disable : 4996)
#pragma warning(disable : 6011)
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

void spis(int tab[], t_element ** adpocz,int liczba_linii_func)     //funkcja spisujaca liste z pliku, polaczyc z sortowaniem
{
	t_element* temp;
	*adpocz = NULL;
	for (int i = 0; i < liczba_linii_func; i++)
	{
		temp = (t_element*)malloc(sizeof(t_element));
		temp->d = tab[i * 5];
		temp->s = tab[i * 5 + 1];
		temp->h = tab[i * 5 + 2];
		temp->yop = tab[i * 5 + 3];
		temp->v = tab[i * 5 + 4];
		temp->obj = ((temp->d)/100) * ((temp->s)/100) * ((temp->h)/100);
		temp->next = *adpocz;
		*adpocz = temp;
	}
}

void sort_listy(int tab[],t_element *adpocz,int liczba_linii_func)
{
	t_element* temp;
	t_element* e, * p;
	int v;


	temp = (t_element*)malloc(sizeof(t_element));
	temp->next = (t_element*)malloc(sizeof(t_element));
	temp->next->next = NULL;
	temp->next->obj = 2147483647;

	for (int i = 0; i < liczba_linii_func; i++)
	{


		v = adpocz->obj;

		for (p = temp; v > p->next->obj; p = p->next);
		
		e = (t_element*)malloc(sizeof(t_element));
		e->obj = v;
		e->next = p->next;
		p->next = e;
		adpocz = adpocz->next;
	}
	for (p = temp->next; p->next; p = p->next) printf("%d ", p->obj);
	printf("\n");
}

void WypiszListe(t_element * poczatek)
{
	while (poczatek)
	{
		printf("%d ", poczatek->d);
		printf("%d ", poczatek->s);
		printf("%d ", poczatek->h);
		printf("%d ", poczatek->yop);
		printf("%d ", poczatek->v);
		printf("%d \n", poczatek->obj);
		poczatek = poczatek->next;
	}
}

int main()
{

	FILE* plik;
	plik = fopen("abc.txt", "r");
	if (!plik) { printf("Plik nie mogl zostac otwarty."); return 1; }
	int w = liczba_linii(plik);
	fclose(plik);

	plik = fopen("abc.txt", "r");
	if (!plik) { printf("Plik nie mogl zostac otwarty."); return 1; }

	int* tab = NULL;
	tab = (int*)malloc(w * 5 * sizeof(int));
	for (int i = 0; i < w*5;)
	{
		fscanf(plik, "%d %d %d %d %d", &tab[i], &tab[i + 1], &tab[i + 2], &tab[i + 3], &tab[i + 4]);
		i += 5;
	}
	for (int i = 0; i < w*5;)
	{
		printf("%d %d %d %d %d\n", tab[i], tab[i + 1], tab[i + 2], tab[i + 3], tab[i + 4]);
		i += 5;
	}
	t_element* poczatek;
	spis(tab, &poczatek, w);
	WypiszListe(poczatek);
	sort_listy(tab,poczatek, w);
	printf("\n");
}
