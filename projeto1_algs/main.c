#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "googlebot_ds.h"
#include "googlebot_lists.h"
#include "googlebot_csv.h"
#define CSV FILE*

void std_divide(void){
	fprintf(stdout, "=#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#=\n");
}

void print_first(void){
	fprintf(stdout, "Modify the database: you can change the properties of a given site directly.\n");
	fprintf(stdout, "Choose one of the following options:\n");
	fprintf(stdout, "\t1 - Insert a new site;\n\t2 - Remove a site from the database;\n\t3 - Update the relevance of a specific site;\n");
	fprintf(stdout, "\t4 - Insert a new keyword to  a site;\n\t5 - Print this menu section again;\n\t6 - Return to the main menu.\n");
	std_divide();
}

void first(void){
	std_divide();
	print_first();
}

void second(void){
}

void options(void){
	fprintf(stdout, "\t1 - Modify the database;\n\t2 - Update the database;\n\t3 - Print the menu options on the screen again;\n\t4 - Exit the Googlebot.\n");
	std_divide();
}

void welcome(void){
	fflush(stdin);
	fprintf(stdout, "Googlebot SCC0202-2018 Project. Developed by Joao Villaca, Bruno Gazoni and Bruno Baldissera.\n");
	fprintf(stdout, "ICMC/USP - Brazil, SP, Sao Carlos. This software is distributed as a free software under the\n");
	fprintf(stdout, "\"Unlicense\". Check the official Googlebot documentation or check<http://www.unlicense.org>\n");
	fprintf(stdout, "for more information.\n");
	std_divide();
	fprintf(stdout, "Welcome. This is Googlebot alpha version 1.0. Choose one of the following options:\n");
	options();	
}

void menu(void){
	
	static int op;
	
	do{
		fscanf(stdin, "%d", &op);
		switch(opcao){
			case 1: first(); break;
			case 2: second(); break;
			case 3: options();
			case 4: break;
			default:
				fprintf(stdout, "Unknown Code! Please insert one of the option codes above.\n");
				fflush(stdin);
				fscanf(stdin, "%d", &op);
		}
	}while(opcao != 3)		
}

void error_no_name(void){
	fprintf(stdout, "No filename given!\n");
	fprintf(stdout, "Instructions on how to use GBSiteRelevance:\n");
	fprintf(stdout, "On console command line, type: ");
	fprintf(stdout, "./GBSiteRelevance <csv_file>\n");
}

int main(int argc, const char* argv[]){
	
	fflush(stdout);
	fflush(stderr);
	
	if (argv[1] == NULL){ 
		error_no_name();
		exit(EXIT_FAILURE);
	} 
	
	CSV fp = GB_OpenCSV(fp, argv[1]);
	
	if (fp == NULL){
		fprintf(stdout, "Are you sure you typed the filename correctly?\n");
		perror("Memory allocation error/file can't be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	welcome();
	menu();
	
	return EXIT_SUCCESS;
}
