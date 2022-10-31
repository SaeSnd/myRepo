#include <stdio.h>
#include <stdlib.h>

//apuntador flotante para la estructura dinamica
//otherwise, it can't be done|
typedef struct{
  float x;
  float y;
}Punto;


int menu();
Punto *crearPunto();
Punto *getData(Punto*);
void crearValDinamico(int*);

Punto *puntoMedio(Punto*);
int distanciaPuntos(Punto*);

int liberarPunto(Punto*);
int liberarVal(int*);
void mensajes(int);

int main (int argc, char *argv[])
{
  mensajes(menu());
  return 0;
}


void mensajes(int msg){
  switch (msg) {
    case 0:
      break;
    case 1:
      fprintf(stderr, "Error en menu.\n");
      break;
    default:
      fprintf(stderr, "Error desconocido.\n");
      break;
  }
}

//regresara error si algo sale mal
int menu(){

  int opcion;
  int *middlePoint;
  int *distancePoint;

  crearValDinamico(middlePoint); crearValDinamico(distancePoint);

  Punto *point;
  point = crearPunto();
  point = getData(point);

  do {
    printf("Bienvenido al MENU.\n Selecciona una opcion:\n");

    printf("\t[1.] Crear una nueva estructura PUNTO, e ingresar los valores de los Puntos.\n");
    printf("\t[2.] Obtener el punto medio entre Punto A y Punto B.\n");
    printf("\t[3.] Obtener la distancia entre los puntos A y B.\n");
    printf("\n\t[0.] Para salir del programa.\n");

    printf("Ingresa tu opcion: "); scanf("%d",&opcion);

    switch (opcion) {
      case 1:
        crearPunto(point);
        point = getData(point);
        break;
      case 2:
        *middlePoint = puntoMedio(point);
        break;
      case 3:
        *distancePoint = distanciaPuntos(point);
        break;
      case 0: break;
      default:
        printf("No un numero correcto.\n");
        continue;
    }

  } while (opcion != 0);

  mensajes(liberarPunto(point) );
  mensajes(liberarVal(middlePoint));
  mensajes(liberarVal(distancePoint));

  return 0;
}

Punto *crearPunto(){
  Punto *point;
  point =(Punto*)malloc(sizeof(Punto));

  return point;
}

Punto *getData(Punto *point){
  printf("Ingresa los valores del punto A: ");
  printf("Test 1\n");
  point->x = 12;
  printf("%f\n",*(point->x));
  //scanf("%f",point->x);
  printf("\nIngresa los valores del punto B: ");
  //scanf("%f",point->y);

  return point;
}

Punto *puntoMedio(Punto *point){
  
}

int distanciaPuntos(Punto *point){

}

void crearValDinamico(int *val){
  val =(int*) malloc(sizeof(int));
}

int liberarPunto(Punto *point){
  free(point);
}

int liberarVal(int *val){
  free(val);
  return 0;
}
