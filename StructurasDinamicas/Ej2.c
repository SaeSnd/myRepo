#include <stdio.h>
#include <stdlib.h>

#define VAL_MAX 50

typedef struct{
  int edad;
  char nombre[VAL_MAX];
  char direccion[VAL_MAX];
  char telefono[20];
} Persona;


int preguntarData();

Persona *crearGente(int);

void fillGente(Persona*,int);

void showGente(Persona*,int);
void ordenarGente(Persona*,int);
void liberar(Persona*);

int main (int argc, char *argv[])
{
  int n;
  n = preguntarData();
  Persona *gente;
  gente = crearGente(n);
  fillGente(gente,n);

  showGente(gente,n);
  liberar(gente);

  return 0;
}

void msg(int n){
  char *error[] = {"No hay memoria disponible... ","Memoria liberada. "};
  printf("%s\n",error[n]);
}

int preguntarData(){
  int n;
  printf("¿Cuantas personas son?: "); scanf("%d",&n);
  getchar();
  return n;
}


Persona *crearGente(int n){
  Persona *ap;
  ap = (Persona*)malloc(sizeof(Persona));
  return ap;
}


void fillGente(Persona *ap, int n){
  int tmp;
  for (int i = 0; i < n; i++) {
    printf("--Persona [%d]:\n",i+1);
    fflush(stdin);
    printf("Ingresa el nombre: "); fgets((ap+i)->nombre,VAL_MAX,stdin); 
    printf("Ingresa la edad: "); scanf("%d",&((ap+i)->edad));
    getchar();
    printf("Ingresa la direccion: "); fgets((ap+i)->direccion,VAL_MAX,stdin);
    printf("Ingresa el numero: "); fgets((ap+i)->telefono,VAL_MAX,stdin);
  }
}

void showGente(Persona *ap, int n){
  ordenarGente(ap,n);
  for (int i = 0; i < n; i++) {
    printf("\n------------[%d]--------------\n",i+1);
    printf("%s%d años\n",(ap+i)->nombre,(ap+i)->edad);
    printf("Vive en %s",(ap+i)->direccion);
    printf("Numero de telefono: %s",(ap+i)->telefono);
  }
} 

void ordenarGente(Persona *ap,int n){
  int i, j;
  Persona tmp;
  for(i = 0; i < n; i++){
    for(j = 0; j < n - i - 1; j++){
      if((ap+j)->edad < (ap+j+1)->edad){
        
        tmp = ap[j];
        ap[j] = ap[j+1];
        ap[j+1] = tmp;
      }
    }
  }
}

void liberar(Persona *ap){
  free(ap);
  msg(1);
}
