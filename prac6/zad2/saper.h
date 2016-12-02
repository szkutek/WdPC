#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR_PLANSZY 8
#define ILOSC_BOMB 10

int koniec_gry=0;

int bomby[ROZMIAR_PLANSZY+1][ROZMIAR_PLANSZY+1]={{0}};
int widok_gry[ROZMIAR_PLANSZY+1][ROZMIAR_PLANSZY+1]={{0}};

int rysuj_plansze(void);
void losuj_bomby(void);
void ruch_gracza(void);
int wykonaj_ruch(void);
void zakoncz_gre(void);
