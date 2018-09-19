#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "googlebot_ds.h"
#define TRUE 1
#define FALSE 0

typedef FILE* CSV;
typedef SITE* OBJ;

CSV gb_OpenCSV (CSV fp, char* filename){
	
	if(filename == NULL){
		fprintf(stdout, "No filename given!\n");
		fprintf(stdout, "Instructions on how to use GBSiteRelevance:\n");
		fprintf(stdout, "On console command line, type: ");
		fprintf(stdout, "./GBSiteRelevance <csv_file>\n");
		exit(EXIT_FAILURE);
	}
	
	fp = fopen(filename, "r+");
	
	if(fp == NULL){
		perror("Memory allocation error/file can't be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	return fp;
}

void* gb_ReadCSV (CSV fp, OBJ o){
	//falta criar o vetor de sites
	int i = 0, j = 0, k = 0;
	char dump = ' '; // dump is initialized as blank space so it certainly enters the reading loop on line x
	
	if(fp == NULL){
		perror("File not opened.\n");
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0, SEEK_SET);
	
	do{
		fscanf(fp, "%d,%m[^,],%d,%m[^,],", &o->code, o->name, &o->relev, o->link);
		//quebrar em 2 linhas isolando o 'code', chamando a função gb_CodeCheck
		
		while (dump != '\n'){
			dump = fgetc(fp);
			o->keyw[j][k] = dump;
			
			k++;
			if(dump == ','){
				 j++;
				 k = 0;
			}
		}
	}while(!feof(fp));
	
}

int gb_CodeCheck (int code, OBJ array){
	//vamos comparar o 'code' com todos os anteriores do vetor antes de inseri-lo neste
	//precisaremos de um contador de quantas structs ja foram armazenadas
}
