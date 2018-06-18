#include <stdio.h>
#include <stdlib.h>

typedef struct {
  short int numerador;
  short int denominador;
} coeficiente;

coeficiente** alocar_matriz(unsigned char tipo, unsigned short int noequ,
                            unsigned short int nocoef, unsigned short int i,
                            unsigned short int j) {
  coeficiente** ponteiro = NULL;

  if (tipo == 'p') {
    ponteiro = (coeficiente**)malloc(sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      ponteiro[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }

    for (i = 0; i < nocoef; i++) {
      ponteiro[0][i].numerador = scanf("%hd ", &ponteiro[0][i].numerador);
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro[1][i].denominador = scanf("%hd ", &ponteiro[0][i].denominador);
    }

  } else {
    ponteiro = (coeficiente**)malloc(2 * sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      ponteiro[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro[0][i].numerador = scanf("%hd ", &ponteiro[0][i].numerador);
    }
    for (i = 0; i < nocoef; i++) {
      ponteiro[0][i].denominador = scanf("%hd ", &ponteiro[0][i].denominador);
    }
    for (j = 0; j < nocoef; j++) {
      ponteiro[1][j].numerador = scanf("%hd ", &ponteiro[0][j].numerador);
    }
    for (j = 0; j < nocoef; j++) {
      ponteiro[1][j].denominador = scanf("%hd ", &ponteiro[0][j].denominador);
    }
  }
  return ponteiro;
}

int main(int argc, char const* argv[]) {
  unsigned short int noequ = scanf("%hu ", &noequ);
  unsigned short int nocoef = scanf("%hu ", &nocoef);
  unsigned short int i, j;
  unsigned char tipo1, tipo2;

  coeficiente** matriz1 = NULL;
  coeficiente** matriz2 = NULL;

  tipo1 = getchar();
  matriz1 = alocar_matriz(tipo1, noequ, nocoef, i, j);

  tipo2 = getchar();
  matriz2 = alocar_matriz(tipo2, noequ, nocoef, i, j);

  return 0;
}
