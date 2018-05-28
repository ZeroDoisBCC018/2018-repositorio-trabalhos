// Sistema de Recomendacao:
// Este programa tenta predizer a nota que um usuario atribuiria a um filme
// atraves
// da similaridade entre suas notas e as de outros usuarios da mesma plataforma.
// Trabalho 2 de ICC 1 - Prof. Moacir Ponti - Entrega dia 30/04/2018
// Joao Vitor Nascimento Villaca - ICMC/USP - NoUSP: 10724239

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(void) {
  // Entradas incializadas como "0", para posicao inicial no vetor/matriz:
  int usuario;
  int nota;
  double limiar;

  usuario = 0;
  nota = 0;
  limiar = 0.0;

  // Entrada dos parametros matriciais:
  scanf("%d %d %lf", &usuario, &nota, &limiar);

  // Especificacao do vetor e das matrizes em si.
  // Matriz com as notas:
  int mat_nota[usuario][nota];

  // Matriz de similaridade:
  double mat_similaridade[usuario][usuario];

  // Vetor com as medias:
  double vet_medias[usuario];

  // Algoritmo que interpreta as notas.
  // Ordem: 1-linhas(usuario), 2-colunas(nota):
  for (int m = 0; m < usuario; m++) {  // 1
    for (int n = 0; n < nota; n++) {   // 2
      mat_nota[m][n] = 0;
      scanf("%d", &mat_nota[m][n]);
    }
  }

  // Algoritmo para determinar a similaridade.
  // Variaveis para determinar a similaridade:
  int numerador;
  int notasdadas;
  double norma01;
  double norma02;
  double media;

  numerador = 0;
  notasdadas = 0;
  norma01 = 0;
  norma02 = 0;
  media = 0;

  // Selecao da linha da matriz de similaridade:
  for (int m = 0; m < usuario; m++) {
    // Com qual linha a nota vai ser comparada:
    for (int n = 0; n < usuario; n++) {
      // Para mudar a coluna apos a comparacao:
      // A letra "o" representa elementos das matrizes que queremos comparar:
      for (int o = 0; o < nota; o++) {
        numerador += ((mat_nota[m][o]) * (mat_nota[n][o]));
        norma01 += pow((mat_nota[m][o]), 2);
        norma02 += pow((mat_nota[n][o]), 2);
        media += (mat_nota[m][o]);

        // Para excluir as notas nao dadas
        // e evitar divisao por zero:
        if ((mat_nota[m][o]) != 0) notasdadas++;
      }

      // Montagem do vetor com as medias:
      vet_medias[m] = (media / notasdadas);

      // Montagem da matriz de similaridade:
      mat_similaridade[m][n] = numerador / ((sqrt(norma01)) * (sqrt(norma02)));

      // Posicao na matriz quando os numeros sao
      // completamente iguais:
      if (mat_similaridade[m][n] == 1.0) mat_similaridade[m][n] = 0;

      // Zerando novamente as matrizes/vetor:
      numerador = 0;
      notasdadas = 0;
      norma01 = 0;
      norma02 = 0;
      media = 0;
    }
  }

  // Algoritmo para predizer a nota.
  // Declaracao das variaveis:
  double nota_usuario = 0.0;
  double divisor = 0.0;
  bool quebra_de_linha = false;

  // Estimativa das notas atraves da matriz da notas
  // e da matriz de similaridade:

  for (int m = 0; m < usuario; m++) {  // Selecao da linha
    for (int n = 0; n < nota; n++) {   // Linha com qual sera comparada
      if (mat_nota[m][n] == 0) {
        // Na forma a seguir usamos "o" para comparar tanto as colunas da matriz
        // de similaridade
        // quanto as linhas (usuarios) na matriz das notas e sua media no vetor
        // das medias:
        for (int o = 0; o < usuario; o++) {
          // Uso do limiar para executar a comparacao e estimar a nota:
          if (mat_similaridade[m][o] > limiar) {
            if (mat_nota[o][n] != 0) {
              nota_usuario += (mat_similaridade[m][o]) *
                              ((mat_nota[o][n]) - (vet_medias[o]));
              divisor += mat_similaridade[m][o];
              quebra_de_linha = true;
            }
          }
        }

        // Para, novamente, evitar divisao por zero, excluimos os filmes que
        // ainda nao receberam notas do algoritmo que tenta predizer essas
        // notas:
        if ((divisor > 0 || nota_usuario > 0) &&
            (nota_usuario <= 5 && divisor <= 5)) {
          printf("%.2lf ", vet_medias[m] + (nota_usuario / divisor));
        }

        //"Dados Insuficientes"
        else {
          printf("DI ");
          quebra_de_linha = true;
        }
      }

      // Para evitar bugs, as variaveis sao zeradas novamente:
      else {
        if (nota_usuario != divisor) {
          nota_usuario = 0.0;
          divisor = 0.0;
        }
      }
    }

    //"Ativacao" das quebras de linha:
    if (quebra_de_linha == true) {
      printf("\n");
      quebra_de_linha = false;
    }
  }
  return 0;
}
