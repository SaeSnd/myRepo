#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>

typedef void typeReq; //cambiar tipo segun necesario

int valOf(void*);
void msg(int);

void dimArrBi(int *, int *);
void dimArr(int *);

void *crearArr(int);
void **crearArrBi(int, int);
void darData(typeReq*);
void darDataBi(typeReq**,int,int);

void mostrarArr(typeReq*);
void mostrarArrBi(typeReq**,int,int);

void freeBi(void **,int);
void freeArr(void*);

#endif
