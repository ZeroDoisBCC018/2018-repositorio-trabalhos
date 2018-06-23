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

long mmc(int a, int b) {
  long c, d, resto;
  a = c;
  b = d;

  do {
    resto = c % d;
    c = d;
    d = resto;
  } while (resto != 0);

  return (a * b) / c;
}
// falta refazer o swap no caso do pivo ser 0 de novo
int escalonamento(coef** mat, int neq, int nco, int cont) {
  if (cont == neq) {
    if (mat[neq - 1][nco - 1].n != 0) {
      return 0;
    } else {
      return 1;
    }
  }

  long aux0;
  int a1 = (mat[cont - 1][cont - 1].n) * (mat[cont][cont - 1].d);
  int a2 = a1 * (mat[cont - 1][j].d);
  int a3 = (mat[i][j].d);
  int a4 = (mat[i][j].n) * (mat[cont - 1][cont - 1].n);
  int a5 = (mat[cont][cont - 1].d) * (mat[cont - 1][j].n);
  int a6 = (mat[cont - 1][j].n) * (mat[i][j].d);
  int a7 = (mat[cont - 1][cont - 1].d) * (mat[i][cont - 1].n);

  for (int i = cont; i < neq; i++) {
    for (int j = cont - 1; j < nco; j++) {
      aux0 = mmc(a2, a3);
      a3 = aux0;
      mat[i][j].n = ((a4 * a5) - (a6 * a7)) / (mat[i][j].d);
    }
  }

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

  cont += 1;
  escalonamento(mat, neq, nco, cont);
}

int swap(coef** mat, int neq, int nco, int cont) {
  int colisao, inst;
  // isso vale so para a primeira vez
  if (mat[0][0].n != 0) colisao = escalonamento(mat, neq, nco, cont);
  // se chamar a swap de novo nao vai funcionar
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
  coef** pt = NULL;
  int mk;

  if (tipo == 'p') {
    mk = 1;
    pt = (coef**)malloc(neq * sizeof(coef*));

    for (int i = 0; i < neq; i++) {
      pt[i] = (coef*)malloc(nco * sizeof(coef));
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[0][i].n, &pt[0][i + 1].d);
    }
  } else {
    mk = 2;
    pt = (coef**)malloc(2 * sizeof(coef*));

    for (int i = 0; i < neq; i++) {
      pt[i] = (coef*)malloc(nco * sizeof(coef));
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[0][i].n, &pt[0][i + 1].d);
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[1][i].n, &pt[1][i + 1].d);
    }
  }

  char t2 = scanf(" %c", &t2);

  if (t2 == 'p') {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[mk][i].n, &pt[mk][i + 1].d);
    }
  } else {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[mk][i].n, &pt[mk][i + 1].d);
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[mk + 1][i].n, &pt[mk + 1][i + 1].d);
    }
  }
  return pt;
}

int main(int argc, char const* argv[]) {
  int neq = scanf("%d", &neq);
  int nco = scanf("%d", &nco);
  char t1;
  int colisao, cont = 0;

  coef** mat = NULL;

  t1 = scanf(" %c", &t1);
  mat = alocar_mat(t1, neq, nco);

  colisao = swap(mat, neq, nco, cont);

  if (colisao == 1) {
    printf("sim\n");
  } else {
    printf("nao\n");
  }

  printa_mat(mat, neq, nco);

  libera_memoria(mat, neq);

  return EXIT_SUCCESS;
}
