#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  int d;
} coef;

void printa_mat(coef** mat, int neq, int nco, int colisao) {
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

void libera_memoria(coef** mat, int neq) {
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
    
  if (cont == neq) {
    if (mat[neq - 1][nco - 1].n != 0) {
      return 0;
    } else {
      return 1;
    }
  }
  
  for (int i = cont; i < neq; i++) {
    for (int j = cont; j < nco; j++) {
		
      int a1 = mat[cont][cont].n;
	  int a2= mat[cont][cont].d;
	  int a3 = mat [cont][j].d;
	  int a4 = mat[cont][j].n;
	  int a5 = mat[i][j].d;
	  int a6 = mat[i][j].n;
	  int a7 = mat[i][cont].n;
	  
	  
	  long aux = mmc(a2, a3);
	  
	  mat[i][j].n = ((a6*a1)*(a2*a4)) - ((a4*a5)*(a2*a7))/a5;
    }
  }

  int aux1, aux2;
  for (int i = 0; i < neq; i++) {
    for (int j = 0; j < nco; j++) {
      aux1 = mat[i][j].n;
      aux2 = mat[i][j].d;
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
    } while (mat[flag][0].n != 0);

    for (int i = 0; i < nco; i++) {
      inst = mat[0][i].n;
      mat[0][i].n = mat[flag][i].n;
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
      scanf("%d %d ", &pt[0][i].n, &pt[0][i].d);
    }
  } else {
    mk = 2;
    pt = (coef**)malloc(2 * sizeof(coef*));

    for (int i = 0; i < neq; i++) {
      pt[i] = (coef*)malloc(nco * sizeof(coef));
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[0][i].n, &pt[0][i].d);
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[1][i].n, &pt[1][i].d);
    }
  }

  char t2 = scanf(" %c", &t2);

  if (t2 == 'p') {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[mk][i].n, &pt[mk][i].d);
    }
  } else {
    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[mk][i].n, &pt[mk][i].d);
    }

    for (int i = 0; i < nco; i++) {
      scanf("%d %d ", &pt[mk + 1][i].n, &pt[mk + 1][i].d);
    }
  }
  return pt;
}

int main(int argc, char const* argv[]) {
  int neq = scanf("%d", &neq);
  int nco = scanf("%d", &nco);
  char t1;
  int colisao;

  coef** mat;

  t1 = scanf(" %c", &t1);
  mat = alocar_mat(t1, neq, nco);

  colisao = swap(mat, neq, nco);

  printa_mat(mat, neq, nco, colisao);

  libera_memoria(mat, neq);

  return EXIT_SUCCESS;
}
