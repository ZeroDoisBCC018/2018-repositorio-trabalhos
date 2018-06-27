// Escalonamento Gaussiano:
// Este programa tenta calcular se ha colisao entre um plano e uma reta
// dadas as suas equacoes, que sao escalonadas numa matriz.
// Trabalho 4 de ICC 1 - Prof. Moacir Ponti - Entrega dia 25/06/2018
// Joao Vitor Nascimento Villaca - ICMC/USP - NoUSP: 10724239
#include <stdio.h>
#include <stdlib.h>

// definicao da struct dos coeficientes
typedef struct {
  int n;  // numerador
  int d;  // denominador
} coef;

// esta funcao imprime a matriz, fazendo simplificacao dos coeficientes
void printa_matriz(coef** mat, int neq, int nco, int colisao) {
  int aux1, aux2;

  for (int i = 0; i < neq; i++) {
    for (int j = 0; j < nco; j++) {
      aux1 = mat[i][j].n;
      aux2 = mat[i][j].d;

      // checando se e' possivel simplificar:
      if (aux1 % aux2 == 0) {
        mat[i][j].n = aux1 / aux2;
        mat[i][j].d = 1;
      }
    }
  }

  if (colisao == 1) {
    printf("sim\n");
  } else {
    printf("nao\n");
  }

  for (int i = 0; i < nco; i++) {
    for (int j = 0; j < neq; j++) {
      if (mat[i][j].d == 1) {
        printf("%d\t", mat[i][j].n);
      } else {
        printf("%d/%d\t", mat[i][j].n, mat[i][j].d);
      }
    }
    printf("\n");
  }
}

// essa funcao libera a memoria da matriz alocada dinamicamente
void libera_matriz(coef** mat, int neq) {
  for (int i = 0; i < neq; i++) {
    free(mat[i]);
  }
  free(mat);
}

// algoritmo que calcula o mmc entre dois numeros
long int mmc(int x, int y) {
  long int ememece;
  if (x >= y)
    ememece = x;
  else
    ememece = y;
  while ((ememece % x) != 0 || (ememece % y) != 0) {
    ememece++;
  }
  return ememece;
}

// funcao de escalonamento
int escalonamento(coef** mat, int neq, int nco, int cont) {
  // caso base: quando chega na ultima linha
  if (cont == neq - 1) {
    // cada retorno depende do valor de 'd' na ultima linha
    // determinando se ha colisao ou nao
    if (mat[neq - 1][nco - 1].n != 0) {
      return 0;
    } else {
      return 1;
    }
  }

  coef x, w;
  int mmc1;

  // algoritmo de escalonamento
  for (int i = cont; i < neq; i++) {
    x.n = mat[i][cont].n * mat[cont][cont].d;
    x.d = mat[i][cont].d * mat[cont][cont].n;

    for (int j = cont; j < nco; j++) {
      w.n = x.n * mat[cont][j].n;
      w.d = x.d * mat[cont][j].d;

      // o mmc e' calculado para a subtracao ser realizada
      // sem problemas
      if (w.d == mat[i][j].d) {
        mat[i][j].n -= w.n;
      } else {
        mmc1 = mmc(w.d, mat[i][j].d);
        w.n = (mmc1 / w.d) * w.n;
        w.n = mmc1;
        mat[i][j].n = (mmc1 / mat[i][j].d) * mat[i][j].n;
        mat[i][j].d = mmc1;
        mat[i][j].n -= w.n;
      }
    }
  }
  // cont: variavel que conta o numero de escalonamentos
  cont += 1;

  escalonamento(mat, neq, nco, cont);
  return 0;
}

// funcao que realiza a troca entre duas linhas de uma matriz
int swap(coef** mat, int neq, int nco) {
  int colisao, inst;
  int cont = 0;
  static int pivo = 0;

  if (mat[pivo][pivo].n != 0) colisao = escalonamento(mat, neq, nco, cont);

  int flag = 0;

  // este 'do while' procura a primeira linha cujo o primeiro elemento NAO e'
  // zero
  if (mat[pivo][pivo].n == 0) {
    do {
      flag += 1;
    } while (mat[flag][0].n != 0);

    // troca das linhas:
    for (int i = pivo; i < nco; i++) {
      inst = mat[pivo][i].n;
      mat[pivo][i].n = mat[flag][i].n;
      mat[flag][i].n = inst;
    }
  }

  // cont e pivo sao igualados para passar a posicao do pivo para a funcao swap
  // ja que variaveis estaticas sao visiveis somente no escopo em que sao
  // inicializadas
  pivo += 1;
  cont = pivo;
  colisao = escalonamento(mat, neq, nco, cont);

  if (colisao == 1) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const* argv[]) {
  int neq, nco;

  // escaneando os numeros
  scanf("%d", &neq);
  scanf("%d", &nco);

  // alocacao dinamica da matriz
  coef** mat = malloc(neq * sizeof(coef));
  for (int i = 0; i < neq; i++) {
    mat[i] = (coef*)malloc(nco * sizeof(coef));
  }

  // escaneando os coeficientes para cada caso (reta e plano)
  char t1, t2;
  scanf(" %c", &t1);

  if (t1 == 'p') {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d", &mat[0][i].n, &mat[0][i].d);
    }
    scanf(" %c", &t2);

    if (t2 == 'p') {
      for (int i = 0; i < nco; i++) {
        scanf("%d %d", &mat[1][i].n, &mat[1][i].d);
      }

      if (t2 == 'r') {
        for (int i = 1; i < 2; i++) {
          for (int j = 0; j < nco; j++) {
            scanf("%d %d", &mat[i][j].n, &mat[i][j].d);
          }
        }
      }
    }
  }
  if (t1 == 'r') {
    for (int i = 1; i < 2; i++) {
      for (int j = 0; j < nco; j++) {
        scanf("%d %d", &mat[i][j].n, &mat[i][j].d);
      }
    }

    if (t2 == 'p') {
      for (int i = 0; i < nco; i++) {
        scanf("%d %d", &mat[2][i].n, &mat[2][i].d);
      }

      if (t2 == 'r') {
        for (int i = 2; i < 3; i++) {
          for (int j = 0; j < nco; j++) {
            scanf("%d %d", &mat[i][j].n, &mat[i][j].d);
          }
        }
      }
    }
  }

  int colisao;

  // a colisao e' determinada pelo retorno "booleano" da funcao swap
  colisao = swap(mat, neq, nco);

  printa_matriz(mat, neq, nco, colisao);

  libera_matriz(mat, neq);

  return EXIT_SUCCESS;
}
