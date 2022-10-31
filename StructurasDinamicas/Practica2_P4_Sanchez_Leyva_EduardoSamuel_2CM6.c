#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int dia, ano;
    char mes[25];
} Info_fecha;

typedef struct {
    char *nombre;
    int edad;
    Info_fecha *fe;
} Alumno;

void msg(int);

void preguntarCantidad(int*);
Alumno *crearAlumnos(int);
void preguntarAlumnos(Alumno*,int);
void preguntarMes(char*);

Alumno *porMes(Alumno*, int, char*);
void mostrar(Alumno*,int);
void mostrarB(Alumno*,int);
void liberarAlumnos(Alumno*,int);
void liberarChar(char*);

int main(int argc, char const *argv[])
{
    int n;
    char *mes;
    Alumno *alumnos,*B;
    preguntarCantidad(&n);
    alumnos = crearAlumnos(n);
    preguntarAlumnos(alumnos,n);

    preguntarMes(mes);
    mostrar(alumnos,n);
    B = porMes(alumnos,n,mes);
    mostrarB(alumnos,n);

    liberarAlumnos(alumnos,n);
    liberarAlumnos(B,n);
    liberarChar(mes);

    return 0;
}

void msg(int n){
    switch (n)
    {
    case 0:
        break;
    case 1:
        fprintf(stderr,"Error.");
        exit(-1);
    default:
        break;
    }
}

void preguntarCantidad(int *n){
    printf("Cuantos alumnos registra?: "); scanf("%d",n);
}

Alumno *crearAlumnos(int n){
    Alumno *ap;
    ap = (Alumno*)malloc(sizeof(Alumno)*n);
    msg((ap == NULL) ? 1 : 0);

    for (int i = 0; i < n; i++){
        (ap + i)->fe = (Info_fecha*)malloc(sizeof(Info_fecha)*2);
        msg(((ap + i)->fe == NULL) ? 1 : 0);
        (ap + i)->nombre = (char*)malloc(sizeof(char)*40);
        msg(((ap + i)->nombre == NULL) ? 1 : 0);
    }
    return ap;
}

void preguntarAlumnos(Alumno *ap, int n){
    for (int i = 0; i < n; i++)
    {
        printf("Alumno [%d]: \n",i+1);
        getc(stdin);
        printf("\tIngresa el nombre: "); fgets((ap + i)->nombre, 40, stdin);
        getc(stdin);
        printf(" \tIngresa la edad: "); scanf("%d",&((ap + i)->edad));
        for (int x = 0; x < 2; x++)
        {
            printf("\t%s\n",(x) ? "Ingresa la fecha de nacimiento: " : "Ingresa la fecha de ingreso a la institucion: ");
            getc(stdin);
            printf("\t\tDia: "); scanf("%d",&((ap + i)->fe->dia));
            getc(stdin);
            printf("\t\tMes: "); scanf("%s",(ap + i)->fe->mes);
            getc(stdin);
            printf("\t\tAnio: "); scanf("%d",&((ap + i)->fe->ano));
        }
    }

}

void preguntarMes(char *mes){
    mes = (char*)malloc(sizeof(char)*25);
    getc(stdin);
    printf("Ingresa el mes de comparacion: "); scanf("%s",mes);
}

Alumno *porMes(Alumno *A, int num, char *mes){
    Alumno *B;
    int n = 0;
    B = crearAlumnos(num);
    for (int i = 0; i < num; i++)
    {
        if(strcasecmp(mes,(A + i)->fe->mes)){
            strcpy((B + n)->fe->mes,(A + i)->fe->mes);
            n++;
        }
    }
    return B;
}

void mostrar(Alumno *ap, int n){
    for (int i = 0; i < n; i++)
    {
        printf("Alumno%d: \n",i+1);

        printf("\tNombre: %s\n",(ap + i)->nombre);
        printf(" \tEdad: %d\n",((ap + i)->edad));
        for (int x = 0; x < 2; x++)
        {
            printf("\t%s\n",(x) ? "Fecha de nacimiento: " : "Fecha de ingreso a la institucion: ");
            printf("\t\tDia: %d\n",((ap + i)->fe->dia));
            printf("\t\tMes: %s\n",(ap + i)->fe->mes);
            printf("\t\tAnio: %d\n",((ap + i)->fe->ano));
        }
    }

}

void mostrarB(Alumno *ap, int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n\t%s\n",(ap + i)->nombre);
        printf(" \t%d\n",((ap + i)->edad));
    }
}

void liberarAlumnos(Alumno *ap,int n){
    for (int i = 0; i < n; i++)
    {
        free((ap + i)->fe);
        msg(0);
        free((ap + i)->nombre);
        msg(0);
    }
    free(ap);
    msg(0);
}

void liberarChar(char *ap){
    free(ap);
    msg(0);
}
