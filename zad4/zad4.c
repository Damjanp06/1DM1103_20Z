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

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

int znajdz(char *szukany_kod, char kody_przed[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_kod, kody_przed[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kody_przed[100][10], char nazwy_przed[100][255],student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i < n; i++) {
        if (znajdz(dane[i].kod_przed, kody_przed, ile_znalazlem ) == -1) {
            strncpy(kody_przed[ile_znalazlem], dane[i].kod_przed, 9);
            strncpy(nazwy_przed[ile_znalazlem], dane[i].nazwa_przed, 254);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char kody_przed[100][10];
    char nazwy_przed[100][255];
    int ile_przedmiotow;
    float sumy_ocen[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    int ilosc_wystapien[100];

    ile_przedmiotow = znajdz_przedmioty(kody_przed, nazwy_przed, dane, ile_rekordow);
    for(int k = 0; k < (ile_rekordow+1); k++) //zeruje miejsca na sumy ocen, aby pozbyć się błędu który powodował pojawianie się losowych wartości i uniemożliwiał obliczenie sumy dla dwóch pierwszych przedmiotów
        {
        sumy_ocen[k] = 0;
        ilosc_wystapien[k] = 0;
        }
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kody_przed, ile_przedmiotow );
        // if (pozycje >= 0)
        sumy_ocen[pozycja] += dane[i].ocena;
        ilosc_wystapien[pozycja]++;
    }    
    float srednia = sumy_ocen[0]/ilosc_wystapien[0];
    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < sumy_ocen[i] / ilosc_wystapien[i]) {
            najlepsza = sumy_ocen[i] / ilosc_wystapien[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepsza średnia: %s - %s: %f\n", kody_przed[najlepsza_pozycja], nazwy_przed[najlepsza_pozycja], sumy_ocen[najlepsza_pozycja] / ilosc_wystapien[najlepsza_pozycja]);


}

void najgorszy_przedmiot(student dane[100], int ile_rekordow) {
    char kody_przed[100][10];
    char nazwy_przed[100][255];
    int ile_przedmiotow;
    float sumy_ocen[100];
    float srednie[100];
    int i;
    int pozycja;
    int najgorsza_pozycja;
    float najgorsza = 5.0f;
    int ilosc_wystapien[100];

    ile_przedmiotow = znajdz_przedmioty(kody_przed, nazwy_przed, dane, ile_rekordow);
    for(int k = 0; k < (ile_rekordow+1); k++) //zeruje miejsca na sumy ocen, aby pozbyć się błędu który powodował pojawianie się losowych wartości i uniemożliwiał obliczenie sumy dla dwóch pierwszych przedmiotów
        {
        sumy_ocen[k] = 0;
        ilosc_wystapien[k] = 0;
        }
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kody_przed, ile_przedmiotow );
        // if (pozycje >= 0)
        sumy_ocen[pozycja] += dane[i].ocena;
        ilosc_wystapien[pozycja]++;
    }    
    float srednia = sumy_ocen[0]/ilosc_wystapien[0];
    for (i=0; i < ile_przedmiotow; i++) {
        if (najgorsza > sumy_ocen[i] / ilosc_wystapien[i]) {
            najgorsza = sumy_ocen[i] / ilosc_wystapien[i];
            najgorsza_pozycja = i;
        }
    }
    printf("Najgorsza średnia: %s - %s: %f\n", kody_przed[najgorsza_pozycja], nazwy_przed[najgorsza_pozycja], sumy_ocen[najgorsza_pozycja] / ilosc_wystapien[najgorsza_pozycja]);


}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);

    najlepszy_przedmiot(dane, ile);
    najgorszy_przedmiot(dane, ile);
    return 0;
}