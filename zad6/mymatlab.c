#include "mat.h"
#include "inout.h"

int main(int argc, char *argv[])
{
    if(strcmp(argv[1], "norm") == 0)
    {
        if(argv[3])
        {
            struct macierz *mac_A;
            FILE *f, *h;
            f = fopen(argv[2], "r");
            h = fopen(argv[3], "w");
            mac_A = wczytaj(f);
            fprintf(h, "%f", norm(mac_A));
            fclose(f);
            fclose(h);
            zwolnij(mac_A);
        }
        else
        {
            struct macierz *mac_A;
            FILE *f;
            f = fopen(argv[2], "r");
            mac_A = wczytaj(f);
            printf("%f\n", norm(mac_A));
            fclose(f);
            zwolnij(mac_A);
        }
    }
    if(strcmp(argv[1], "multiply") == 0)
    {
        if(argv[4])
        {
            struct macierz *mac_A;
            FILE *f, *h;
            f = fopen(argv[2], "r");
            h = fopen(argv[4], "w");
            mac_A = wczytaj(f);
            zapisz(h, multiply(mac_A, atof(argv[3])));
            fclose(h);
            fclose(f);
            zwolnij(mac_A);
        }
        else
        {
            struct macierz *mac_A;
            FILE *f;
            f = fopen(argv[2], "r");
            mac_A = wczytaj(f);
            wypisz(multiply(mac_A, atof(argv[3])));
            fclose(f);
            zwolnij(mac_A);
        }
    }
    if(strcmp(argv[1], "sum") == 0)
    {
        if(argv[4])
        {
            struct macierz *mac_A;
            struct macierz *mac_x;
            FILE *f, *g, *h;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            h = fopen(argv[4], "w");
            mac_A = wczytaj(f);
            mac_x = wczytaj(g);
            if(mac_A->r == mac_x->r && mac_A->c == mac_x->c)
                zapisz(h, sum(mac_A, mac_x));
            else
                printf("Nie mozna dodac tych dwoch macierzy. Ich wymiary nie sa takie same.\n"); 
            fclose(h);
            fclose(g);
            fclose(f);
            zwolnij(mac_A);
            zwolnij(mac_x);
        }
        else
        {
            struct macierz *mac_A;
            struct macierz *mac_x;
            FILE *f, *g;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            mac_A = wczytaj(f);
            mac_x = wczytaj(g);
            if(mac_A->r == mac_x->r && mac_A->c == mac_x->c)
                wypisz(sum(mac_A, mac_x));
            else
                printf("Nie mozna dodac tych dwoch macierzy. Ich wymiary nie sa takie same.\n"); 
            fclose(g);
            fclose(f);
            zwolnij(mac_A);
            zwolnij(mac_x);
        }
    }
    if(strcmp(argv[1], "subtract") == 0)
    {
        if(argv[4])
        {
            struct macierz *mac_A;
            struct macierz *mac_x;
            FILE *f, *g, *h;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            h = fopen(argv[4], "w");
            mac_A = wczytaj(f);
            mac_x = wczytaj(g);
            if(mac_A->r == mac_x->r && mac_A->c == mac_x->c)
                zapisz(h, subtract(mac_A, mac_x));
            else
                printf("Nie mozna odjac tych dwoch macierzy. Ich wymiary nie sa takie same.\n"); 
            fclose(h);
            fclose(g);
            fclose(f);
            zwolnij(mac_A);
            zwolnij(mac_x);
        }
        else
        {
            struct macierz *mac_A;
            struct macierz *mac_x;
            FILE *f, *g;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            mac_A = wczytaj(f);
            mac_x = wczytaj(g);
            if(mac_A->r == mac_x->r && mac_A->c == mac_x->c)
            wypisz(sum(mac_A, mac_x));
            else
                printf("Nie mozna odjac tych dwoch macierzy. Ich wymiary nie sa takie same.\n");
            fclose(g);
            fclose(f);
            zwolnij(mac_A);
            zwolnij(mac_x);
        }
    }
    if(strcmp(argv[1], "prod") == 0)
    {
        if(argv[4])
        {
            struct macierz *mac_A;
            struct macierz *mac_x;
            FILE *f, *g, *h;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            h = fopen(argv[4], "w");
            mac_A = wczytaj(f);
            mac_x = wczytaj(g);
            zapisz(h, prod(mac_A, mac_x));
            fclose(h);
            fclose(g);
            fclose(f);
            zwolnij(mac_A);
            zwolnij(mac_x);

        }
        else
        {
            struct macierz *mac_A;
            struct macierz *mac_x;
            FILE *f, *g;
            f = fopen(argv[2], "r");
            g = fopen(argv[3], "r");
            mac_A = wczytaj(f);
            mac_A = wczytaj(g);
            wypisz(prod(mac_A, mac_x));
            fclose(g);
            fclose(f);
            zwolnij(mac_A);
            zwolnij(mac_x);
        }
    }

}
