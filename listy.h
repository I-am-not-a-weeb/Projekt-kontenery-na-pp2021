#pragma once

struct lista
{
	int d, s, h, yop, v; // w - szerokosc, s - dlugosc, h - glebokosc, yop - rok produkcji, v - wartosc
	struct lista* next;
};

void spis(FILE *plikfunc, ADRES pierwszy)     //funkcja spisujaca liste z pliku
{
    ADRES pom = pierwszy;
    while (pom)
    {
        fscanf(plikfunc, pom->d, pom->s, pom->h, pom->yop, pom->v);
        pom = pom->next;
    }
}

typedef struct lista LISTA;
typedef LISTA* ADRES;