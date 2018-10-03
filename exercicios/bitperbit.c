#include "bitperbit.h"

void swap_ints(int a, int b){
	a = a + b;
	b = a - b;
	a = a - b; 
}

int int_module(int a){
	int p = pow(a, 2);
	a = sqrt(p);
	return a;
}

void force_terminator(char* str, int n){
	str[n] = '\0';
}

void fdump1(FILE* f){
	fgetc(f);
}

char* readline(FILE* fp){
	char* str;
	int i = 0;
	char c;
	fflush(fp);
	do{
		c = fgetc(fp);
		str[i] = c;
		i++;
	}while(c != '\n');
	str[i-1] = '\0';
	return str;
}
