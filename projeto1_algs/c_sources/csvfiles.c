#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef FILE* CSV;

CSV openCSV (CSV fp, char* filename){
	
	if(filename == NULL){
		fprintf(stdout, "No filename given!\n");
		fprintf(stdout, "Instructions on how to use SiteRelevance:\n");
		fprintf(stdout, "On console command line, type: ");
		frpintf(stdout, "./SiteRelevance <csv_file>\n");
	}
	
	fp = fopen(filename, "r");
	
	if(fp == NULL){
		perror("Memmory allocation error/file can't be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	return fp;
}

void* readCSV (CSV fp){
	
	const char v[2] = ",";
	char* str, tok;
	
	fseek(fp, 0, SEEK_SET);
	
	do{
		fscanf(fp, "", str);
	}while(feof(fp));
	
	tok = strtok(str, v);
}
