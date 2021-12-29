#pragma once

struct lista
{
	int d, s, h, yop, v; // d - szerokosc, s - dlugosc, h - glebokosc, yop - rok produkcji, v - wartosc
	struct lista* next;
};

typedef struct lista LISTA;
typedef LISTA* ADRES;