#include "bitperbit.h"

void swap_ints(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b; 
}

unsigned int int_module(int n){
	if(n == 0) return 0;
	else if(n > 0) return ((unsigned int) n);
	else return((unsigned int) n*(-1));
}

void force_terminator(char* str){
	int n = (int) strlen(str);
	str[n-1] = '\0';
}

void fdump1(FILE* stream){
	fgetc(stream);
}

void fdumpline(FILE* stream){
	char c = 'a';
	do{
		c = fgetc(stream);
	}while(c != '\n');
}

char* readline(FILE* stream){
	char* line;
	int i = 0;
	char c;
	fflush(stream);
	do{
		c = fgetc(stream);
		line[i] = c;
		i++;
	}while(c != '\n');
	line[i-1] = '\0';
	return line;
}

int higher(int a, int b){
	if(a > b) return a;
	if(b > a) return b;
	else return 0;
}

int lower(int a, int b){
	if(a < b) return a;
	if(b < a) return b;
	else return 0;
}

int lcm(int a, int b){
	int c, d, r;	
	c = a;	
	d = b;
	do{
        	r = c % d;
		c = d;	
		d = r;
	}while(r != 0);
    return ((a*b)/c);
}

int gcd(int a, int b){
	int r = a % b;
	while(r != 0){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

unsigned int factorial(int n){
	int i;
	unsigned int fac = 1;
	for(i = 0; i < n; i++){
		fac *= i;
	}
	return fac;
}

unsigned int fibonacci(int n){
	int i;
	unsigned int f1 = 0;
	unsigned int f2 = 1;
	unsigned int fi;
	if(n == 0) return 0;
	if(n == 1) return 1;

	for(i = 1 ; i < n ; i++){
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
	}
	return fi;
}

int cleanfile(FILE* fp, const char* mode){
	if(f == NULL) return;
	fflush(fp);
	fclose(fp);
	fopen(fp, "w");
	fclose(fp);
	fopen(fp, mode);
	fseek(fp, 0, SEEK_SET);
	if(fp == NULL) return 0;
	else return 1;
}

int int_arit_ref(const char op, int* n, int a){
	switch(op){
		case '+': *n += a; return *n;
		case '-': *n -= a; return *n;
		case '*': *n *= a; return *n;
		case '/': *n /= a; return *n;
		default: return *n;
	}
	return 0;
}
