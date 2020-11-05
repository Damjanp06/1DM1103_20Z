#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char n[100]; //zarezerwuj pamiec na sto znakow
    int i;
    strcpy(n, "Ala");
    for(i=0;i<3;i++){
    printf("\n[%d] %c, %d\n", i, n[i], n[1]);
    }
    return 0; 
}