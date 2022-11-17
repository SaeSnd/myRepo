#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Fraccion.h"


void manejaMsg(int);
void darFracciones(FRACCION, FRACCION);
void mostrarPropia(FRACCION);
void mostrarFraccion(FRACCION, FRACCION, FRACCION, FRACCION, FRACCION, int);
int preguntarPotencia();
void liberarMem(FRACCION, FRACCION, FRACCION, FRACCION,FRACCION);

void main( ){
      FRACCION F1, F2, F3,F4 ,F5;
      int n;
      F1=crearFraccion();
      F2=crearFraccion ();
      F3=crearFraccion ();
       darFracciones(F1, F2);
       n = preguntarPotencia();
      F3 = producto(F1, F2);
      F5 = potencia(F3,n);
      F4 = division(F1,F5);
      mostrarPropia(F3);
     mostrarFraccion(F1, F2, F3,F4,F5,n);
     liberarMem(F1, F2, F3,F4,F5);
} 


void darFracciones(FRACCION F1, FRACCION F2){
     int n, d;
     printf("Dar el numerador de la fraccion 1\n");
     scanf("%d", &n);
     asignaNum(F1, n);
     printf("Dar el denominador de la fraccion 1\n");
     scanf("%d", &d); 
     asignaDenom(F1, d);
    printf("Dar el numerador de la fraccion 2\n");
     scanf("%d", &n);
     asignaNum(F2, n);
     printf("Dar el denominador de la fraccion 2\n");
     scanf("%d", &d); 
     asignaDenom(F2, d);
}

void mostrarFraccion(FRACCION F1, FRACCION F2, FRACCION F3,FRACCION F4, FRACCION F5, int n){
    printf("Fraccion 1  %d/%d \n", obtenNum(F1), obtenDenom(F1) );
    printf("Fraccion 2  %d/%d \n", obtenNum(F2), obtenDenom(F2) ); 
    printf("El producto es %d/%d \n", obtenNum(F3), obtenDenom(F3));
    printf("La fraccion F3 a la [%d] potencia es: %d/%d\n",n, obtenNum(F5), obtenDenom(F5));
    printf("La division entre F1 y F3^%d es: %d/%d\n",n,obtenNum(F4),obtenDenom(F4));
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .", "\nSe ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
void liberarMem(FRACCION F1, FRACCION F2, FRACCION F3, FRACCION F4, FRACCION F5){
    free(F1);
    free(F2); 
    free(F3);
    free(F4);
    free(F5);
    manejaMsg(1);
}

void mostrarPropia(FRACCION F){
     printf("La fraccion [%d/%d] ",obtenNum(F),obtenDenom(F));
     if(preguntarPropia(F)){
          printf("es propia\n");
     }else printf("no es propia\n");
}

int preguntarPotencia(){
     int n;
     printf("\nIngresa el numero a potenciar la fraccion: ");
     scanf("%d",&n);
     return n;
}
