#include <stdio.h>
#include <stdlib.h>

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
void showPacientes(Paciente*,int);

//void freeArrStruct(Persona*,int);

int main(){
	int n;
	Paciente *pacientes;
	noPacientes(&n);
	pacientes=crearStruct(pacientes,n);
	fillPacientes(pacientes,n);
	return 0;
}

void msg(int option){
	switch(option){
		case 0: fprintf(stderr,"\nError al guardar memoria dinamica.");
			exit(1);
			break;
		case 1: 
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
	tmp->nombre=(char*)malloc(sizeof(char)*30);
	if(tmp->nombre==NULL) msg(0);
	tmp->peso=(float*)malloc(sizeof(float));
	if(tmp->peso==NULL) msg(0);
	tmp->glucosa=(float*)malloc(sizeof(float)*5);
	if(tmp->glucosa==NULL) msg(0);
	return tmp;
}

void fillPacientes(Paciente *ap,int n){
	int x;
	printf("\nRegistre a los pacientes.");
	for(x=0;x<n;x++){
		printf("\n--Paciente no.%d\n",x+1);
		printf("\tRegistre el nombre: ");
		fflush(stdin);
	       	scanf("%[^\n]",(ap+x)->nombre);
		printf("\tRegistre el edad: ");
		fflush(stdin);
	       	scanf("%d",&(ap+x)->edad);
		printf("\tRegistre el peso: "); 
		fflush(stdin);
		scanf("%f",(ap+x)->peso);
		printf("\tRegistra el sexo: "); 
		fflush(stdin);
		scanf("%c",&(ap+x)->sexo);
		//printf("\tRegistra su glucosa(separado por espacios): "); scanf("%f %f %f %f %f",(ap+x)->glucosa, (ap+x)->glucosa+1 ,(ap+x)->glucosa+2 ,ap+x->glucosa+3 ,ap+x->glucosa+4 );
	fflush(stdin);
	}
}

void showPacientes(Paciente *ap,int n){
	int x;
	for(x=0;x<n;x++){
	
	}
}


