#include<stdlib.h>
#include<stdio.h>
#include "Fraccion.h"
#include <math.h>

void manejaMsg(int);
FRACCION crearFraccion(void){
 FRACCION F;
   F = (FRACCION)malloc(sizeof(Fraccion));
   if( F == NULL){
         manejaMsg(0);
         exit(0);
    }
    return F;
}
void asignaNum(FRACCION F,  int n){
    F -> numerador = n;
}

void asignaDenom(FRACCION F, int d){
      F -> denominador = d;
}

int obtenNum(FRACCION F){
       return ( F -> numerador);
}

int obtenDenom(FRACCION F){
      return ( F -> denominador);
}

FRACCION producto(FRACCION F1, FRACCION F2){
      FRACCION F3 =  crearFraccion();
      asignaNum( F3, obtenNum(F1) * obtenNum(F2) );
      asignaDenom( F3, obtenDenom(F1) * obtenDenom(F2) );
      return F3;
}


FRACCION division(FRACCION F1, FRACCION F2){
      FRACCION F3 =  crearFraccion();
      asignaNum( F3, obtenNum(F1) * obtenDenom(F2) );
      asignaDenom( F3, obtenNum(F1) * obtenDenom(F2) );
      return F3;
}

int preguntarPropia(FRACCION F){
      return ((obtenNum(F) < obtenDenom(F))? 1: 0);
}

FRACCION potencia(FRACCION F, int n){
      FRACCION F2 =  crearFraccion();
      asignaNum( F2, pow(obtenNum(F),n));
      asignaDenom( F2, pow(obtenDenom(F),n) );
      return F2;
}