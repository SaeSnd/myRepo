#include <stdio.h>
#include <stdlib.h>

void dimMatriz(int*,int*);
int **crearMatriz(int,int);
void darDatos(int**,int,int);

int main (int argc, char *argv[])
{
  int n,m;
  dimMatriz(&n,&m);
  int **a = crearMatriz(n,m);
  darDatos(a,n,m);
  return 0;
}

void dimMatriz(int *x, int *y){
  printf("Registra las filas: "); scanf("%d",x);
  printf("\nRegistra las columnas: "); scanf("%d",y);
}

int **crearMatriz(int x, int y){
  int **tmp;
  tmp =(int**) malloc(sizeof(int*)*y);
  for (int i = 0; i < y; i++) {
    *(tmp+i) = (int*) malloc(sizeof(int)*x);
  }
  return tmp;
}
void darDatos(int **mtz,int n,int m){
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("Registra el valor [%d][%d]: "); scanf("%d",mtz[i][j]);
    }
  }
}
