#ifndef _complejo_
#define _complejo_

typedef struct {
    float real;
    float imaginario;
} Complejo;

typedef Complejo * COMPLEJO;

void manejaMsg(int);

COMPLEJO creaComplejo();
void asignaReal(COMPLEJO, float);
void asignaImaginario(COMPLEJO, float);
float obtenReal(COMPLEJO);
float obtenImaginario(COMPLEJO);

COMPLEJO suma(COMPLEJO, COMPLEJO);

#endif // !_complejo_