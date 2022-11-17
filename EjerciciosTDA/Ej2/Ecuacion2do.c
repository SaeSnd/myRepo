/*Defina un tipo abstracto de datos de una ec 2do grado de la forma (ax^2 + bx + c = 0) con las operaciones
CrearEc*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mandarMsg(int n){
  char *msg[] = {"No hay memoria disponible. "};
  fprintf(stderr, "%s\n",msg[n]);
}

ECUACION crearEcuac(){
  ECUACION A = (ECUACION)malloc(sizeof(ecuacion));
  if(A == NULL){
    mandarMsg(0);
    exit(-1);
  }
  return A;
}

void ponA(ECUACION E, int n){
  E -> a = n;
}

void ponB(ECUACION E, int n){
  E -> b = n;
}

void ponC(ECUACION E, int n){
  E -> c = n;
}

int obtenA(ECUACION E){
  return (E -> a);
}

int obtenB(ECUACION E){
  return (E -> b);
}

int obtenC(ECUACION E){
  return (E -> c);
}

double *obtenerSoluciones(ECUACION eq){
  double soluciones[2];
  double determinante = (double) obtenB(eq) * obtenB(eq) - 4 * obtenA(eq) * obtenC(eq);
  if(determinante == 0){
    soluciones[1] = -obtenB(eq)/2obtenA(eq);
    soluciones[0] = soluciones[1];
  } else if(determinante > 0){
    soluciones[0] = (double)(-obtenB(eq) + sqrt(determinante))/(double)2*obtenA(eq);
    soluciones[1] = (double)(-obtenB(eq) - sqrt(determinante))/(double)2*obtenA(eq);
  } else{
    soluciones[0] = (-obtenB(eq)/2*obtenA(eq));
    soluciones[1] = sqrt(-determinante) / 2 * obtenA(eq);
    
  }

  return soluciones;
}
