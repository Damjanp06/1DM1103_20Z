#include "studenci.h"
#include "dziekanat.h"

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    if(strcmp(argv[2], "studenci")==0)
        najlepszy_student(dane, ile);
    if(strcmp(argv[2], "przedmioty")==0)
    {
        najlepszy_przedmiot(dane, ile);
        najgorszy_przedmiot(dane, ile);
    }
    return 0;
}