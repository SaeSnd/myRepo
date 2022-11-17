typedef struct {
  int a;
  int b;
  int c;
} ecuacion;

typedef ecuacion * ECUACION;
typedef soluciones * SOLUCIONES;

void mandarMsg(int);

ECUACION crearEcuac();
void ponA(ECUACION, int);
void ponB(ECUACION, int);
void ponC(ECUACION, int);
int obtenA(ECUACION);
int obtenB(ECUACION);
int obtenC(ECUACION);

SOLUCIONES crearSoluciones();

double determinante(ECUACION);
double *obtenerSoluciones(ECUACION);
//obtener raices reales y complejas.
