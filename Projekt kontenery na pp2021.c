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
	return lines + 1;

}

void spis(int tab[], t_element** adpocz, int liczba_linii_func)     //funkcja spisujaca liste z pliku, polaczyc z sortowaniem
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
		temp->obj = ((temp->d) / 100) * ((temp->s) / 100) * ((temp->h) / 100);
		temp->next = *adpocz;
		*adpocz = temp;
	}
}
void WypiszListe(t_element* poczatek)
{
	while (poczatek)
	{
		printf("ID: %d ", poczatek->id);
		printf("Dlugosc: %d ", poczatek->d);
		printf("Szerokosc: %d ", poczatek->s);
		printf("Glebokosc: %d ", poczatek->h);
		printf("Rok: %d ", poczatek->yop);
		printf("Wartosc: %d ", poczatek->v);
		printf("Objetosc: %f \n", poczatek->obj);

		poczatek = poczatek->next;
	}
}
t_element* dodajNaKoncu(int dfunc, int sfunc, int gfunc, double objfunc, int rzfunc,int valfunc, t_element* koniec,int i)
{
	t_element* wsk;

	wsk = (t_element*)malloc(sizeof(t_element));

	wsk->d = dfunc;
	wsk->s = sfunc;
	wsk->h = gfunc;
	wsk->obj = objfunc;
	wsk->yop = rzfunc;
	wsk->v = valfunc;
	wsk->id = i;
	wsk->next = NULL;
	if (koniec) koniec->next = wsk;
	return wsk;
}
t_element* wstawElement(int dfunc, int sfunc, int gfunc, double objfunc, int rzfunc,int valfunc, t_element* poczatek, int i)
{
	t_element* temp, * poprzednik, * nastepnik;
	temp = (t_element*)malloc(sizeof(t_element));
	temp->d = dfunc;
	temp->s = sfunc;
	temp->h = gfunc;
	temp->obj = objfunc;
	temp->yop = rzfunc;
	temp->v = valfunc;
	temp->id = i;
	poprzednik = NULL;
	nastepnik = poczatek;
	while (nastepnik != NULL)
	{
		if(nastepnik->obj!=objfunc)
		if (nastepnik->obj < objfunc)
		{
			temp->next = nastepnik;
			if (poprzednik != NULL)               //dolaczanie wewnatrz listy
			{
				poprzednik->next = temp;
				return poczatek;
			}
			else return temp;                    //dolaczanie na poczatku listy
		}
		else
		{
			poprzednik = nastepnik;
			nastepnik = poprzednik->next;
		}
		else if(nastepnik->yop < rzfunc)
		{
			temp->next = nastepnik;
			if (poprzednik != NULL)               //dolaczanie wewnatrz listy
			{
				poprzednik->next = temp;
				return poczatek;
			}
			else return temp;                    //dolaczanie na poczatku listy
		}
		else
		{
			poprzednik = nastepnik;
			nastepnik = poprzednik->next;
		}
	}
	temp->next = NULL;                  //dolaczanie na koncu listy
	poprzednik->next = temp;
	return poczatek;
}

double objcal(t_element* poczatek)
{
	
	double suma = 0;
	while (poczatek)
	{
		suma+=poczatek->obj;
		poczatek = poczatek->next;
	}
	return suma;
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


	int dl, sz, gl, rz, war;
	double obj;

	t_element* poczatek=NULL, * koniec;
	for (int i = 0; i < w; i++)
	{
		fscanf(plik, "%d %d %d %d %d", &dl, &sz, &gl, &rz, &war);
		obj = 1.0*((dl/100.0) * (sz/100.0) * (gl/100.0));
		if (i == 0)poczatek = koniec = dodajNaKoncu(dl,sz,gl,obj, rz, war,NULL,i);
		else
		poczatek=wstawElement(dl,sz,gl,obj,rz,war,poczatek,i);

	}
	

	WypiszListe(poczatek);
	printf("\n");
	int objprz;
	printf("Podaj objetosc: ");
	scanf("%d", &objprz);
	if (objprz > objcal(poczatek)) 
	{
		printf("Ilosc kontenerow z danymi pojemnoscia nie starczy do przerzutu paczk"); return 0;
	}
	//jakie kontenery sa potrzebne do przerzutu
	//wypisac te kontenery i usunac je
	//funkcja wyszukujaca kontenery po id i kasujaca je
	getch();
}
