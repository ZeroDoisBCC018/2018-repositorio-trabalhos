#define ERROR -404
#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "googlebot_ds.h"
#include "googlebot_lists.h"
typedef int boolean;
typedef FILE* CSV;

boolean GB_CodeCheck (int code, SITE* array){
	//vamos comparar o 'code' com todos os anteriores do vetor antes de inseri-lo neste
	//precisaremos de um contador de quantas structs ja foram armazenadas
}


CSV GB_OpenCSV (CSV fp, char* filename){
	if(filename == NULL){
		perror(".csv filename not given.\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r+");
	if(fp == NULL){
		perror(".csv file could not be opened. Not enough memory/fatal error ocurred while trying to access the disk.\n");
		exit(EXIT_FAILURE);
	}
	return fp;
}

void GB_ReadCSV (CSV fp, SITE* s){
	int i = 0, j = 0, k = 0;
	char dump = ' '; // dump is initialized as blank space so it certainly enters the reading loop on line x
	if(fp == NULL){
		perror("File not opened.\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_SET);
	do{
		fscanf(fp, "%d", &s->code);
		if (!GB_CodeCheck(s->code, )) return NULL;
		fscanf(fp, ",%m[^,],%d,%m[^,],", o->name, &o->relev, o->link);
		while (dump != '\n'){
			dump = fgetc(fp);
			s->keyw[j][k] = dump;
			k++;
			if(dump == ','){
				 j++;
				 k = 0;
			}
		}
	}while(!feof(fp));
}

boolean GB_UpdateDataBase () { /* TODO */
}
