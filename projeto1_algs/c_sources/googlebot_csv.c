
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "googlebot_ds.h"
#define TRUE 1
#define FALSE 0

typedef FILE* CSV;
typedef SITE* OBJ;


int gb_CodeCheck (int code, OBJ array){
	//vamos comparar o 'code' com todos os anteriores do vetor antes de inseri-lo neste
	//precisaremos de um contador de quantas structs ja foram armazenadas
}


CSV gb_OpenCSV (CSV fp, char* filename){
	
	if(filename == NULL){
		
		exit(EXIT_FAILURE);
	}
	
	fp = fopen(filename, "r+");
	
	if(fp == NULL){
		
		exit(EXIT_FAILURE);
	}
	
	return fp;
}

void* gb_ReadCSV (CSV fp, OBJ o){
	
	int i = 0, j = 0, k = 0;
	char dump = ' '; // dump is initialized as blank space so it certainly enters the reading loop on line x
	
	if(fp == NULL){
		//perror("File not opened.\n");
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0, SEEK_SET);
	
	do{
		fscanf(fp, "%d", &o->code);
		
		if (!gb_CodeCheck) return NULL;
		
		fscanf(fp, ",%m[^,],%d,%m[^,],", o->name, &o->relev, o->link);
		
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
