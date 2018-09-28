#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "googlebot_ds.h"
#include "googlebot_lists.h"
#include "googlebot_csv.h"
#define CSV FILE*

LIST* l;

void std_divide(void){
	fprintf(stdout, "=#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#==#=\n");
}

void print_first(void){
	fprintf(stdout, "Modify the database: you can change the properties of a given site directly.\n");
	fprintf(stdout, "Choose one of the following options:\n");
	fprintf(stdout, "\t1 - Insert a new site;\n\t2 - Remove a site from the database;\n\t3 - Update the relevance of a specific site;\n");
	fprintf(stdout, "\t4 - Insert a new keyword to a site;\n\t5 - Print this menu section again;\n\t6 - Return to the main menu.\n");
	std_divide();
}

void first(void){
	
	static int op = 101;
	std_divide();
	print_first();
	
	while(op != 6){
		fflush(stdin);
		fscanf(stdin, "%d");
		switch(op){
			case 1: new_site(); break;
			case 2: remove_site(); break;
			case 3: update_rel(); break;
			case 4: new_keyw(); break;
			case 5: print_first(); break;
			case 6: std_divide(); break;
			default:
				fprintf(stdout, "Unknown Code! Please insert one of the option codes above.\n");
		}
		if (op != 6) fprintf(stdout, "Insert code 5 to print this menu section again.\n");
	}
}

void second(void){
}

void menu_options(void){
	
	fprintf(stdout, "\t1 - Modify the database;\n\t2 - Update the database;\n\t3 - Print the menu options on the screen again;\n\t4 - Exit the Googlebot.\n");
	std_divide();
}

void welcome(void){
	fflush(stdin);
	fprintf(stdout, "Googlebot SCC0202-2018 Project. Developed by Joao Villaca, Bruno Gazoni and Bruno Baldissera.\n");
	fprintf(stdout, "ICMC/USP - Brazil, SP, Sao Carlos. This software is distributed as a free software under the\n");
	fprintf(stdout, "\"Unlicense\". Check the official Googlebot documentation or access <http://www.unlicense.org>\n");
	fprintf(stdout, "for more information.\n");
	std_divide();
	fprintf(stdout, "Welcome. This is Googlebot alpha version 1.0. Choose one of the following options:\n");
	menu();	
}

void menu(void){
	
	static int op = 101;
	menu_options();
	
	while(op != 4){
		fflush(stdin);
		fscanf(stdin, "%d", &op);
		switch(opcao){
			case 1: first(); break;
			case 2: second(); break;
			case 3: menu_options(); break;
			case 4: break; 
			default:
				fprintf(stdout, "Unknown Code! Please insert one of the option codes above.\n");
		}
		if (op != 4) fprintf(stdout, "Insert code 3 to print the menu options again.\n");
	}	
}

void error_no_name(void){
	fprintf(stdout, "No filename given!\n");
	fprintf(stdout, "Instructions on how to use GBSiteRelevance:\n");
	fprintf(stdout, "On console command line, type: ");
	fprintf(stdout, "./GBSiteRelevance <csv_file>\n");
	fprintf(stdout, "If the filename input is a nonexistent file\n");
	fprintf(stdout, "an empty new one with this name will be created.\n");
}

int main(int argc, const char* argv[]){
	
	if (argv[1] == NULL){ 
		error_no_name();
		perror("Input error: missing filename.\n");
		exit(EXIT_FAILURE);
	} 
	
	CSV fp = GB_OpenCSVread(fp, argv[1]);
	l = GB_NewList();
	GB_ReadCSV(fp, l);
	
	if (fp == NULL){
		fprintf(stdout, "Are you sure you typed the filename correctly?\n");
		perror("Memory allocation error/file can't be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	welcome();
	
	return EXIT_SUCCESS;
}
