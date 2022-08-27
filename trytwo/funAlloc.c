#include <stdio.h>
#include <stdlib.h>

typedef int typeReq; //cambiar tipo segun necesario

int valOf(void*);
void msg(int);

void dimArrBi(int *, int *);
void dimArr(int *);

typeReq *crearArr(int);
typeReq **crearArrBi(int, int);
void darData(typeReq*);
void darDataBi(typeReq**,int,int);

void mostrarArr(typeReq*);
void mostrarArrBi(typeReq**,int,int);

void freeBi(typeReq **,int);
void freeArr(typeReq*);


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
typeReq *crearArr(int x){
  typeReq *p;
  p=(typeReq*)malloc(sizeof(typeReq)*x);

  return p;
}

//cambiar igualmente el tipo a lo necesario en todo momento que se necesite
typeReq **crearArrBi(int x, int y) {
  typeReq **p;   int i;
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
    printf("\tDato no.%d:  ",i+1); scanf("%d",ap+i); //cambiar linea dependiendo el tipo
  }
}

//arreglo bidimensional
void darDataBi(typeReq **ap,int x, int y){
  printf("\nIngresa los datos de la matriz: \n");
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      printf("Dato [%d][%d]: ",i+1,j+1); scanf("%d",*(ap+j)+i); //cambiar linea por tipo
    }
  }
}

void mostrarArr(typeReq* ap){
  int x = valOf(ap),i;
  for (i = 0; i < x; i++)
    printf("%d ",*(ap+i));
  printf("\n");
}

void mostrarArrBi(typeReq** ap,int x,int y){
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++)
      printf("%d ",*(*(ap+i)+j));
    printf("\n");
  }
}

//x es x dimension
void freeBi(typeReq **ap,int x){
  int i;

  for (i = 0; i < x; i++)
    freeArr(*(ap+i));
  free(ap);
}

//libera apuntador normal
void freeArr(typeReq *ap){
  free(ap);
}
