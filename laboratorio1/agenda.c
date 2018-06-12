#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

  char *nome;

  double altura;

  double peso;

  char genero;

  int id;

} agenda;

char *read_line() {

  char *vetc = (char *)malloc(1 * sizeof(char));

  scanf("%c", &vetc[0]);

  int i = 0;

  i++;

  while (vetc[i - 1] != '\n' && vetc[i - 1] != '\r') {

    vetc = (char *)realloc(vetc, (i + 1) * sizeof(char));

    scanf("%c", &vetc[i]);

    i++;

  }

  vetc[i - 1] = '\0';

  return vetc;

}

int main(int argc, char const *argv[]) {

  int numpes;

  int i, j;

  scanf("%d ", &numpes);

  agenda *cartao = (agenda *)malloc(sizeof(agenda) * numpes);

  for (i = 0; i < numpes; i++) {

    fflush(stdin);

    cartao[i].nome = read_line();

    scanf("%lf ", &cartao[i].altura);

    scanf("%lf ", &cartao[i].peso);

    cartao[i].genero = getchar();

    scanf("%d ", &cartao[i].id);

  }

  i = 0;

  int lista = 0;

  double imc;

  fflush(stdin);

  while (lista != -1) {

    scanf("%d", &lista);

    for (j = 0; j < numpes; j++) {

      if (lista == cartao[j].id) {

        puts(cartao[j].nome);

        if (cartao[j].genero == 'F') {

          imc = cartao[j].peso / ((cartao[j].altura) * (cartao[j].altura));

          printf("%lf\n", imc);

          if (imc < 19.1) {

            printf("Abaixo do peso\n");

          }

          if (imc >= 19.1 && imc < 25.8) {

            printf("Peso ideal\n");

          }

          if (imc >= 25.8 && imc < 27.3) {

            printf("Pouco acima do peso\n");

          }

          if (imc >= 27.3 && imc < 32.3) {

            printf("Acima do peso\n");

          }

          if (imc >= 32.4) {

            printf("Obesidade\n");

          }

        } else {

          imc = cartao[j].peso / ((cartao[j].altura) * (cartao[j].altura));

          printf("%lf\n", imc);

          if (imc < 20.7) {

            printf("Abaixo do peso\n");

          }

          if (imc >= 20.7 && imc < 26.4) {

            printf("Peso ideal\n");

          }

          if (imc >= 26.4 && imc < 27.8) {

            printf("Pouco acima do peso\n");

          }

          if (imc >= 27.8 && imc < 31.1) {

            printf("Acima do peso\n");

          }

          if (imc >= 31.1) {

            printf("Obesidade\n");

          }

        }

      }

      i++;

    }

  }

  return 0;

}
