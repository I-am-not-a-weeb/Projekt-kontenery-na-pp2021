#pragma once

struct lista
{
	int w, d, h, yop, v; // w - szerokosc, d - dlugosc, h - wysokosc, yop - rok produkcji, v - wartosc
	struct lista* nast;
};

typedef struct lista LISTA;
typedef LISTA* adres;