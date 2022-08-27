#include "header.h"

int main (int argc, char *argv[]){
  int x,y;
  typeReq **a;
  typeReq **b;
  dimArrBi(&x,&y);
  
  a=crearArrBi(x,y);
  b=crearArrBi(x,y);

  darDataBi(a,x,x);
  darDataBi(b,x,x);

  typeReq *arrFinal;
  arrFinal=crearArr(x);

  fillArr(a,b,arrFinal,x,x);
  mostrarArrBi(arrFinal,x,x);

  freeBi(a,x);
  freeBi(b,x);
  freeBi(arrFinal,x);

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
typeReq dimArrBi(int *x,int *y){
  printf("Ingresa las filas: ");  scanf("%d",x);
  printf("\nIngresa las columnas: ");  scanf("%d",y);
}

//pregunta por arreglo dimensional
void dimArr(int *x){
  printf("Ingresa las filas: ");  scanf("%d",x);
}

//cambiar el tipo con la linea, gracias c por la falta de polimorfismo
typeReq *crearArr(int x){
  void *p;
  p=(void*)malloc(sizeof(typeReq)*x);

  return p;
}

//cambiar igualmente el tipo a lo necesario en todo momento que se necesite
typeReq **crearArrBi(int x, int y) {
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
    printf("\tDato no.%d:  ",i+1); scanf("%d",*(ap+i)); //cambiar linea dependiendo el tipo
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

void mostrarArr(typeReq* ap){
  int x = valOf(ap),i;
  for (i = 0; i < x; i++)
    //printf("%% ",*(ap+i));
  printf("\n");
}

void mostrarArrBi(typeReq** ap,int x,int y){
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++)
      //printf("%% ",*(*(ap+i)+j);
    printf("\n");
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

//empezamos con las funciones que vamos a ocupar actualmente
//realiza el promedio de una fila
int promArr(typeReq **ap,int i,int x){
  int sum=0,j;
  for (j = 0; j < x; j++) {
    sum+=*(*(ap+j)+i);
  }
  return sum/x;
}
typeReq min(typeReq **ap,int i,int x){
}

//realiza la operacion y devuelve el resultado
int arithmeticProcess(typeReq **array1,typeReq **array2,int i,int x){
  int result,tmp, val=99999;
  int dir1,j;
  for (j = 0; j < x; j++)
      if(*(*(ap+j)+x) < val){
        val = *(*(ap+j)+x);
        dir1=j;
      }
  tmp = promArr(array1,i,x)*val;

  result = pow(tmp,(j+i));
  return result;
}

//rellena el arreglo
void fillArr(typeReq **array1,typeReq,typeReq **array2,typeReq *arrProduct,int x){
  int i;
  for (i = 0; i < ; i++) {
    *arrProduct=arithmeticProcess(array1,array2,i,x);
  }
}
