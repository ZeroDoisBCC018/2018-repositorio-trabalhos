#include <stdio.h>
#include <stdlib.h>

typedef struct {
  short int numerador;
  short int denominador;
} coeficiente;

coeficiente** alocar_matriz(char tipo, unsigned short int noequ, unsigned short int nocoef, unsigned short int i) {
  coeficiente** ponteiro = NULL;
  unsigned short int mk;

  if (tipo == 'p') {
    mk = 1;
    ponteiro = (coeficiente**)malloc(noequ * sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      ponteiro[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (i = 0; i < nocoef; i++) {
      scanf("%hd %hd ", &ponteiro[0][i].numerador,
            &ponteiro[0][i + 1].denominador);
    }
  } else {
    mk = 2;
    ponteiro = (coeficiente**)malloc(2 * sizeof(coeficiente*));
    for (i = 0; i < noequ; i++) {
      ponteiro[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (i = 0; i < nocoef; i++) {
      scanf("%hd  %hd ", &ponteiro[0][i].numerador,
            &ponteiro[0][i + 1].denominador);
    }
    for (i = 0; i < nocoef; i++) {
      scanf("%hd %hd ", &ponteiro[1][i].numerador,
            &ponteiro[1][i + 1].denominador);
    }
  }

  char tipo2 = getchar();

  if (tipo == 'p') {
    for (i = 0; i < nocoef; i++) {
      scanf("%hd %hd ", &ponteiro[mk][i].numerador,
            &ponteiro[mk][i + 1].denominador);
    }
  } else {
    for (i = 0; i < nocoef; i++) {
      scanf("%hd  %hd ", &ponteiro[mk][i].numerador,
            &ponteiro[mk][i + 1].denominador);
    }
    for (i = 0; i < nocoef; i++) {
      scanf("%hd %hd ", &ponteiro[mk + 1][i].numerador,
            &ponteiro[mk + 1][i + 1].denominador);
    }
  }
  return ponteiro;
}

int main(int argc, char const* argv[]) {
  unsigned short int noequ = scanf("%hu ", &noequ);
  unsigned short int nocoef = scanf("%hu ", &nocoef);
  unsigned short int i = 0;
  char tipo1;

  coeficiente** matriz = NULL;

  tipo1 = getchar();
  matriz = alocar_matriz(tipo1, noequ, nocoef, i);

  return 0;
}
