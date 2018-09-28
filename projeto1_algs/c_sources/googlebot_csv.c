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
	NODE* aux = array->first; /*nao eh mais array*/
	while (aux != NULL){
		if (aux->site->code == code) return ERROR; /* esse trecho ficou otimo mas coloca else so por garantia*/
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
	fp = fopen(filename, "r+"); /* aqui tem que ser "r+" pq "w" sempre cria uma empty file */
	if(fp == NULL){
		perror(".csv file could not be opened. Not enough memory/fatal error ocurred while trying to access the disk.\n");
		exit(EXIT_FAILURE);
	}
	return fp;
}

void GB_CloseCSV (CSV fp){
	if(fp == NULL){
		perror("no .csv file oṕened."); /*nao precisa quitar do programa, so da return na funcao*/
		exit(EXIT_FAILURE);
	}
	
	fclose(fp);
}



void GB_ReadCSV (CSV fp, SITE* s){ //pq ta recebendo site como parametro? nao deveria ser lista?
	/*detalhe: lembrar de ignorar a primeira linha que contem a classificacao dos objetos do csv */
	/*criar duas opcoes: uma para csv com header(primeira linha inutil) e outra sem, sugestao: receber boolean mode*/
	/*lembrar de checar se tem lista criada, vazia ou com tamanho invalido*/
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

boolean/*int*/ GB_UpdateDataBase (CSV fp, char* filename, LIST* l) { //o retorno deve ser int para retornar sucesso ou erro
	int i = 0;
	NODE* aux;
	aux = l->first;
	char c;
	
	if(fp == NULL){
		perror("File not opened.\n");
		exit(EXIT_FAILURE);
	}
	
	fflush(fp);
	
	GB_CloseCSV(fp);
	GB_OpenCSVwrite(fp, filename);
	
	while (aux->next != l->last)
	{
		fprintf(fp, "%d,%s,%s,", aux->site->code, aux->site->name, aux->site->link);
		
		do{
			fprintf("%c"), aux->site->keyw[i];
			i++;
		}while (c != '\n');
		
		aux = aux->next;
	}
	
	GB_CloseCSV(fp);
}
