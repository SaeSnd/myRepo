#include "header.h"

int main (int argc, char *argv[]){
  int x,y;

  return 0;
}

//muestra un mensaje dependiendo el numero
void msg(int opcion){
  switch (opcion) {
    case 0: break;
    case 1: fprintf(stderr, "Error.\n");
      break;
  }
}

//regresa el tamaño de un arreglo
int valOf(void *array){
  return sizeof(array)/sizeof(array[0]);
}

//pregunta por arreglo bidimensional
void dimArrBi(int *x,int *y){
  printf("Ingresa las filas: ");  scanf("%d",x);
  printf("\nIngresa las columnas: ");  scanf("%d",y);
}

//pregunta por arreglo dimensional
void dimArr(int *x){
  printf("Ingresa las filas: ");  scanf("%d",x);
}

//cambiar el tipo con la linea, gracias c por la falta de polimorfismo
void *crearArr(int x){
  void *p;
  p=(void*)malloc(sizeof(typeReq)*x);

  return p;
}

//cambiar igualmente el tipo a lo necesario en todo momento que se necesite
void **crearArrBi(int x, int y) {
  void **p;   int i;
  p=(typeReq**)malloc(sizeof(typeReq*)*x);
  for (i = 0; i < x; i++)
    *(p+i)=(typeReq *)malloc(sizeof(typeReq)*y);

  return p;
}

//solo arreglo unidimensional
void darData(typeReq *ap){
  int x = valOf(ap),i;
  printf("\nIngresa los datos de la matriz: \n");
  for (i = 0; i < x; i++) {
    printf("\tDato no.%d:  ",i+1); //scanf("%d",*(ap+i)); //cambiar linea dependiendo el tipo
  }
}

//arreglo bidimensional
void darDataBi(typeReq **ap,int x, int y){
  printf("\nIngresa los datos de la matriz: \n");
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      printf("Dato [%d][%d]: ",i+1,j+1); //scanf("%d",*(ap+j)+i); //cambiar linea por tipo
    }
  }
}

//x es x dimension
void freeBi(void **ap,int x){
  int i;

  for (i = 0; i < x; i++)
    freeArr(*(ap+i));
  free(ap);
}

//libera apuntador normal
void freeArr(void *ap){
  free(ap);
}
