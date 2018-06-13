#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char type;
	short int a1, a2, b1, b2, c1, c2, d1, d2;
}parameter;

int gaussian_scaling(){

}

int main(int argc, char const *argv[]){

	short int noequ  = scanf("%hd ", &noequ);
	unsigned short int nocoef = scanf("%hu ", &nocoef);
	short int i, j;

	parameter *vector_access = (parameter*)malloc(sizeof(parameter)*noequ);

	for(i=0; i<noequ; i++){	  //sera q tem um jeito melhor de fazer isso?
		vector_access[i].type = getchar();
		vector_access[i].a1 = scanf("%hd ", &vector_access[i].a1);
		vector_access[i].a2 = scanf("%hd ", &vector_access[i].a2);
		vector_access[i].b1 = scanf("%hd ", &vector_access[i].b1);
		vector_access[i].b2 = scanf("%hd ", &vector_access[i].b2);
		vector_access[i].c1 = scanf("%hd ", &vector_access[i].c1);
		vector_access[i].c2 = scanf("%hd ", &vector_access[i].c2);
		vector_access[i].d1 = scanf("%hd ", &vector_access[i].d1);
		vector_access[i].d2 = scanf("%hd ", &vector_access[i].d2);
	//vai rolar um if aqui
	}
}
