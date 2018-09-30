#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void dump_one_byte(FILE* f){
	fscanf(f, " ");
}

char* read_line(FILE* fp){
	char* str;
	int i = 0;
	char c;
	fflush(fp);
	do{
		c = fgetc(fp);
		str[i] = c;
		i++;
	}while(c != '\n');
	str[i] = '\0';
	return str;
}
