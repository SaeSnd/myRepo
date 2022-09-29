#include<stdio.h>
#include<stdlib.h>

int **crearParal();
void fillParal(int**);
void showParal(int**);
int *vol(int**);
void mostrarVol(int*);
void freeAll(int**,int*);

int main(){
	int **paralelipedo,*volumen;
  paralelipedo=crearParal();
	fillParal(paralelipedo);
  showParal(paralelipedo);
	volumen=vol(paralelipedo);
	mostrarVol(volumen);
  freeAll(paralelipedo,volumen);

	return 0;
}

int **crearParal(){
  int i;
  int **tmp=(int**)malloc(sizeof(int*)*3);
  for(i=0;i<3;i++){
    *(tmp+i)=(int*)malloc(sizeof(int)*3);
  }
  return tmp;
}

void fillParal(int **paralelipedo){
	int i,j;
	char c='A';
  for(i=0;i<3;i++){
    printf("\n\tVector %c:\n",c+i);
    for (j = 0; j < 3; j++) {
      printf("[%d][%d]: ",i,j);
      scanf("%d",&paralelipedo[i][j]);
    }
printf("\n");
  }
}

void showParal(int **paralelipedo){
	int i,j;
	char vector = 'A';
	for(i=0;i<3;i++){
		printf("\nVector %c: ",vector+i);
		for(j=0;j<3;j++){
			printf("%d ",paralelipedo[i][j] );
		}
	}
}

int *vol(int **paralelipedo){
	int *answer;
  answer=(int*)malloc(sizeof(int));

	*answer=paralelipedo[0][0]*paralelipedo[1][1]*paralelipedo[2][2]+paralelipedo[1][0]*paralelipedo[2][1]*paralelipedo[0][2]+paralelipedo[2][0]*paralelipedo[0][1]*paralelipedo[1][2]-paralelipedo[0][2]*paralelipedo[1][1]*paralelipedo[2][0]-paralelipedo[1][2]*paralelipedo[2][1]*paralelipedo[0][0]-paralelipedo[2][2]*paralelipedo[0][1]*paralelipedo[1][0];
  printf("%d\n",*answer);
	return answer;
}

void mostrarVol(int *volumen){
	printf("\nEl volumen es: %d\n",*volumen);
}

void freeAll(int **vectores,int *vol){
  int i;
  free(vol);
  for (i = 0; i < 3; i++)
    free(*(vectores+i));
  free(vectores);
}
