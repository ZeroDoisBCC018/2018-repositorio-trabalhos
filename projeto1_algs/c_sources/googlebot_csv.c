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
#define boolean int;
#define CSV FILE*;

int GB_CodeCheck (int code, LIST* l){
	if (GB_CheckInvalidList(l)) return ERROR;
	if (GB_CheckEmptyList(l)) return ERROR;
	NODE* aux = array->first;
	while (aux != NULL){
		if (aux->site->code == code) return ERROR;
		aux = aux->next;
	}
	return SUCCESS;
}


CSV GB_OpenCSVread (CSV fp, char* filename){
	if(filename == NULL){
		perror(".csv filename not given.\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if(fp == NULL){
		perror(".csv file could not be opened. Not enough memory/fatal error ocurred while trying to access the disk.\n");
		exit(EXIT_FAILURE);
	}
	return fp;
}

CSV GB_OpenCSVwrite (CSV fp, char* filename){
	if(filename == NULL){
		perror(".csv filename not given.\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "w");
	if(fp == NULL){
		perror(".csv file could not be opened. Not enough memory/fatal error ocurred while trying to access the disk.\n");
		exit(EXIT_FAILURE);
	}
	return fp;
}

void GB_CloseCSV (CSV fp){
	if(fp == NULL){
		perror("no .csv file oṕened.");
		exit(EXIT_FAILURE);
	}
	
	fclose(fp);
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
