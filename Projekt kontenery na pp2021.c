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
		fscanf(plikfunc , "%d %d %d %d" , pom->d, pom->s,pom->h,pom->yop);
		pom = pom->next;
	}
}

int main()
{
	ADRES pierwszy = NULL, ostatni = NULL, pom;
	pom = (ADRES)malloc(sizeof(LISTA));
	int obj;

	FILE* plik = fopen("kontenery.txt", "r");
	printf("Wpisz objetosc metryczna ladunku: "); 

	printf("\n");
	spis(plik,pierwszy);
	printf("%d %d %d %d", pom->d, pom->s, pom->h, pom->yop);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
