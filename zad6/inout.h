#ifndef _inout_h
#define _inout_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct macierz
{
    int r;
    int c;
    float **tab;
};

struct macierz *wczytaj(FILE *f);
void wypisz(struct macierz *tab);
void zapisz(FILE *h, struct macierz *tab);


#endif