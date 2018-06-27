#include <stdio.h>
#include <stdlib.h>
long long potencia(long long x, int p) {
  unsigned long long int m;
  if (p == 0) return 1;
  if ((p % 2) == 0) {
    m = potencia(x, p / 2);
    return m * m;
  } else
    return x * potencia(x, p - 1);
}
long long soma(long long* v, int n, long long s) {
  if (n == 0) return s;
  s += v[n - 1];
  n--;
  return soma(v, n, s);
}
int main() {
  int n, p;
  long long* vet;
  long long sum;
  scanf("%d %d", &n, &p);
  vet = (long long*)malloc(n * sizeof(long long));
  for (int i = 0; i < n; i++) {
    scanf("%lli", &vet[i]);
  }
  long long int s = 0;
  sum = soma(vet, n, s);
  printf("Soma: %lli\n", sum);
  long long pot = 0;
  printf("Potencias:");
  for (int i = 0; i < n; i++) {
    pot = potencia(vet[i], p);
    printf(" %lli", pot);
  }
  return 0;
}
