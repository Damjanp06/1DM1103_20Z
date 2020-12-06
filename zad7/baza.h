#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast_s;
} Student;

typedef struct _Przedmiot {
    char * nazwa;
    char * sem;
    char * kod_przedmiotu;

    struct _Przedmiot *nast_p;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;

    char * ocena;
    char * komentarz;

    struct _Ocena *nast_o;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow; /* Głowa listy! */
    Ocena *lista_ocen; /* Głowa listy! */

} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
void zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void listuj_oceny(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
SBaza *dodaj_studenta(SBaza *baza, char * imie, char * nazwisko, char * nr_albumu, char * email);
SBaza *dodaj_przedmiot(SBaza *baza, char * nazwa, char * sem, char * kod_przedmiotu);
SBaza *dodaj_studenta_do_przedmiotu(SBaza *baza, char * nr_albumu, char * kod_przedmiotu);


#endif