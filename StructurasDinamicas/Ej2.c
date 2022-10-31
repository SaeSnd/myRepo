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

int main (int argc, char *argv[])
{
  int n;
  n = preguntarData();
  Persona *gente;
  gente = crearGente(n);
  fillGente(gente,n);

  showGente(gente,n);

  return 0;
}

int preguntarData(){
  int n;
  printf("¿Cuantas personas son?: "); scanf("%d",&n);
  return n;
}


Persona *crearGente(int n){
  Persona *ap;
  ap = (Persona*)malloc(sizeof(Persona));
  return ap;
}


void fillGente(Persona *ap, int n){
  for (int i = 0; i < n; i++) {
    printf("--Persona [%d]:\n",i);
    printf("Ingresa la edad: "); scanf("%d",&(ap->edad));
    printf("Ingresa el nombre: "); fgets(ap->nombre,VAL_MAX,stdin); 
    getchar();

    printf("Ingresa la direccion: "); fgets(ap->direccion,VAL_MAX,stdin);
    getchar();

    printf("Ingresa el numero: "); fgets(ap->telefono,VAL_MAX,stdin);
    getchar();
  }
}

void showGente(Persona *ap, int n){
  ordenarGente(ap,n);

} 

void ordenarGente(Persona *ap,int n){
  int i, j;
  Persona tmp;
  for(i = 0; i < n; i++){
    for(j = 1; j < n - i - 1; j++){
      if((ap+j)->edad < (ap+j+1)->edad){
        
        tmp = ap[j];
        ap[j] = ap[j+1];
        ap[j+1] = tmp;
      }
    }
  }
}


