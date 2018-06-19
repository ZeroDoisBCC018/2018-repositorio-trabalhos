#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  short int numerador;
  short int denominador;
} coeficiente;

bool escalonamento(coeficiente** matriz, unsigned short int noequ, unsigned short int nocoef, unsigned short int i){
	
	if(matriz[noequ-1][0].numerador && matriz[noequ-1][1].numerador && matriz[noequ-1][2].numerador == 0){
		if(matriz[noequ-1][nocoef].numerador != 0)
			return false;
	 } else {
		 return true;
	 }
	 return false;
}

bool swap(coeficiente** matriz, unsigned short int noequ, unsigned short int nocoef, unsigned short int i) {
  short int inst, flag = 0;

  if (matriz[0][0].numerador == 0) {
    do {
      i++;
      flag = i;
    } while (matriz[i][0].numerador != 0);

    for (i = 0; i < nocoef; i++) {
      inst = matriz[0][i].numerador;
      matriz[0][i].numerador = matriz[flag][i].numerador;
      matriz[flag][i].numerador = inst;
    }
  }	  
  bool colisao = escalonamento(matriz, noequ, nocoef, i);
  if(colisao == true){
	   return true;
   } else {
	   return false;
		}
}

coeficiente** alocar_matriz(unsigned char tipo, unsigned short int noequ, unsigned short int nocoef, unsigned short int i) {
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

  if (tipo2 == 'p') {
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
  unsigned char tipo1;
  bool colisao;

  coeficiente** matriz = NULL;

  tipo1 = getchar();
  matriz = alocar_matriz(tipo1, noequ, nocoef, i);
  
  colisao = swap(matriz, noequ, nocoef, i);
  if(colisao == true) printf("sim");
	else printf("nao");

  return 0;
}
