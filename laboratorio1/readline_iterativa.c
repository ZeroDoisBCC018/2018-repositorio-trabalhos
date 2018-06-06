#include <stdio.h>
#include <stdlib.h>
int length(char *str) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}
char *read_line() {
  char *string = NULL;
  char c = 'j';
  int count = 1;
  while (c != '\n') {
    string = (char *)realloc((string), count * sizeof(char));
    scanf("%c", &c);
    string[count - 1] = c;
    count++;
  }
  string[count - 2] = '\0';
  return string;
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
int main(void) {
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
