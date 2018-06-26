#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  int d;
} coef;

void printa_matriz(coef** mat, int neq, int nco, int colisao) {
  int aux1, aux2;
  for (int i = 0; i < neq; i++) {
    for (int j = 0; j < nco; j++) {
      aux1 = mat[i][j].n;
      aux2 = mat[i][j].d;
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

void libera_matriz(coef** mat, int neq) {
  for (int i = 0; i < neq; i++) {
    free(mat[i]);
  }
  free(mat);
}

long mmc(int a, int b) {
  long c, d, resto;
  c = a;
  d = b;

  do {
    resto = c % d;
    c = d;
    d = resto;
  } while (resto != 0);

  return (a * b) / c;
}
//###########################################################//
int escalonamento(coef** mat, int neq, int nco, int cont) {
	
  if (cont == neq - 1) {
    if (mat[neq - 1][nco - 1].n != 0) {
      return 0;
    } else {
      return 1;
    }
  }
  
  coef x;
  
  for (int i = cont; i < neq; i++) {
    for (int j = cont; j < nco; j++) {
		
      int a1 = mat[cont][cont].n; //pivo
      int a2 = mat[cont][cont].d;
      int a3 = mat[cont][j].d;//coef pivo
      int a4 = mat[cont][j].n;
      int a5 = mat[i][j].d;//coef sub
      int a6 = mat[i][j].n;
      int a7 = mat[i][cont].n;
      int a8 = mat[i][cont].d;
      
      x.n = (a2*a7);
      x.d = (a1*a8);
      a1 = a1*x.n;
      a2 = a1*x.d;      
      
      long aux = mmc(a3, a5);
      mat[i][j].d = aux;
      mat[i][j].n = (aux/a5)*a6;
      mat[i][j].n -= (aux/a1)*a3;
    }
  }

  cont += 1;

  escalonamento(mat, neq, nco, cont);
  return 0;
}

int swap(coef** mat, int neq, int nco) {
  int colisao, inst;
  int cont = 0;
  static int pivo = 0;

  if (mat[pivo][pivo].n != 0) colisao = escalonamento(mat, neq, nco, cont);

  int flag = 0;

  if (mat[pivo][pivo].n == 0) {
    do {
      flag += 1;
    } while (mat[flag][0].n == 0);

    for (int i = pivo; i < nco; i++) {
      inst = mat[pivo][i].n;
      mat[pivo][i].n = mat[flag][i].n;
      mat[flag][i].n = inst;
    }
  }

  pivo += 1;
  cont = pivo;
  colisao = escalonamento(mat, neq, nco, cont);

  if (colisao == 1) {
    return 1;
  } else {
    return 0;
  }
}
//###############################################//
int main(int argc, char const* argv[]) {
  int neq, nco;
  scanf("%d", &neq);
  scanf("%d", &nco);

  coef** mat = malloc(neq * sizeof(coef));
  for (int i = 0; i < neq; i++) {
    mat[i] = (coef*)malloc(nco * sizeof(coef));
  }

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

  colisao = swap(mat, neq, nco);

  printa_matriz(mat, neq, nco, colisao);

  libera_matriz(mat, neq);

  return EXIT_SUCCESS;
}
