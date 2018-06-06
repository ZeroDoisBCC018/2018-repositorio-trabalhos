#include <stdio.h>
#include <stdlib.h>
int length(char *str) {
  int count = 0;
  while (str[count] != '\n') {
    count++;
  }
  return count;
}
void read_recursiva(char *str, int i) {
  str = (char *)realloc(str, (i + 1) * sizeof(char));
  str[i] = getchar();

  if (str[i] == '\n' || str[i] == '\0') {
    str[i] = '\0';
    return;
  }
  read_recursiva(str, i + 1);
  return;
}
char *read_line() {
  char *str = NULL;
  read_recursiva(str, 0);
  return str;
}
int equal(char *a, char *b) {
  int x, y;
  x = length(a);
  y = length(b);
  if (x != y) return 0;
  for (int i = 0; i < x; i++) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}
int main(int argc, char const *args[]) {
  char *str1;
  str1 = read_line();
  char *str2;
  str2 = read_line();

  int r = equal(str1, str2);
  if (r == 1) {
    printf("Linhas 1 e 2: %s", str1);
  } else {
    printf("Linha 1: %s\n", str1);
    printf("Linha 2: %s\n", str2);
  }
  free(str1);
  free(str2);
  return 0;
}
