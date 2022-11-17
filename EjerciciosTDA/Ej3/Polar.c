#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Complejo.h"
#include "Polar.h"
#define PI 3.14159265358979323846

PCOMPLEX createPolarComplex() {
    PCOMPLEX c;
    c = (PCOMPLEX)malloc(sizeof(PCOMPLEX) * 1);
    if(c == NULL){
        manejaMsg(0);
        exit(0);
    };
    return c;
}

void setR(PCOMPLEX c, double r) {
    c -> r = r;
}

double getR(PCOMPLEX c) {
    return c -> r;
}

void setAngle(PCOMPLEX c, double a) {
    c -> angle = a;
}

double getAngle(PCOMPLEX c) {
    return c -> angle;
}

PCOMPLEX toPolar(COMPLEJO c) {
    PCOMPLEX p = createPolarComplex();
    int substraction = cartesianCuadrantSubstract(c);
    double r= sqrt(obtenReal(c)*obtenReal(c)+obtenImaginario(c)*obtenImaginario(c));
    double angle= atan(obtenImaginario(c)/obtenReal(c));

    angle= angle*180 / PI;
    r= round(r*1000) / 1000;

    if(angle < 0.0) angle = -1*angle;

    angle= substraction - (angle);

    setAngle(p, angle);
    setR(p, r);

    return p;
}

COMPLEJO toRectangular(PCOMPLEX c) {
    COMPLEJO rectangularComplex = creaComplejo();
    double radians = getAngle(c) * (PI / 180);
    printf("%.2f\n", cos(radians) * getR(c) );
    asignaReal(rectangularComplex, cos(radians) * getR(c));
    asignaImaginario(rectangularComplex, getR(c) * sin(radians));
    return rectangularComplex;
}

int cartesianCuadrantSubstract(COMPLEJO complex){ 
    int x = obtenReal(complex);
    int y = obtenImaginario(complex);

    if(x > 0 && y > 0){
        return 0;
    } else if(x < 0 && y > 0) {
        return 180;
    } else if(x < 0 && y < 0) {
        return 270;
    } else if(x > 0 && y < 0) {
        return 360;
    }
}