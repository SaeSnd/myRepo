#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Complejo.h"
#include "Polar.h"

COMPLEJO creaComplejo(void) {
    COMPLEJO c;
    c = (COMPLEJO)malloc(sizeof(COMPLEJO) * 1);
    if(c == NULL){
        manejaMsg(0);
        exit(0);
    };
    return c;
}

void asignaReal(COMPLEJO c, float r) {
    c -> real = r;
}

void asignaImaginario(COMPLEJO c, float r) {
    c ->imaginario = r;
}

float obtenReal(COMPLEJO c) {
    return c -> real;
}

float obtenImaginario(COMPLEJO c) {
    return c -> imaginario;
}

COMPLEJO suma(COMPLEJO a, COMPLEJO b) {
    COMPLEJO result = creaComplejo();
    asignaReal(result, obtenReal(a) + obtenReal(b));
    asignaImaginario(result, obtenImaginario(a) + obtenImaginario(b));
    return result;
}

void manejaMsg(int index) {
    char *messages[] = {
        "Sin espacio en memoria"
    };
    printf("\n%s\n", messages[index]);
}
