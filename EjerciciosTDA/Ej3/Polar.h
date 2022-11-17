#ifndef _polar_

typedef struct{
    double r;
    double angle;
} PolarComplex;

typedef PolarComplex * PCOMPLEX;

void setR(PCOMPLEX, double);
double getR(PCOMPLEX);

void setAngle(PCOMPLEX, double);
double getAngle(PCOMPLEX);

PCOMPLEX toPolar(COMPLEJO);
COMPLEJO toRectangular(PCOMPLEX);
PCOMPLEX createPolarComplex();
int cartesianCuadrantSubstract(COMPLEJO);

#endif // !_polar_