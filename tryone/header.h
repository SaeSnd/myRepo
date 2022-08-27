#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int typeReq; //cambiar tipo segun necesario

int valOf(void*);
void msg(int);

void dimArrBi(int *, int *);
void dimArr(int *);

typeReq *crearArr(int);
typeReq **crearArrBi(int, int);
void darData(typeReq*);
void darDataBi(typeReq**,int,int);

void mostrarArr(typeReq*);
void mostrarArrBi(typeReq**,int,int);

typeReq freeBi(void **,int);
typeReq freeArr(void*);

int promArr(typeReq**);
void fillArr(typeReq**,typeReq**,typeReq*,int,int);
int arithmeticProcess(typeReq**,typeReq**,int);

#endif
