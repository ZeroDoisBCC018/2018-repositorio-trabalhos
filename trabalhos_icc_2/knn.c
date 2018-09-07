#define _GNU_SOURCE 
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 200

typedef struct Atributos EXEMPLO;

struct Atributos{
	float SL;
	float SW;
	float PL;
	float PW;
	char* Classe; 
};

typedef struct DistanciaEuclidiana DIST;

struct DistanciaEuclidiana{
	float d;
	char* Classe;
};

int filecheck(FILE* p, char* fname){
	if(p == NULL){
		fprintf(stderr, "NULL fopen return: such file do not exist/allocation error\n");
		fprintf(stdout, "Trying to open: ");
		puts(fname);
		exit(EXIT_FAILURE);
	}
	return 1;
}

void INSERTIONSORT(DIST v[MAX], int tam){
	float aux;
	int i, j;
	for(i=1; i<tam; i++){
		aux = v[i].d;
		for(j=i-1; (j>=0)&&(aux<v[j].d); j--){
			v[j+1].d = v[j].d;
		}
		v[j+1].d = aux;
	}
}

void EXEMPLO_ATRIBUIR(FILE* csv, EXEMPLO* ex){
	
	static char TiraVirgula;
	static int n = 0;
	char atr[3];
	
	fgets(atr, 3, csv);
	ex[n].SL = atof(atr);
	TiraVirgula = fgetc(csv);
		
	fgets(atr, 3, csv);
	ex[n].SW = atof(atr);
	TiraVirgula = fgetc(csv);
		
	fgets(atr, 3, csv);
	ex[n].PL = atof(atr);
	TiraVirgula = fgetc(csv);
		
	fgets(atr, 3, csv);
	ex[n].PW = atof(atr);
	TiraVirgula = fgetc(csv);
	
	fscanf(csv, "%s[^\n]", ex[n].Classe); 
	size_t str = strlen(ex[n].Classe);
	for(int i=0; i<(str-2); i++){
		ex[n].Classe[i] = ex[n].Classe[i+1];
	}
	ex[n].Classe[str-1] = '\0'; 
	
	n++; 
}

int main(){
	
	int k;
	char* ArquivoNomeA;
	char* ArquivoNomeB;
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	
	EXEMPLO* VetorEx = (EXEMPLO*) malloc(sizeof(EXEMPLO) * MAX);
	EXEMPLO* VetorTest = (EXEMPLO*) malloc(sizeof(EXEMPLO) * MAX);
	if(VetorEx == NULL || VetorTest == NULL){
		perror("Memory allocation error\n");
		return EXIT_FAILURE;
	}
	
	int numex = 0, numtest = 0;
	char PrimeiraLinha = 'q';
	
	fgets(ArquivoNomeA, 15, stdin);
	fgets(ArquivoNomeB, 15, stdin);
	fscanf(stdin, "%d", &k);
	
	fp1 = fopen(ArquivoNomeA, "r");
	filecheck(fp1, ArquivoNomeA);
	
	while(PrimeiraLinha != '\n'){
		PrimeiraLinha = fgetc(fp1);
	} 
	
	do{
		EXEMPLO_ATRIBUIR(fp1, VetorEx);
		numex++;
	}while(!feof(fp1));
	fclose(fp1); 
	
	if(k < 1 || k > numex){
		fprintf(stdout, "k is invalid\n");
		fcloseall();
		free(VetorEx);
		free(VetorTest);
		return 0;
	}
	
	fp2 = fopen(ArquivoNomeB, "r");
	filecheck(fp2, ArquivoNomeB);
	
	PrimeiraLinha = 'q';
	while(PrimeiraLinha != '\n'){
		PrimeiraLinha = fgetc(fp2);
	}
	
	do{
		EXEMPLO_ATRIBUIR(fp2, VetorTest);
		numtest++;
	}while(!feof(fp2));
	fclose(fp2);
	
	int distancia, versicolors, virginicas, setosas, acertos;
	DIST VetorDist[MAX];
	char ClasseOriginal[10];
	
	for(int i=0; i<numex; i++){
		
		for(int j=0; j<numtest; j++){
			distancia = sqrt(pow(VetorEx[j].SL-VetorTest[i].SL, 2)+pow(VetorEx[j].SW-VetorTest[i].SW, 2)+pow(VetorEx[j].PL-VetorTest[i].PL, 2)+pow(VetorEx[j].PW-VetorTest[i].PW, 2));
			VetorDist[j].d = distancia;
			strcpy(VetorDist[j].Classe, VetorEx[j].Classe);
		}
		
		INSERTIONSORT(VetorDist, numex);
		
		versicolors = 0;
		virginicas = 0;
		setosas = 0;
		
		for(int w=0; w<k; w++){
			if(strcmp(VetorDist[j].Classe, "versicolor")){
				versicolors += 1;
			} else if(strcmp(VetorDist[j].Classe, "virginica")){
				virginicas += 1;
			} else if(strcmp(VetorDist[j].Classe, "setosa")){
				setosas += 1;
			}
		}
		
		ClasseOriginal = VetorTest[i].Classe;
		if((versicolors>virginicas) && (versicolors>setosas)){
			fprintf(stdout, "versicolor ");
			puts(ClasseOriginal);
			if(strcmp(ClasseOriginal, "versicolor")) acertos++;
		} else if((virginicas>versicolors) && (virginicas>setosas)){
			fprintf(stdout, "virginica ");
			puts(ClasseOriginal);
			if(strcmp(ClasseOriginal, "virginica")) acertos++;
		} else {
			fprintf(stdout, "setosa ");
			puts(ClasseOriginal);
			if(strcmp(ClasseOriginal, "setosa")) acertos++;
		}
	}
	
	fprintf(stdout, "%.04f\n", ((float)acertos/(float)numex));
	
	fcloseall();
	free(VetorEx);
	free(VetorTest);
	return EXIT_SUCCESS;
}
