#include <stdio.h>
#include <stdlib.h>

typedef struct datos{
  char nombre[15];
  char ap_pater[15];
  int edad;
  char carrera[20];
} Datos;

typedef struct deportista{
  Datos pers;
  char deportes[30];
  int medallas;
} Deportista;

void manejarMsg(int);

void preguntar(int*);
Deportista *crearDeportistas(int);
void darDatos(Deportista*,int);
void mostrar(Deportista*,int);
void calcular(Deportista*,int,int*);

void liberar(Deportista*);

int main (int argc, char *argv[])
{
  int n;
  Deportista *deportistas;
  preguntar(&n);
  deportistas = crearDeportistas(n);
  darDatos(deportistas,n);
  mostrar(deportistas,n);
  liberar(deportistas);
  return 0;
}

void manejarMsg(int opcion){
  char *msg[] = {"No hay memoria disponible... ","Se ha liberado la memoria correctamente. "};
  fprintf(stderr, "%s\n",msg[opcion]);
}

void preguntar(int *n){
  printf("Cuantos deportistas?: "); scanf("%d",n);
}

Deportista *crearDeportistas(int n){
  Deportista *tmp;
  tmp = (Deportista*)malloc(sizeof(Deportista)*n);
  if(tmp == NULL) manejarMsg(0);
  return tmp;
}

void darDatos(Deportista *ap,int n){
  for (int i = 0; i < n; i++) {
    printf("\nDeportista [%d]\n",i+1);
    printf("\tIngresa el nombre: "); scanf("%s",(ap+i)->pers.nombre);
    printf("\tIngresa el apellido paterno: "); scanf("%s", (ap+i)->pers.ap_pater);
    printf("\tIngresa la edad: "); scanf("%d",&((ap+i)->pers.edad) );
    getchar();
    printf("\tIngresa la carrera: "); fgets((ap+i)->pers.carrera, 20, stdin);
    printf("\tIngresa los deportes realizados: "); fgets((ap+i)->deportes,30,stdin);
    printf("\tIngresa las medallas recibidas: "); scanf("%d",&((ap+i)->medallas) );
    getchar();
  }
}

void mostrar(Deportista *ap, int n){
  int medallas[] = {0,0,0,0}; //first is prom, second min, third is max, four is dep.med > prom
  calcular(ap,n,medallas);

  printf("\n-------------------------------------\n");

  printf("Numero prom. de medallas obtenidas: %d\n",medallas[0]);
  printf("Esudiantes con medallas mayor al promedio: %d\n",medallas[3]);
  printf("Estudiante con menor numero de medallas: [%d]\n",(ap+(medallas[1]))->medallas);

  printf("\t%s %s\n",(ap+(medallas[1]))->pers.nombre,(ap+(medallas[1]))->pers.ap_pater);
  printf("\tDe la carrera %s\n",(ap+(medallas[1]))->pers.carrera);

  printf("Estudiante con mayor numero de medallas: [%d]\n",(ap+(medallas[2]))->medallas);

  printf("\t%s %s\n",(ap+(medallas[2]))->pers.nombre,(ap+(medallas[2]))->pers.ap_pater);
  printf("\tDe la carrera %s",(ap+(medallas[2]))->pers.carrera);
  printf("---------------------------------------\n");
}

void calcular(Deportista *ap, int n, int *nums){
  int maxmin[] = {500,0};
  for (int i = 0; i < n; i++) {
    nums[0]+=(ap+i)->medallas;

    if(maxmin[0] > (ap+i)->medallas){
      nums[1] = i;
      maxmin[0] = (ap+i)->medallas;
    }

    if(maxmin[1] < (ap+i)->medallas){
      nums[2] = i;
      maxmin[1] = (ap+i)->medallas;
    }
  }
  nums[0]/=n;
  
  for (int i = 0; i < n; i++)
    if((ap+i)->medallas > nums[0]) nums[3]++;
}

void liberar(Deportista *ap){
  free(ap);
  manejarMsg(1);
}
