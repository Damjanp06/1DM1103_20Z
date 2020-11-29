#include "mat.h"

struct macierz *sum(struct macierz *A, struct macierz *x)
{
    struct macierz *suma;
    suma = (struct macierz*) malloc(sizeof(struct macierz));
    suma->r = x->r;
    suma->c = x->c;
    suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for (int k=0;k<suma->r;k++) 
        {
        suma->tab[k] = (float*) malloc(sizeof(float) * suma->c);
        for (int l=0;l< suma->c; l++)
            suma->tab[k][l] = l+1+k;
        }

    for(int i = 0; i < x->r; i++)
        for(int j = 0; j < x->c; j++)
            suma->tab[i][j] = A->tab[i][j] + x->tab[i][j];
    return suma;
}

struct macierz *subtract(struct macierz *A, struct macierz *x)
{
    struct macierz *roznica;
    roznica = (struct macierz*) malloc(sizeof(struct macierz));
    roznica->r = x->r;
    roznica->c = x->c;
    roznica->tab = (float**) malloc(sizeof(float*) * roznica->r);
    for (int k=0;k<roznica->r;k++) 
        {
        roznica->tab[k] = (float*) malloc(sizeof(float) * roznica->c);
        for (int l=0;l< roznica->c; l++)
            roznica->tab[k][l] = l+1+k;
        }

    for(int i = 0; i < x->r; i++)
        for(int j = 0; j < x->c; j++)
            roznica->tab[i][j] = A->tab[i][j] - x->tab[i][j];
    return roznica;
}

struct macierz *prod(struct macierz *A, struct macierz *x)
{
    struct macierz *iloczyn;
    iloczyn = (struct macierz*) malloc(sizeof(struct macierz));
    iloczyn->r = A->r;
    iloczyn->c = x->c;
    iloczyn->tab = (float**) malloc(sizeof(float*) * iloczyn->r);
    for (int k=0;k<iloczyn->r;k++) 
        {
        iloczyn->tab[k] = (float*) malloc(sizeof(float) * iloczyn->c);
        for (int l=0;l< iloczyn->c; l++)
            iloczyn->tab[k][l] = l+1+k;
        }

    if(A->c == x->r)
    {
        for(int i = 0; i < x->c; i++)
            for(int j = 0; j < A->r; j++)
                for(int k = 0; k < A->c; k++)
                iloczyn->tab[j][i] += A->tab[j][k] * x->tab[k][i];
    }
    else
    {
        printf("Działanie nie może być wykonane."
        "Liczba kolumn w pierwszej macierzy nie "
        "jest równa liczbie wierszy w drugiej macierzy.\n");
    }
    return iloczyn;
}

struct macierz *multiply(struct macierz *A, float skalar)
{
    struct macierz *iloczyn_skalar;
    iloczyn_skalar = (struct macierz*) malloc(sizeof(struct macierz));
    iloczyn_skalar->r = A->r;
    iloczyn_skalar->c = A->c;
    iloczyn_skalar->tab = (float**) malloc(sizeof(float*) * iloczyn_skalar->r);
    for (int k=0;k<iloczyn_skalar->r;k++) 
        {
        iloczyn_skalar->tab[k] = (float*) malloc(sizeof(float) * iloczyn_skalar->c);
        for (int l=0;l< iloczyn_skalar->c; l++)
            iloczyn_skalar->tab[k][l] = l+1+k;
        }

    for(int i = 0; i < A->r; i++)
        for(int j = 0; j < A->c; j++)
            iloczyn_skalar->tab[i][j] = A->tab[i][j] * skalar;
    return iloczyn_skalar;
}

float norm(struct macierz *C) 
{
    float suma = 0;
    float pierwiastek;
    int i,j;
    for(i = 0; i < C->r; i++)
        for(j = 0; j < C->c; j++)
            suma += C->tab[i][j] * C->tab[i][j];
    pierwiastek = sqrt(suma);
    return pierwiastek;
}