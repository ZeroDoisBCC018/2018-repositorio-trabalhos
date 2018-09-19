#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "googlebot_ds.h"

typedef FILE* CSV;
typedef SITE* OBJ;

CSV gb_openCSV (CSV fp, char* filename){
	
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

void* gb_readCSV (CSV fp, OBJ o){
	
	int i = 0, j = 0;
	char dump = ' '; // dump is initialized as blank space so it certainly enters the reading loop on line x
	
	if(fp == NULL){
		perror("File not opened.\n");
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0, SEEK_SET);
	
	do{
		fscanf(fp, "%d,%m[^,],%d,%m[^,],", &OBJ->code, OBJ->name, &OBJ->relev, OBJ->link);
		
		while (dump != '\n'){
			dump = fgetc(fp);
			OBJ->keyw[i][j] = dump;
			
			j++;
			if(dump == ','){
				 i++;
				 j = 0;
			}
		}
	}while(!feof(fp));
	
}
