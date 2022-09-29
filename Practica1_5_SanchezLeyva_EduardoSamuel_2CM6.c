#include<stdio.h>
#include<stdlib.h>

void reqSize(int*);
int **crearArr(int);
void fillArr(int**,int**,int);
void mostrarMtz(int**,int);
void liberarMtz(int**,int);
void requestPQ(int*,int*);

int **multConstMatriz(int **,int,int);
int **traspuestaArr(int**,int**,int);

int main(int argc, char const *argv[])
{
    int n,p,q;
    int **a,**b;
    reqSize(&n);
    a=crearArr(n);
    b=crearArr(n);
    //rellena los 2 arreglos simult.
    fillArr(a,b,n);

    requestPQ(&p,&q);

    mostrarMtz(a,n);
    mostrarMtz(b,n);

    //multiplica por constante y devuelve el mismo apuntador
    a=multConstMatriz(a,p,n);
    b=multConstMatriz(b,q,n);

    int **c;
    //rellena c con la operacion indicada
    c=traspuestaArr(a,b,n);

    mostrarMtz(a,n);
    mostrarMtz(b,n);
    mostrarMtz(c,n);

    liberarMtz(a,n);
    liberarMtz(b,n);
    liberarMtz(c,n);
    return 0;
}

void reqSize(int *n){
    printf("Ingresa n: "); scanf("%d",n);
}

int **crearArr(int n){
    int **tmp;
    tmp=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
        *(tmp+i)=(int*)malloc(sizeof(int)*n);
    return tmp;
}

void fillArr(int **a,int **b,int n){
    int i,j;
    printf("\nRellena el arreglo no.1: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("\tDato[%d][%d]=",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nRellena el arreglo no.2: \n"); 
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("\tDato[%d][%d]=",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
}

void requestPQ(int*p,int*q){
    printf("\nIngresa p: "); scanf("%d",p);
    printf("Ingresa q: "); scanf("%d",q);
}

int **multConstMatriz(int **matriz,int x,int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            matriz[i][j]*=x;
        }
    }
    return matriz;
}

int **traspuestaArr(int**a,int**b,int n){
    int **tmp;
    tmp=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
        *(tmp+i)=(int*)malloc(sizeof(int)*n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j]=a[j][i]+b[j][i];
        }
        
    }
    
    return tmp;
}

void mostrarMtz(int **mtz, int n){
    int i, j;
    printf("\n-----------------------------------------\n");
    printf("Los datos de la Matriz son: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ",mtz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void liberarMtz(int **mtz,int fil){
    int i;
    for(i=0; i<fil; i++)
        free(mtz[i]);//libera columnas
    free(mtz); //libera filas
}
