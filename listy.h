#pragma once

typedef struct element
{
	int d, s, h, yop, v, obj; // d - szerokosc, s - dlugosc, h - glebokosc, yop - rok produkcji, v - wartosc
	struct element* next;
} t_element;

//typedef struct lista LISTA;
//typedef LISTA* ADRES;