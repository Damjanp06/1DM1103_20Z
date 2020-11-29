#include "inout.h"

struct macierz *wczytaj(FILE *f)
{
    struct macierz *m;
    m = (struct macierz*) malloc(sizeof(struct macierz));
    fscanf(f, "%d", &m->r);
    fscanf(f, "%d", &m->c);
    m->tab = (float**) malloc(sizeof(float*) * m->r);
    for (int k=0;k<m->r;k++) 
        {
        m->tab[k] = (float*) malloc(sizeof(float) * m->c);
        for (int l=0;l< m->c; l++)
            m->tab[k][l] = l+1+k;
        }

    for(int i = 0; i < m->r; i++)
        for(int j = 0; j < m->c; j++)
            fscanf(f, "%f", &m->tab[i][j]);
    return m;
}

void wypisz(struct macierz *tab)
{
    printf("[");
    for(int i = 0; i < tab->r; i++)
    {
        for(int j = 0; j < tab->c; j++)
        {
            printf("%5.1f " , tab->tab[i][j]);
        }
        if(i <( tab->r-1))
            printf("\n ");
    }
    printf("]\n");
    
}

void zapisz(FILE *h, struct macierz *tab)
{
    fprintf(h, "%d\n%d\n", tab->r, tab->c);
    for(int i = 0; i < tab->r; i++)
    {
        for(int j = 0; j < tab->c; j++)
        {
            fprintf(h, "%f\n" , tab->tab[i][j]);
        }
    }
}

void zwolnij(struct macierz *m)
{
    for(int i = 0; i < m->r; i++)
    {
        free(m->tab[i]);
    }
    free(m->tab);
    free(m);
}