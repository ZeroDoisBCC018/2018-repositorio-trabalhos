#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 200

typedef struct Atributos EXEMPLO;

struct Atributos{
	float SL;
	float SW;
	float PL;
	float PW;
	char* EspecieNome = NULL; 
};

void EXEMPLO_ATRIBUIR(FILE* p, EXEMPLO* ex){
	
	static char AspaVirgulaFim;
	static int n = 0;
	char atr[4];
	
	fgets(atr, 4, p);
	ex[n].SL = atof(atr);
	AspaVirgulaFim = fgetc(p);
		
	fgets(atr, 4, p);
	ex[n].SW = atof(atr);
	AspaVirgulaFim = fgetc(p);
		
	fgets(atr, 4, p);
	ex[n].PL = atof(atr);
	AspaVirgulaFim = fgetc(p);
		
	fgets(atr, 4, p);
	ex[n].PW = atof(atr);
	AspaVirgulaFim = fgetc(p);
	AspaVirgulaFim = fgetc(p);
	
	fscanf(p, "%[^\n]s", ex[n].EspecieNome);
	size_t str = strlen(ex[n].EspecieNome);
	ex[n].EspecieNome[str-1] = '\0';
	
	n++;
}

int main(){
	
	int k;
	char* ArquivoNomeA = NULL;
	char* ArquivoNomeB = NULL;
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	EXEMPLO* TabelaEx = malloc(sizeof(EXEMPLO) * MAX);
	int numln = 0;
	char PrimeiraLinha = 'q';
	
	fgets(ArquivoNomeA, 15, stdin);
	fgets(ArquivoNomeB, 15, stdin);
	fscanf(stdin, "%d", &k);
	
	fp1 = fopen(ArquivoNomeA, "r");
	if(fp1 == NULL){
		fprintf(stderr, "NULL fopen return: such file do not exist/allocation problem\n");
		return 0;
	}
	
	while(PrimeiraLinha != '\n'){
		PrimeiraLinha = fgetc(fp1);
	} 
	
	do{
		EXEMPLO_ATRIBUIR(fp1, TabelaEx);
		numln++;
	}while(feof(fp1));
	
	if(k < 1 || k > numln){
		fprintf(stdout, "k is invalid\n");
		return 0;
	}
			
		
