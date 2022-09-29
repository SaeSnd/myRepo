#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *nombre;
	int edad;
	float *peso;
	char sexo;
	float *glucosa;
}Paciente;

void msg(int);
void noPacientes(int*);
Paciente *crearStruct(Paciente*,int);
void fillPacientes(Paciente*,int);
int *promSugar(Paciente*,int);
void showPacientes(Paciente*,int*,int);

void freeArrStruct(Paciente*,int);
void freeSugar(int*);

int main(){
	int n;
	Paciente *pacientes;
	noPacientes(&n);
	pacientes=crearStruct(pacientes,n);
	fillPacientes(pacientes,n);

  int *sugarLvl;
  sugarLvl=promSugar(pacientes,n);

  showPacientes(pacientes,sugarLvl,n);
  freeArrStruct(pacientes,n);
  freeSugar(sugarLvl);


	return 0;
}

void msg(int option){
	switch(option){
		case 0: fprintf(stderr,"\nError al guardar memoria dinamica.");
			exit(1);
			break;
		case 1: 
			break;
    case 2: fprintf(stderr, "Error al eliminar puntero.\n");
      break;
		default: fprintf(stderr,"\nNo se reconoce esta opcion.");
	}
}

void noPacientes(int *x){
	printf("Cuantos pacientes desea registrar?: ");
	scanf("%d",x);
}

Paciente *crearStruct(Paciente *ap,int n){
	Paciente *tmp;
	tmp=(Paciente*)malloc(sizeof(Paciente)*n);
	if(tmp==NULL) msg(0);
  for (int i = 0; i < n; i++) {
	tmp[i].nombre=(char*)malloc(sizeof(char)*30);
	if(tmp[i].nombre==NULL) msg(0);
	tmp[i].peso=(float*)malloc(sizeof(float));
	if(tmp[i].peso==NULL) msg(0);
	tmp[i].glucosa=(float*)malloc(sizeof(float)*5);
	if(tmp[i].glucosa==NULL) msg(0);
  }
	return tmp;
}

void fillPacientes(Paciente *ap,int n){
	int x;
	printf("\nRegistre a los pacientes.");
	for(x=0;x<n;x++){
		printf("\n--Paciente no.%d\n",x+1);
		printf("\tRegistre el nombre: ");
		fflush(stdin);
	  scanf("%s",ap[x].nombre);
		printf("\tRegistre el edad: ");
		fflush(stdin);
	  scanf("%d",&ap[x].edad);
		printf("\tRegistre el peso: "); 
		fflush(stdin);
		scanf("%f",&*(ap[x].peso));
    getchar();
		printf("\tRegistra el sexo(H/M): "); 
		fflush(stdin);
		scanf("%c",&ap[x].sexo);
    if(ap[x].sexo=='h') ap[x].sexo='H';
    else if(ap[x].sexo=='m') ap[x].sexo='M';
    else if(ap[x].sexo!='H' || ap[x].sexo!='M') ap[x].sexo='N';
		for (int i = 0; i < 5; i++) {
      printf("\t|\tRegistra la glucosa de la semana %d: ",i+1);
      scanf("%f",&(ap[x].glucosa[i]));
		}
	fflush(stdin);
	}
}

int *promSugar(Paciente *ap,int n){
  int i,j;
  int *sugarLevel;
  sugarLevel=(int*)malloc(sizeof(int)*n);
  if(sugarLevel==NULL) msg(0);
  for(i=0;i<n;i++) {
    for (j = 0; j < 5; j++) {
      *(sugarLevel+i)+=ap[i].glucosa[j];
    }
    *(sugarLevel+i)/=5;
  }
  return sugarLevel;
}

void showPacientes(Paciente *ap,int *sugar,int n){
	int x;
	for(x=0;x<n;x++){
    char level[30];
    printf("----------------------------------------------------------------\n");
    printf("\nPaciente no.%d\n\n",x+1);
    printf("\tNombre: %s\n",ap[x].nombre); printf("\tEdad: %d\n",ap[x].edad); printf("\tPeso: %.2f\n",*(ap[x].peso)); printf("\tSexo: %c\n",ap[x].sexo);
    for (int i = 0; i < 5; i++) {
      printf("\t|\tGlucosa semana %d: %.2f\n",i+1,ap[x].glucosa[i]);
    }

    if (*(sugar+x) < 70) {
    strcpy(level,"Hipoglucemia");
    } else if(*(sugar+x) >= 80 && *(sugar+x) <= 115)
    strcpy(level,"Normal");
    else if (*(sugar+x) >= 150 && *(sugar+x) <= 180)
    strcpy(level,"Elevado");
    else if (*(sugar+x) > 215) {
    strcpy(level,"Altamente elevado");
    }
    printf("\n\tPromedio Glucosa: %d. Nivel %s\n",*(sugar+x),level);
	}
}

void freeArrStruct(Paciente *ap,int n){
  for (int i = 0; i < n; i++) {
    free(ap[i].nombre);
    free(ap[i].peso);
    free(ap[i].glucosa);
  }
  free(ap);
}

void freeSugar(int *ap){
  free(ap);
}
