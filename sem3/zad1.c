#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float a; 
    a = atof(argv[1]);
    printf("Wartość %.0f do kwadratu to %.0f.\n", a, a*a);
}