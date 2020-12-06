#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa_s = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast_s = NULL;

        if (last_student == NULL)
            glowa_s = stud;
        else
            last_student->nast_s = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa_s;
}

Przedmiot * wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa_p = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast_p = NULL;

        if (last_przedmiot == NULL)
            glowa_p = przed;
        else
            last_przedmiot->nast_p = przed;
        last_przedmiot = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa, s);

        s = strtok(NULL, ";");
        przed->sem = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->sem, s);

        s = strtok(NULL, "\n");
        przed->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przedmiotu, s);

    }

    return glowa_p;
}

Ocena * wczytaj_oceny(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_ocena = NULL;
    Ocena *glowa_o = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *oc = (Ocena*) malloc(sizeof(Ocena));
        oc->nast_o = NULL;

        if (last_ocena == NULL)
            glowa_o = oc;
        else
            last_ocena->nast_o = oc;
        last_ocena = oc;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        oc->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->nr_albumu, s);

        s = strtok(NULL, ";");
        oc->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        oc->ocena = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->ocena, s);

        s = strtok(NULL, "\n");
        oc->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->komentarz, s);


    }

    return glowa_o;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast_s;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot * przed = baza->lista_przedmiotow;
    while (przed != NULL) {
        n++;
        przed = przed->nast_p;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena * oc = baza->lista_ocen;
    while (oc != NULL) {
        n++;
        oc = oc->nast_o;
    }
    return n;
}

SBaza *dodaj_studenta(SBaza *baza, char * imie, char * nazwisko, char * nr_albumu, char * email) {
    
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *teraz = NULL;
  	nowy->nast_s = NULL;

  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);

    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);
    
    teraz=baza->lista_studentow;
    
    if(ile_studentow(baza) == 0)
    {
      baza->lista_studentow = nowy;
    }
    else
    {
      for(int i=1; i<ile_studentow(baza); i++)
      {
        teraz = teraz->nast_s;
      }
      teraz->nast_s = nowy;
    }   
    return NULL;
}

SBaza *dodaj_przedmiot(SBaza *baza, char * nazwa, char * sem, char * kod_przedmiotu) {
    
    Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
  	Przedmiot *teraz = NULL;
  	nowy->nast_p = NULL;

  	nowy->nazwa = (char*) malloc(sizeof(char) * (strlen(nazwa) + 1));
    strcpy(nowy->nazwa, nazwa);

    nowy->sem = (char*) malloc(sizeof(char) * (strlen(sem) + 1));
    strcpy(nowy->sem, sem);

    nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);

    teraz=baza->lista_przedmiotow;
    
    if(ile_przedmiotow(baza) == 0)
    {
      baza->lista_przedmiotow = nowy;
    }
    else
    {
      for(int i=1; i<ile_przedmiotow(baza); i++)
      {
        teraz = teraz->nast_p;
      }
      teraz->nast_p = nowy;
    }   
    return NULL;
}

SBaza *dodaj_studenta_do_przedmiotu(SBaza *baza, char * nr_albumu, char * kod_przedmiotu) {

    char *ocena = " ";
    char *komentarz = " ";

    Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));
  	Ocena *teraz = NULL;
  	nowy->nast_o = NULL;

  	nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);

    nowy->ocena = (char*) malloc(sizeof(char) * (strlen(ocena) + 1));
    strcpy(nowy->ocena, ocena);

    nowy->komentarz = (char*) malloc(sizeof(char) * (strlen(komentarz) + 1));
    strcpy(nowy->komentarz, komentarz);
    
    teraz=baza->lista_ocen;
    
    if(ile_ocen(baza) == 0)
    {
      baza->lista_ocen = nowy;
    }
    else
    {
      for(int i=1; i<ile_ocen(baza); i++)
      {
        teraz = teraz->nast_o;
      }
      teraz->nast_o = nowy;
    }   
    return NULL;
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    printf("\n");
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast_s;
    }
}

void listuj_przedmioty(SBaza *baza) {
    Przedmiot * przed = baza->lista_przedmiotow;
    printf("\n");
    while (przed != NULL) {
        printf("%s %s %s\n", przed->nazwa, przed->sem, przed->kod_przedmiotu);
        przed = przed->nast_p;
    }
}

void listuj_oceny(SBaza *baza) {
    Ocena * oc = baza->lista_ocen;
    printf("\n");
    while (oc != NULL) {
        printf("%s %s %s %s\n", oc->nr_albumu, oc->kod_przedmiotu, oc->ocena, oc->komentarz);
        oc = oc->nast_o;
    }
}

void listuj_do_pliku_studentow(SBaza *baza, FILE *fout) {
    Student * stud = baza->lista_studentow;
    //printf("\n");
    while (stud != NULL) {
        fprintf(fout, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast_s;
    }
    //printf("\n");
}

void listuj_do_pliku_przedmioty(SBaza *baza, FILE *fout) {
    Przedmiot * przed = baza->lista_przedmiotow;
    //printf("\n");
    while (przed != NULL) {
        fprintf(fout, "%s;%s;%s\n", przed->nazwa, przed->sem, przed->kod_przedmiotu);
        przed = przed->nast_p;
    }
    //printf("\n");
}

void listuj_do_pliku_oceny(SBaza *baza, FILE *fout) {
    Ocena * oc = baza->lista_ocen;
    //fprintf(fout, "\n");
    while (oc != NULL) {
        fprintf(fout, "%s;%s;%s;%s\n", oc->nr_albumu, oc->kod_przedmiotu, oc->ocena, oc->komentarz);
        oc = oc->nast_o;
    }
}

void zapisz_baze(char *nazwa_pliku, SBaza * baza) {
    FILE *fout = fopen(nazwa_pliku, "w");
    fprintf(fout, "%d\n", ile_studentow(baza));
    listuj_do_pliku_studentow(baza, fout);
    fprintf(fout, "%d\n", ile_przedmiotow(baza));
    listuj_do_pliku_przedmioty(baza, fout);
    fprintf(fout, "%d\n", ile_ocen(baza));
    listuj_do_pliku_oceny(baza, fout);

}



void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast_s;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_przedmiot(Przedmiot *s) {
    free(s->nazwa);
    free(s->sem);
    free(s->kod_przedmiotu);
    free(s);
}


void zwolnij_liste_przedmiotow(Przedmiot *s) {
    Przedmiot *n;
    while (s != NULL) {
        n = s->nast_p;
        zwolnij_przedmiot(s);
        s = n;
    }
}

void zwolnij_ocena(Ocena *s) {
    free(s->nr_albumu);
    free(s->kod_przedmiotu);
    free(s->ocena);
    free(s->komentarz);
    free(s);
}

void zwolnij_liste_ocen(Ocena *s) {
    Ocena *n;
    while (s != NULL) {
        n = s->nast_o;
        zwolnij_ocena(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}