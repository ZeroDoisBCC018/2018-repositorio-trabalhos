#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

typedef struct Atributos EXEMPLO;

struct Atributos {
  float SL;
  float SW;
  float PL;
  float PW;
  char* Classe;
};

typedef struct DistanciaEuclidiana DIST;

struct DistanciaEuclidiana {
  float d;
  char* Classe;
};

void FREE_CLASSE(EXEMPLO a[MAX], int n) {
  for (int i = 0; i < n; i++) {
    free(a[i].Classe);
  }
}

int FILE_CHECK(FILE* p, char* fname) {
  if (p == NULL) {
    fprintf(stderr, "NULL fopen return: such file do not exist/allocation error\n");
    fprintf(stdout, "Trying to open: ");
    fputs(fname, stdout);
    exit(EXIT_FAILURE);
  }
  return 1;
}

void INSERTION_SORT(DIST v[MAX], int tam) {
  float aux;
  int i, j;
  for (i = 1; i < tam; i++) {
    aux = v[i].d;
    for (j = i - 1; (j >= 0) && (aux < v[j].d); j--) {
      v[j + 1].d = v[j].d;
    }
    v[j + 1].d = aux;
  }
}

void EXEMPLO_ATRIBUIR(FILE* csv, EXEMPLO ex[MAX]) {
  static char TiraVirgula;
  static int n = 0;
  float atr;

  ex[n].SL = fscanf(csv, "%3f", &atr);
  TiraVirgula = fgetc(csv);

  ex[n].SW = fscanf(csv, "%3f", &atr);
  TiraVirgula = fgetc(csv);

  ex[n].PL = fscanf(csv, "%3f", &atr);
  TiraVirgula = fgetc(csv);

  ex[n].PW = fscanf(csv, "%3f", &atr);
  TiraVirgula = fgetc(csv);

  fscanf(csv, "\"%m[^\"]\"", &ex[n].Classe);

  size_t str = strlen(ex[n].Classe);
  for (int i = 0; i < (str - 1); i++) {
    ex[n].Classe[i] = ex[n].Classe[i + 1];
  }
  ex[n].Classe[str - 1] = '\0';

  n++;
  TiraVirgula++;
}

int main() {
  int k;
  char* ArquivoNomeA;
  char* ArquivoNomeB;
  FILE* fp1;
  FILE* fp2;

  scanf("%m[^ ] %m[^ ] %d", &ArquivoNomeA, &ArquivoNomeB, &k);

  fp1 = fopen(ArquivoNomeA, "r");
  FILE_CHECK(fp1, ArquivoNomeA);
  fp2 = fopen(ArquivoNomeB, "r");
  FILE_CHECK(fp2, ArquivoNomeB);

  char PrimeiraLinha = 'q';
  EXEMPLO VetorTest[MAX];
  EXEMPLO VetorEx[MAX];
  int numex = 0, numtest = 0;

  while (PrimeiraLinha != '\n') {
    PrimeiraLinha = fgetc(fp1);
  }

  do {
    EXEMPLO_ATRIBUIR(fp1, VetorEx);
    numex++;
  } while (feof(fp1));
  fclose(fp1);

  if (k < 1 || k > numex) {
    fprintf(stdout, "k is invalid\n");
    fcloseall();
    return 0;
  }

  PrimeiraLinha = 'q';
  while (PrimeiraLinha != '\n') {
    PrimeiraLinha = fgetc(fp2);
  }

  do {
    EXEMPLO_ATRIBUIR(fp2, VetorTest);
    numtest++;
  } while (feof(fp2));
  fclose(fp2);

  int distancia, versicolors, virginicas, setosas, acertos;
  DIST VetorDist[MAX];
  char ClasseOriginal[10];

  for (int i = 0; i < numex; i++) {
    for (int j = 0; j < numtest; j++) {
      distancia = pow((VetorEx[j].SL - VetorTest[i].SL), 2) +
                  pow((VetorEx[j].SW - VetorTest[i].SW), 2) +
                  pow((VetorEx[j].PL - VetorTest[i].PL), 2) +
                  pow((VetorEx[j].PW - VetorTest[i].PW), 2);
      VetorDist[j].d = distancia;
      strcpy(VetorDist[j].Classe, VetorEx[j].Classe);
    }

    INSERTION_SORT(VetorDist, numex);

    versicolors = 0;
    virginicas = 0;
    setosas = 0;

    for (int w = 0; w < k; w++) {
      if (strcmp(VetorDist[i].Classe, "versicolor")) {
        versicolors += 1;
      } else if (strcmp(VetorDist[i].Classe, "virginica")) {
        virginicas += 1;
      } else if (strcmp(VetorDist[i].Classe, "setosa")) {
        setosas += 1;
      }
    }

    strcpy(ClasseOriginal, VetorTest[i].Classe);

    if ((versicolors > virginicas) && (versicolors > setosas)) {
      fprintf(stdout, "versicolor ");
      fputs(ClasseOriginal, stdout);
      if (strcmp(ClasseOriginal, "versicolor")) acertos++;
    } else if ((virginicas > versicolors) && (virginicas > setosas)) {
      fprintf(stdout, "virginica ");
      fputs(ClasseOriginal, stdout);
      if (strcmp(ClasseOriginal, "virginica")) acertos++;
    } else {
      fprintf(stdout, "setosa ");
      fputs(ClasseOriginal, stdout);
      if (strcmp(ClasseOriginal, "setosa")) acertos++;
    }
    versicolors = 0;
    virginicas = 0;
    setosas = 0;
  }

  fprintf(stdout, "%.04f\n", ((float)acertos / (float)numex));

  fcloseall();
  free(ArquivoNomeA);
  free(ArquivoNomeB);
  FREE_CLASSE(VetorEx, numex);
  FREE_CLASSE(VetorTest, numtest);

  return EXIT_SUCCESS;
}
