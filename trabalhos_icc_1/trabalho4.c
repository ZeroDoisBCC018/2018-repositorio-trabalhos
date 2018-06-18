#include <stdio.h>
#include <stdlib.h>

typedef struct {
  short int numerador;
  short int denominador;
} coeficiente;

int main(int argc, char const* argv[]) {
  unsigned short int noequ = scanf("%hu ", &noequ);
  unsigned short int nocoef = scanf("%hu ", &nocoef);
  unsigned short int i, j;
  unsigned char tipo1, tipo2;

  tipo1 = getchar();

  if (tipo1 == 'p') {
    coeficiente** ponteiro1 = (coeficiente**)malloc(sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      coeficiente[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }

    for (i = 0; i < nocoef; i++) {
      ponteiro1[0][i] = scanf("%h ", &ponteiro1[0][i].numerador);
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro1[1][i] = scanf("%h ", &ponteiro1[0][i].denominador);
    }

  } else {
    coeficiente** ponteiro1 = (coeficiente**)malloc(2 * sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      coeficiente[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro1[0][i] = scanf("%h ", &ponteiro1[0][i].numerador);
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro1[0][i] = scanf("%h ", &ponteiro1[0][i].denominador);
    }
    for (j = 0; j < nocoef; j++) {
      ponteiro1[1][j] = scanf("%h ", &ponteiro1[0][j].numerador);
    }
    for (j = 0; j < nocoef; j++) {
      ponteiro1[1][j] = scanf("%h ", &ponteiro1[0][j].denominador);
    }
  }

  tipo2 = getchar();

  if (tipo2 == 'p') {
    coeficiente** ponteiro2 = (coeficiente**)malloc(sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      coeficiente[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro2[0][i] = scanf("%h ", &ponteiro2[0][i].numerador);
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro2[1][i] = scanf("%h ", &ponteiro2[0][i].denominador);
    }
  } else {
    coeficiente** ponteiro2 = (coeficiente**)malloc(2 * sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      coeficiente[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro2[0][i] = scanf("%h ", &ponteiro2[0][i].numerador);
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro2[0][i] = scanf("%h ", &ponteiro2[0][i].denominador);
    }
    for (j = 0; j < nocoef; j++) {
      ponteiro2[1][j] = scanf("%h ", &ponteiro2[0][j].numerador);
    }
    for (j = 0; j < nocoef; j++) {
      ponteiro2[1][j] = scanf("%h ", &ponteiro2[0][j].denominador);
    }
  }
}
