#ifndef _mat_h
#define _mat_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "inout.h"

struct macierz *sum(struct macierz *A, struct macierz *x);
struct macierz *subtract(struct macierz *A, struct macierz *x);
struct macierz *prod(struct macierz *A, struct macierz *x);
struct macierz *multiply(struct macierz *A, float skalar);
float norm(struct macierz *C);

#endif