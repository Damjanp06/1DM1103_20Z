#ifndef _studenci_h
#define _studenci_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;


int wczytaj(student dane[100], char *fnazwa);
int znajdz(char *szukany_kod, char kody_przed[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);
int znajdz_przedmioty(char kody_przed[100][10], char nazwy_przed[100][255],student dane[100], int n);



#endif