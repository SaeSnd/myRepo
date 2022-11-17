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

void asignaEnt(FRACCION F, int n){
  F -> entero = n;
}

int obtenNum(FRACCION F){
       return ( F -> numerador);
}

int obtenDenom(FRACCION F){
      return ( F -> denominador);
}

int obtenEnt(FRACCION F){
  return (F -> entero);
}

FRACCION producto(FRACCION F1, FRACCION F2){
      FRACCION F3 =  crearFraccion();
      asignaNum( F3, obtenNum(F1) * obtenNum(F2) );
      asignaDenom( F3, obtenDenom(F1) * obtenDenom(F2) );
      asignaEnt(F3, obtenEnt(F1) * obtenEnt(F2));
      return F3;
}


FRACCION division(FRACCION F1, FRACCION F2){
      FRACCION F3 =  crearFraccion();
      asignaNum( F3, obtenNum(F1) * obtenDenom(F2) );
      asignaDenom( F3, obtenNum(F1) * obtenDenom(F2) );
      asignaEnt(F3, obtenEnt(F1) / obtenEnt(F2));
      return F3;
}

int preguntarPropia(FRACCION F){
      return ((obtenNum(F) < obtenDenom(F))? 1: 0);
}

FRACCION potencia(FRACCION F, int n){
      FRACCION F2 =  crearFraccion();
      asignaNum( F2, pow(obtenNum(F),n));
      asignaDenom( F2, pow(obtenDenom(F),n) );
      asignaEnt(F2, pow(obtenEnt(F),n) );
      return F2;
}

FRACCION impropia(FRACCION F){
  FRACCION F1 = crearFraccion();
  asignaNum(F1,obtenNum(F)*obtenEnt(F));
  asignaEnt(F1,1);
  asignaDenom(F1,obtenDenom(F));
  return F1;
}

FRACCION propia(FRACCION F){
  int residuo = obtenNum(F) % obtenDenom(F);
  
  if( !(preguntarPropia(F)) && residuo != 0 ){
    FRACCION F1 = crearFraccion();

    asignaNum(F1, residuo);
    asignaEnt(F1, (obtenNum(F)-residuo) / obtenDenom(F) );
    return F1;

  } else if(residuo == 0){
    FRACCION F1 = crearFraccion();
    asignaNum(F1, obtenNum(F) / obtenDenom(F));
    asignaDenom(F1,1);
    return F1;

  } else return F;
}

double toDecimal(FRACCION F){
  return ((double)obtenNum(F) / (double)obtenDenom(F));
}

FRACCION toFraccion(double n){
  FRACCION F = crearFraccion();

  int c = 10000;
  double b = (n - floor(n)) * c;
  int d = (int) floor(n) * c + (int)(b + .5f);

  while (1) {
    if( d % 10 == 0){
      d /= 10;
      c /= 10;
    } else break;
  }

  asignaNum(F,d);
  asignaDenom(F,c);

  return F;
}
