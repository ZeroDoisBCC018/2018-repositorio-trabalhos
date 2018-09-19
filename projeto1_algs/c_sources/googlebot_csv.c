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
	}
	
	fp = fopen(filename, "r+");
	
	if(fp == NULL){
		perror("Memmory allocation error/file can't be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	return fp;
}

void* gb_readCSV (CSV fp, OBJ o){
	
	char* str;
	if(fp == NULL){
		perror("File not opened.\n");
	}
	
	fseek(fp, 0, SEEK_SET);
	
	/* brunao */
	
	do{
		fscanf(fp, "%d,%m[^,],%d,%m[^,]", &OBJ->code, OBJ->name, &OBJ->relev, OBJ->link);
		//fscanf(fp, 
	}while(!feof(fp));
	
}
