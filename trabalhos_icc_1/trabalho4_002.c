#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
  int den;
} coeficiente;

void printa_mat(coeficiente** mat, int noequ, int nocoef) {
  int aux1, aux2;
  for (int i = 0; i < noequ; i++) {
    for (int j = 0; j < nocoef; j++) {
      aux1 = mat[i][j].num;
      aux2 = mat[i][j].den;
      if (aux1 % aux2 == 0) {
        mat[i][j].num = aux1 / aux2;
        mat[i][j].den = 1;
      }
    }
  }

  for (int i = 0; i < nocoef; i++) {
    for (int j = 0; j < noequ; j++) {
      if (mat[i][j].den == 1) {
        printf("%d\t", mat[i][j].num);
      } else {
        printf("%d/%d\t", mat[i][j].num, mat[i][j].den);
      }
    }
    printf("\n");
  }
}

void libera_memoria(coeficiente** mat, int noequ) {
  for (int i = 0; i < noequ; i++) {
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

int escalonamento(coeficiente** mat, int noequ, int nocoef, int n_vezes) {
  if (n_vezes == noequ) {
    if (mat[noequ - 1][nocoef - 1].num != 0) {
      return 0;
    } else {
      return 1;
    }
  }

  long int aux0;
  int i = 0, j = 0;
  int a1 =
      (mat[n_vezes - 1][n_vezes - 1].num) * (mat[n_vezes][n_vezes - 1].den);
  int a2 = a1 * (mat[n_vezes - 1][j].den);
  int a3 = (mat[i][j].den);
  int a4 = (mat[i][j].num) * (mat[n_vezes - 1][n_vezes - 1].num);
  int a5 = (mat[n_vezes][n_vezes - 1].den) * (mat[n_vezes - 1][j].num);
  int a6 = (mat[n_vezes - 1][j].num) * (mat[i][j].den);
  int a7 = (mat[n_vezes - 1][n_vezes - 1].den) * (mat[i][n_vezes - 1].num);

  for (i = n_vezes; i < noequ; i++) {
    for (j = n_vezes - 1; j < nocoef; j++) {
      aux0 = mmc(a2, a3);
      a3 = aux0;
      mat[i][j].num = ((a4 * a5) - (a6 * a7)) / (mat[i][j].den);
    }
  }

  int aux1, aux2;
  for (i = 0; i < noequ; i++) {
    for (j = 0; j < nocoef; j++) {
      aux1 = mat[i][j].num;
      aux2 = mat[i][j].den;
      if (aux1 % aux2 == 0) {
        mat[i][j].num = aux1 / aux2;
        mat[i][j].den = 1;
      }
    }
  }

  n_vezes += 1;
  escalonamento(mat, noequ, nocoef, n_vezes);
}

int swap(coeficiente** mat, int noequ, int nocoef, int n_vezes) {
  int colisao, inst;

  if (mat[0][0].num != 0) colisao = escalonamento(mat, noequ, nocoef, n_vezes);

  int flag = 0;

  if (mat[0][0].num == 0) {
    do {
      flag += 1;
    } while (mat[flag][0].num != 0);

    for (int i = 0; i < nocoef; i++) {
      inst = mat[0][i].num;
      mat[0][i].num = mat[flag][i].num;
      mat[flag][i].num = inst;
    }
  }
  colisao = escalonamento(mat, noequ, nocoef, n_vezes);
  if (colisao == 1) {
    return 1;
  } else {
    return 0;
  }
}

coeficiente** alocar_mat(char tipo, int noequ, int nocoef) {
  coeficiente** point = NULL;
  int mk;

  if (tipo == 'p') {
    mk = 1;
    point = (coeficiente**)malloc(noequ * sizeof(coeficiente*));
    for (int i = 0; i < noequ; i++) {
      point[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (int i = 0; i < nocoef; i++) {
      scanf("%d %d ", &point[0][i].num, &point[0][i + 1].den);
    }
  } else {
    mk = 2;
    point = (coeficiente**)malloc(2 * sizeof(coeficiente*));
    for (int i = 0; i < noequ; i++) {
      point[i] = (coeficiente*)malloc(nocoef * sizeof(coeficiente));
    }
    for (int i = 0; i < nocoef; i++) {
      scanf("%d  %d ", &point[0][i].num, &point[0][i + 1].den);
    }
    for (int i = 0; i < nocoef; i++) {
      scanf("%d %d ", &point[1][i].num, &point[1][i + 1].den);
    }
  }

  char tipo2 = getchar();

  if (tipo2 == 'p') {
    for (int i = 0; i < nocoef; i++) {
      scanf("%d %d ", &point[mk][i].num, &point[mk][i + 1].den);
    }
  } else {
    for (int i = 0; i < nocoef; i++) {
      scanf("%d  %d ", &point[mk][i].num, &point[mk][i + 1].den);
    }
    for (int i = 0; i < nocoef; i++) {
      scanf("%d %d ", &point[mk + 1][i].num, &point[mk + 1][i + 1].den);
    }
  }
  return point;
}

int main(int argc, char const* argv[]) {
  int noequ = scanf("%d ", &noequ);
  int nocoef = scanf("%d ", &nocoef);
  char tipo1;
  int colisao, n_vezes = 0;

  coeficiente** mat = NULL;

  tipo1 = getchar();
  mat = alocar_mat(tipo1, noequ, nocoef);

  colisao = swap(mat, noequ, nocoef, n_vezes);

  if (colisao == 1)
    printf("sim\n");
  else
    printf("nao\n");

  printa_mat(mat, noequ, nocoef);

  libera_memoria(mat, noequ);

  return EXIT_SUCCESS;
}
