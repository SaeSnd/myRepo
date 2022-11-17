#include "Complejo.h"
#include "Polar.h"
#include <stdlib.h>
#include <stdio.h>

void darComplejos(COMPLEJO);
void mostrarComplejo(COMPLEJO);
void showPolarComplex(PCOMPLEX);

int main(int argc, char const *argv[])
{
    COMPLEJO C1, C2, C3;
    PCOMPLEX p = createPolarComplex(); 
    setAngle(p, 270);
    setR(p, 6);
    showPolarComplex(p);
    C2 = toRectangular(p);
    mostrarComplejo(C2);
    return 0;
}

void darComplejos(COMPLEJO c1) {
    float r, i;
    printf("Dar la parte real del complejo: \n");
    scanf("%f", &r);
    printf("Dar la parte imaginaria del complejo: \n");
    scanf("%f", &i);
    asignaReal(c1, r);
    asignaImaginario(c1, i);
}

void mostrarComplejo(COMPLEJO c1) {
    printf("Complejo 1 (%f, i%f)\n", c1->real, c1->imaginario);
}

void showPolarComplex(PCOMPLEX p) {
    printf("Polar representation (z): %.2f ( cos %.2f + i sin %.2f)\n",p->r, p->angle, p->angle);
    
}