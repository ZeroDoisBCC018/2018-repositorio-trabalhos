#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  int d;
} coef;

void printa_mat(coef** mat, int neq, int nco) {
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

void libera_memoria(coef** mat, int neq) {
  for (int i = 0; i < neq; i++) {
    free(mat[i]);
  }
  free(mat);
}

long int mmc(int a, int b) {
  long int c, d, resto;

  do {
    resto = c % d;
    c = d;
    d = resto;
  } while (resto != 0);

  return (a * b) / c;
}

int escalonamento(coef** mat, int neq, int nco, int cont) {
  if (cont == neq) {
    if (mat[neq - 1][nco - 1].n != 0) {
      return 0;
    } else {
      return 1;
    }
  }

  long int aux0;
  int i = 0, j = 0;
  int a1 = (mat[cont - 1][cont - 1].n) * (mat[cont][cont - 1].d);
  int a2 = a1 * (mat[cont - 1][j].d);
  int a3 = (mat[i][j].d);
  int a4 = (mat[i][j].n) * (mat[cont - 1][cont - 1].n);
  int a5 = (mat[cont][cont - 1].d) * (mat[cont - 1][j].n);
  int a6 = (mat[cont - 1][j].n) * (mat[i][j].d);
  int a7 = (mat[cont - 1][cont - 1].d) * (mat[i][cont - 1].n);

  for (i = cont; i < neq; i++) {
    for (j = cont - 1; j < nco; j++) {
      aux0 = mmc(a2, a3);
      a3 = aux0;
      mat[i][j].n = ((a4 * a5) - (a6 * a7)) / (mat[i][j].d);
    }
  }

  int aux1, aux2;
  for (i = 0; i < neq; i++) {
    for (j = 0; j < nco; j++) {
      aux1 = mat[i][j].n;
      aux2 = mat[i][j].d;
      if (aux1 % aux2 == 0) {
        mat[i][j].n = aux1 / aux2;
        mat[i][j].d = 1;
      }
    }
  }

  cont += 1;
  escalonamento(mat, neq, nco, cont);
}

int swap(coef** mat, int neq, int nco, int cont) {
  int colisao, inst;

  if (mat[0][0].n != 0) colisao = escalonamento(mat, neq, nco, cont);

  int flag = 0;

  if (mat[0][0].n == 0) {
    do {
      flag += 1;
    } while (mat[flag][0].n != 0);

    for (int i = 0; i < nco; i++) {
      inst = mat[0][i].n;
      mat[0][i].n = mat[flag][i].n;
      mat[flag][i].n = inst;
    }
  }
  colisao = escalonamento(mat, neq, nco, cont);
  if (colisao == 1) {
    return 1;
  } else {
    return 0;
  }
}

coef** alocar_mat(char tipo, int neq, int nco) {
  coef** point = NULL;
  int mk;

  if (tipo == 'p') {
    mk = 1;
    point = (coef**)malloc(neq * sizeof(coef*));
    for (int i = 0; i < neq; i++) {
      point[i] = (coef*)malloc(nco * sizeof(coef));
    }
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &point[0][i].n, &point[0][i + 1].d);
    }
  } else {
    mk = 2;
    point = (coef**)malloc(2 * sizeof(coef*));
    for (int i = 0; i < neq; i++) {
      point[i] = (coef*)malloc(nco * sizeof(coef));
    }
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &point[0][i].n, &point[0][i + 1].d);
    }
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &point[1][i].n, &point[1][i + 1].d);
    }
  }

  char tipo2 = scanf(" %c", &tipo2);

  if (tipo2 == 'p') {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &point[mk][i].n, &point[mk][i + 1].d);
    }
  } else {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &point[mk][i].n, &point[mk][i + 1].d);
    }
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &point[mk + 1][i].n, &point[mk + 1][i + 1].d);
    }
  }
  return point;
}

int main(int argc, char const* argv[]) {
  int neq = scanf("%d", &neq);
  int nco = scanf("%d", &nco);
  char tipo1;
  int colisao, cont = 0;

  coef** mat = NULL;

  tipo1 = scanf(" %c", &tipo1);
  mat = alocar_mat(tipo1, neq, nco);

  colisao = swap(mat, neq, nco, cont);

  if (colisao == 1)
    printf("sim\n");
  else
    printf("nao\n");

  printa_mat(mat, neq, nco);

  libera_memoria(mat, neq);

  return EXIT_SUCCESS;
}
