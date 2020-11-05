#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz
{
    int r;
    int c;
    float tab[20][20];
};

void wczytaj(FILE *f, struct macierz *m)
{
    fscanf(f, "%d", &m->r);
    fscanf(f, "%d", &m->c);

    for(int i = 0; i < m->r; i++)
        for(int j = 0; j < m->c; j++)
            fscanf(f, "%f", &m->tab[i][j]);
}

struct macierz sum(struct macierz A, struct macierz x)
{
    struct macierz suma;
    suma.r = x.r;
    suma.c = x.c;
        for(int i = 0; i < x.r; i++)
            for(int j = 0; j < x.c; j++)
                suma.tab[i][j] = A.tab[i][j] + x.tab[i][j];
    return suma;
}

struct macierz subtract(struct macierz A, struct macierz x)
{
    struct macierz roznica;
    roznica.r = x.r;
    roznica.c = x.c;
        for(int i = 0; i < x.r; i++)
            for(int j = 0; j < x.c; j++)
                roznica.tab[i][j] = A.tab[i][j] - x.tab[i][j];
    return roznica;
}

struct macierz prod(struct macierz A, struct macierz x)
{
    struct macierz iloczyn;
    iloczyn.r = A.r;
    iloczyn.c = x.c;
    if(A.c == x.r)
    {
        for(int i = 0; i < x.c; i++)
            for(int j = 0; j < A.r; j++)
                for(int k = 0; k < A.c; k++)
                iloczyn.tab[j][i] += A.tab[j][k] * x.tab[k][i];
    }
    else
    {
        printf("Działanie nie może być wykonane."
        "Liczba kolumn w pierwszej macierzy nie "
        "jest równa liczbie wierszy w drugiej macierzy.\n");
    }
    return iloczyn;
}

struct macierz multiply(struct macierz A, float skalar)
{
    struct macierz iloczyn_skalar;
    iloczyn_skalar.r = A.r;
    iloczyn_skalar.c = A.c;
    for(int i = 0; i < A.r; i++)
        for(int j = 0; j < A.c; j++)
            iloczyn_skalar.tab[i][j] = A.tab[i][j] * skalar;
    return iloczyn_skalar;
}

float norm(struct macierz C) 
{
    float suma = 0;
    float pierwiastek;
    int i,j;
    for(i = 0; i < C.r; i++)
        for(j = 0; j < C.c; j++)
            suma += C.tab[i][j] * C.tab[i][j];
    pierwiastek = sqrt(suma);
    return pierwiastek;
}

void wypisz(struct macierz tab)
{
    printf("[");
    for(int i = 0; i < tab.r; i++)
    {
        for(int j = 0; j < tab.c; j++)
        {
            printf("%5.1f " , tab.tab[i][j]);
        }
        if(i <( tab.r-1))
            printf("\n ");
    }
    printf("]\n");
    
}

void zapisz(FILE *h, struct macierz tab)
{
    fprintf(h, "%d\n%d\n", tab.r, tab.c);
    for(int i = 0; i < tab.r; i++)
    {
        for(int j = 0; j < tab.c; j++)
        {
            fprintf(h, "%f\n" , tab.tab[i][j]);
        }
    }
}

int main(int argc, char *argv[])
{
    if(strcmp(argv[1], "norm") == 0)
    {
        if(argv[3])
        {
            struct macierz mac_A;
            FILE *f, *h;
            f = fopen(argv[2], "r");
            h = fopen(argv[3], "w");
            wczytaj(f, &mac_A);
            fprintf(h, "%f", norm(mac_A));
            fclose(f);
            fclose(h);
        }
        else
        {
            struct macierz mac_A;
            FILE *f;
            f = fopen(argv[2], "r");
            wczytaj(f, &mac_A);
            printf("%f\n", norm(mac_A));
            fclose(f);
        }
    }
    if(strcmp(argv[1], "multiply") == 0)
    {
        if(argv[4])
        {
            struct macierz mac_A;
            FILE *f, *h;
            f = fopen(argv[2], "r");
            h = fopen(argv[4], "w");
            wczytaj(f, &mac_A);
            zapisz(h, multiply(mac_A, atof(argv[3])));
            fclose(h);
            fclose(f);
        }
        else
        {
            struct macierz mac_A;
            FILE *f;
            f = fopen(argv[2], "r");
            wczytaj(f, &mac_A);
            wypisz(multiply(mac_A, atof(argv[3])));
            fclose(f);
        }
    }
    if(strcmp(argv[1], "sum") == 0)
    {
        if(argv[4])
        {
            struct macierz mac_A;
            struct macierz mac_x;
            FILE *f, *g, *h;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            h = fopen(argv[4], "w");
            wczytaj(f, &mac_A);
            wczytaj(g, &mac_x);
            if(mac_A.r == mac_x.r && mac_A.c == mac_x.c)
                zapisz(h, sum(mac_A, mac_x));
            else
                printf("Nie mozna dodac tych dwoch macierzy. Ich wymiary nie sa takie same.\n"); 
            fclose(h);
            fclose(g);
            fclose(f);
        }
        else
        {
            struct macierz mac_A;
            struct macierz mac_x;
            FILE *f, *g;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            wczytaj(f, &mac_A);
            wczytaj(g, &mac_x);
            if(mac_A.r == mac_x.r && mac_A.c == mac_x.c)
                wypisz(sum(mac_A, mac_x));
            else
                printf("Nie mozna dodac tych dwoch macierzy. Ich wymiary nie sa takie same.\n"); 
            fclose(g);
            fclose(f);
        }
    }
    if(strcmp(argv[1], "subtract") == 0)
    {
        if(argv[4])
        {
            struct macierz mac_A;
            struct macierz mac_x;
            FILE *f, *g, *h;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            h = fopen(argv[4], "w");
            wczytaj(f, &mac_A);
            wczytaj(g, &mac_x);
            if(mac_A.r == mac_x.r && mac_A.c == mac_x.c)
                zapisz(h, subtract(mac_A, mac_x));
            else
                printf("Nie mozna odjac tych dwoch macierzy. Ich wymiary nie sa takie same.\n"); 
            fclose(h);
            fclose(g);
            fclose(f);
        }
        else
        {
            struct macierz mac_A;
            struct macierz mac_x;
            FILE *f, *g;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            wczytaj(f, &mac_A);
            wczytaj(g, &mac_x);
            if(mac_A.r == mac_x.r && mac_A.c == mac_x.c)
            wypisz(sum(mac_A, mac_x));
            else
                printf("Nie mozna odjac tych dwoch macierzy. Ich wymiary nie sa takie same.\n");
            fclose(g);
            fclose(f);
        }
    }
    if(strcmp(argv[1], "prod") == 0)
    {
        if(argv[4])
        {
            struct macierz mac_A;
            struct macierz mac_x;
            FILE *f, *g, *h;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            h = fopen(argv[4], "w");
            wczytaj(f, &mac_A);
            wczytaj(g, &mac_x);
            zapisz(h, prod(mac_A, mac_x));
            fclose(h);
            fclose(g);
            fclose(f);
        }
        else
        {
            struct macierz mac_A;
            struct macierz mac_x;
            FILE *f, *g;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            wczytaj(f, &mac_A);
            wczytaj(g, &mac_x);
            wypisz(prod(mac_A, mac_x));
            fclose(g);
            fclose(f);
        }
    }
}
