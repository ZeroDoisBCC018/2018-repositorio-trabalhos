#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char type;
	short int a2, a3, b2, b3, c2, c3, d2, d3;
	short int a1 = (a2/a3);
	short int b1 = (b2/b3);
	short int c1 = (c2/c3);
	short int d1 = (d2/d3);
}parameter;

short int gaussian_scaling(){

}

int main(int argc, char const *argv[]){

	unsigned short int noequ  = scanf("%hu ", &noequ);
	unsigned short int nocoef = scanf("%hu ", &nocoef);
	unsigned short int i, j;

	parameter *vector_access = (parameter*)malloc(sizeof(parameter)*noequ);

	for(i=0; i<noequ; i++){	  //sera q tem um jeito melhor de fazer isso?
		vector_access[i].type = getchar();
		vector_access[i].a2 = scanf("%hd ", &vector_access[i].a2);
		vector_access[i].a3 = scanf("%hd ", &vector_access[i].a3);
		vector_access[i].b2 = scanf("%hd ", &vector_access[i].b2);
		vector_access[i].b3 = scanf("%hd ", &vector_access[i].b3);
		vector_access[i].c2 = scanf("%hd ", &vector_access[i].c2);
		vector_access[i].c3 = scanf("%hd ", &vector_access[i].c3);
		vector_access[i].d2 = scanf("%hd ", &vector_access[i].d2);
		vector_access[i].d3 = scanf("%hd ", &vector_access[i].d3);
	//vai rolar um if aqui
	}
}
