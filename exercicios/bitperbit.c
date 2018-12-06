#include "bitperbit.h"

/*
1 - int elementsof(array, type of array)
2 - char* typeof(generic var)
3 - int stringhash(char* str)
4 - long long unsigned int checksum(str1, str2)
5 - double decimalpart(double)
6 - int integerpart(double)
7 - int spinbits(int, const char left-right)
*/

void swap_ints(int * a, int * b) {
        * a = * a + * b;
        * b = * a - * b;
        * a = * a - * b;
}

int int_module(int n) {
        if (n == 0) return 0;
        else if (n > 0) return n;
        else return (n * (-1));
}

void fdump1(FILE * stream) {
        fgetc(stream);
}

void fdumpline(FILE * stream) {
        char c = 'a';
        do {
                c = fgetc(stream);
        } while (c != '\n');
}

char * readline(FILE * stream) {
        char * line;
        int i = 0;
        char c;
        fflush(stream);
        do {
                c = fgetc(stream);
                line[i] = c;
                i++;
        } while (c != '\n');
        line[i - 1] = '\0';
        return line;
}

int higher(int a, int b) {
        if (a > b) return a;
        if (b > a) return b;
        else return 0;
}

int lower(int a, int b) {
        if (a < b) return a;
        if (b < a) return b;
        else return 0;
}

int lcm(int a, int b) {
        int c, d, r;
        c = a;
        d = b;
        do {
                r = c % d;
                c = d;
                d = r;
        } while (r != 0);
        return ((a * b) / c);
}

int gcd(int a, int b) {
        int r = a % b;
        while (r != 0) {
                a = b;
                b = r;
                r = a % b;
        }
        return b;
}

unsigned int factorial(int n) {
        int i;
        unsigned int fac = 1;
        for (i = 0; i < n; i++) {
                fac *= i;
        }
        return fac;
}

unsigned int fibonacci(int n) {
        int i;
        unsigned int f1 = 0;
        unsigned int f2 = 1;
        unsigned int fi;
        if (n == 0) return 0;
        if (n == 1) return 1;

        for (i = 1; i < n; i++) {
                fi = f1 + f2;
                f1 = f2;
                f2 = fi;
        }
        return fi;
}

int cleanfile(FILE * fp,
        const char * mode) {
        if (f == NULL) return;
        fflush(fp);
        fclose(fp);
        fopen(fp, "w");
        fclose(fp);
        fopen(fp, mode);
        fseek(fp, 0, SEEK_SET);
        if (fp == NULL) return 0;
        else return 1;
}

int int_arit_ref(const char op, int * n, int a) {
        switch (op) {
        case '+':
                * n += a;
                return *n;
        case '-':
                * n -= a;
                return *n;
        case '*':
                * n *= a;
                return *n;
        case '/':
                * n /= a;
                return *n;
        default:
                return *n;
        }
        return 0;
}

int power_ref(int * n, int e) {
        int i;
        int aux = * n;
        for (i = 0; i < e; i++) {
                * n *= aux;
        }
        return *n;
}

double totalclock(clock_t start_t, clock_t end_t) {
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        return total_t;
}

void merge(int v[], int s, int m, int e) {
        int s1 = s, s2 = m + 1, saux = 0, size = e - s + 1;
        int * vaux;
        vaux = (int * ) malloc(size * sizeof(int));

        while (s1 <= m && s2 <= e) {
                if (v[s1] < v[s2]) {
                        vaux[saux] = v[s1];
                        s1++;
                } else {
                        vaux[saux] = v[s2];
                        s2++;
                }
                saux++;
        }

        while (s1 <= m) {
                vaux[saux] = v[s1];
                saux++;
                s1++;
        }

        while (s2 <= e) {
                vaux[saux] = v[s2];
                saux++;
                s2++;
        }

        for (saux = s; saux <= e; saux++) {
                v[saux] = vaux[saux - s];
        }

        free(vaux);
}

void mergeSort(int vector[], int start, int end) {
        if (start < end) {
                int middle = (end + start) / 2;

                mergeSort(vector, start, middle);
                mergeSort(vector, middle + 1, end);
                merge(vector, start, middle, end);
        }
}

void heapsort(int a[], int n) {
        int i = n / 2, dad, son, t;
       
        while (true) {
                if (i > 0) {
                        i--;
                        t = a[i];
                } else {
                        n--;
                        if (n == 0) return;
                        t = a[n];
                        a[n] = a[0];
                }
               
                dad = i;
                son = i * 2 + 1;
               
                while (son < n) {
                        if ((son + 1 < n) && (a[son + 1] > a[son]))
                                son++;
                        if (a[son] > t) {
                                a[dad] = a[son];
                                dad = son;
                                son = dad * 2 + 1;
                        } else {
                                break;
                        }
                }
                a[dad] = t;
        }
}
