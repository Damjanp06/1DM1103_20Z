#include "dziekanat.h"

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

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}