#pragma warning(disable : 4996)
#pragma warning(disable : 6011)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista.h"


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
	t_element* temp;
	temp = (t_element*)malloc(sizeof(t_element));

	temp->d = dfunc;
	temp->s = sfunc;
	temp->h = gfunc;
	temp->obj = objfunc;
	temp->yop = rzfunc;
	temp->v = valfunc;
	temp->id = i;
	temp->next = NULL;
	if (koniec) koniec->next = temp;
	return temp;
}
t_element* wstawElement(int dfunc, int sfunc, int gfunc, double objfunc, int rzfunc,int valfunc, t_element* poczatek, int i)
{
	t_element* temp, * prev, * nexty;
	temp = (t_element*)malloc(sizeof(t_element));
	temp->d = dfunc;
	temp->s = sfunc;
	temp->h = gfunc;
	temp->obj = objfunc;
	temp->yop = rzfunc;
	temp->v = valfunc;
	temp->id = i;
	if (temp->d <= 0 || temp->s <= 0 || temp->h <= 0 || temp->v <= 0) 
	{
		printf("Kontener w linijce %d. pliku zrodlowego zawiera niepoprawne dane, zanim kontynuujesz sprawdz plik zrodlowy", i+1);
		exit(0);
	}
	prev = NULL;
	nexty = poczatek;
	while (nexty != NULL)
	{
		if(nexty->obj!=objfunc)
		if (nexty->obj < objfunc)
		{
			temp->next = nexty;
			if (prev != NULL)             
			{
				prev->next = temp;
				return poczatek;
			}
			else return temp;                   
		}
		else
		{
			prev = nexty;
			nexty = prev->next;
		}
		else if(nexty->yop < rzfunc)
		{
			temp->next = nexty;
			if (prev != NULL)               
			{
				prev->next = temp;
				return poczatek;
			}
			else return temp;                    
		}
		else
		{
			prev = nexty;
			nexty = prev->next;
		}
	}
	temp->next = NULL;                 
	prev->next = temp;
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
t_element* usunPoczatek(t_element* poczatek)
{
	t_element* wsk;
	wsk = poczatek->next;
	free(poczatek);
	return wsk;
}
t_element* kontenery(t_element* poczatek, double objfunc)
{
	while ((objfunc > 0)&&(poczatek->next!=NULL))
	{	
		printf("Kontenery do uzycia:\n");
		{
			printf("ID: %d ", poczatek->id);
			printf("Dlugosc: %d ", poczatek->d);
			printf("Szerokosc: %d ", poczatek->s);
			printf("Glebokosc: %d ", poczatek->h);
			printf("Rok: %d ", poczatek->yop);
			printf("Wartosc: %d ", poczatek->v);
			printf("Objetosc: %f \n", poczatek->obj);
		}
		objfunc = objfunc - poczatek->obj;
		poczatek->next = usunPoczatek(poczatek);
		poczatek = poczatek->next;
	}
	return poczatek;
}



int main()
{

	FILE* plik;
	plik = fopen("kontenery.txt", "r");
	if (!plik) { printf("Plik nie mogl zostac otwarty."); return 1; }
	int w = liczba_linii(plik);
	fclose(plik);				//reset pliku
	plik = fopen("kontenery.txt", "r");
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
		printf("Ilosc kontenerow na stanie nie starczy do transportu"); return 0;
	}
	else poczatek = kontenery(poczatek,objprz);
	
	printf("\nLista kontenerow na stanie po odebraniu zamowienia na: %d metrow szesciennych ladunku:\n", objprz);
	WypiszListe(poczatek);
	printf("\n");
	getch();
}
