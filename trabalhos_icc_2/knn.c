/* k-Nearest Neighbours
 * Este programa tenta classificar flores usando o algoritmo de 
 * aprendizado de maquina k-Nearest Neighbours.
 * Trabalho 2 de ICC-II - Prof. Moacir Ponti - Entrega dia 12/00/2018
 * Joao Vitor Nascimento Villaca - ICMC/USP - NoUSP: 10724239 */

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

/* Funcao que libera os ponteiros (strings) de classe
 * que estao na estrutura Atributos.
 * Parametros:
 * 	EXEMPLO a[MAX] - vetor com os Atributos de cada exemplo
 * 	int n - numero de exemplos
 * Retorno: void */
void FREE_CLASSE(EXEMPLO a[MAX], int n) {
  for (int i = 0; i < n; i++) {
    free(a[i].Classe);
  }
}

/* Funcao que checa se os arquivos foram abertos corretamente.
 * Feita exclusivamente com intencao de debugar o codigo.
 * Parametros:
 * 	FILE* p - ponteiro para o arquivo a ser verificado
 * 	char* fname - string com o nome do arquivo
 * Retorno: void */
void FILE_CHECK(FILE* p, char* fname) {
  if (p == NULL) {
    fprintf(stderr, "NULL fopen return: such file do not exist/allocation error\n");
    fprintf(stdout, "Trying to open: ");
    fputs(fname, stdout);
    exit(EXIT_FAILURE);
  }
}

/* Funcao que ordena as distancias dos exemplos dados.
 * Parametros:
 * 	DIST v[MAX] - vetor com as distancias euclidianas
 * 	int tam - tamanho do vetor (numero de exemplos)
 * Retorno: void */
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

/* Funcao que concede atributos aos exemplos baseado
 * no arquivo .csv que o programa recebe.
 * Parametros:
 * 	FILE* csv - ponteiro para o arquivo .csv com os atributos
 * 	EXEMPLO ex[MAX] - vetor com os exemplos que receberao atributos
 * Retorno: void */
void EXEMPLO_ATRIBUIR(FILE* csv, EXEMPLO ex[MAX]) {
  static char TiraVirgula;
  static int n = 0;
  char atr[4], cl[20];
  atr[3] = '\0';

  fgets(atr, 3, csv);
  ex[n].SL = atof(atr);
  TiraVirgula = fgetc(csv);

  fgets(atr, 3, csv);
  ex[n].SW = atof(atr);
  TiraVirgula = fgetc(csv);

  fgets(atr, 3, csv);
  ex[n].PL = atof(atr);
  TiraVirgula = fgetc(csv);

  fgets(atr, 3, csv);
  ex[n].PW = atof(atr);
  TiraVirgula = fgetc(csv);
  
  fgets(cl, 20, csv);
  strcpy(ex[n].Classe, cl);

  n++;
  TiraVirgula--;
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

  EXEMPLO VetorTest[MAX];
  EXEMPLO VetorEx[MAX];
  char PrimeiraLinha = 'q';
  int numex = 0, numtest = 0;

  while (PrimeiraLinha != '\n') {
    PrimeiraLinha = fgetc(fp1);
  }

  while (1) {
    EXEMPLO_ATRIBUIR(fp1, VetorEx);
    numex++;
    if (feof(fp1)) {
      break;
    }
  }
  fclose(fp1);

  //verificar se o k e invalido
  //i.e., negativo ou maior que o numero de exemplos
  if (k < 1 || k > numex) {
    fprintf(stdout, "k is invalid\n");
    fcloseall();
    return 0;
  }

  while (PrimeiraLinha != '\n') {
    PrimeiraLinha = fgetc(fp1);
  }

  while (1) {
    EXEMPLO_ATRIBUIR(fp1, VetorEx);
    numex++;
    if (feof(fp1)) {
      break;
    }
  }
  fclose(fp2);

  int distancia, versicolors, virginicas, setosas, acertos;
  DIST VetorDist[MAX];
  char ClasseOriginal[15];

  /* Calculo das distancias euclidianas, seguido do armazenamento
   * da classe original do arquivo de teste*/
  for (int i = 0; i < numex; i++) {
    for (int j = 0; j < numtest; j++) {
      distancia = pow((VetorEx[j].SL - VetorTest[i].SL), 2) +
                  pow((VetorEx[j].SW - VetorTest[i].SW), 2) +
                  pow((VetorEx[j].PL - VetorTest[i].PL), 2) +
                  pow((VetorEx[j].PW - VetorTest[i].PW), 2);
      VetorDist[j].d = distancia;
      strcpy(VetorDist[j].Classe, VetorEx[j].Classe);
    }

    //ordenacao das distancias euclidianas
    INSERTION_SORT(VetorDist, numex);

    versicolors = 0;
    virginicas = 0;
    setosas = 0;

    /*contagem do numero de flores para fazer o calculo do acerto
     *no fim do programa */
    for (int w = 0; w < k; w++) {
      if (strcmp(VetorDist[i].Classe, "\"versicolor\"")) {
        versicolors += 1;
        strcpy(ClasseOriginal, "versicolor");
      } else if (strcmp(VetorDist[i].Classe, "\"virginica\"")) {
        virginicas += 1;
        strcpy(ClasseOriginal, "virginica");
      } else if (strcmp(VetorDist[i].Classe, "\"setosa\"")) {
        setosas += 1;
        strcpy(ClasseOriginal, "setosa");
      }
    }
    
    /* comparacao entre o numero de flores por classe
     * e saida do resultado da estimativa k-NN */
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
    
    /* variaveis zeradas para nao afetar o for() da contagem
     * do numero de flores */
    versicolors = 0;
    virginicas = 0;
    setosas = 0;
  }

  fprintf(stdout, "%.04f\n", ((float)acertos / (float)numex));

  fcloseall();
  free(fp1);
  free(fp2);
  free(ArquivoNomeA);
  free(ArquivoNomeB);
  FREE_CLASSE(VetorEx, numex);
  FREE_CLASSE(VetorTest, numtest);

  return EXIT_SUCCESS;
}
