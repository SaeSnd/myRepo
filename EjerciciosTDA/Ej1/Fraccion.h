#ifndef  _fraccion_
#define _fraccion_

typedef struct{
   int numerador;
   int denominador;
   int entero;
}Fraccion;
typedef Fraccion * FRACCION;




// operaciones
FRACCION crearFraccion(void);
void asignaNum(FRACCION F,  int n);
void asignaDenom(FRACCION F, int d);
void asignaEnt(FRACCION F, int n);
int obtenNum(FRACCION F);
int obtenDenom(FRACCION F);
int obtenEnt(FRACCION F);
FRACCION producto(FRACCION F1, FRACCION F2);
FRACCION division(FRACCION F1, FRACCION F2);
int preguntarPropia(FRACCION F);
FRACCION potencia(FRACCION F, int n);

FRACCION impropia(FRACCION F);
FRACCION propia(FRACCION F);

double toDecimal(FRACCION F);
FRACCION toFraccion(double n);
#endif

