#define ERROR -404
#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "googlebot_lists.h"

struct site_ {
	int code;
	const char* name;
	int relev;
	const char* link;
	const char keyw[10][50];
}

int GB_GetSiteStdin(LIST* l) {
	if (l == NULL) return ERROR;
	if (GB_CheckInvalidList(l)) return ERROR;
	NODE* n = GB_NewNode();
	int code = fscanf(stdin, "%d", &code);
	fflush(stdin);
	char* name = fgets(name, 50, stdin);
	fflush(stdin);
	int relev = fscanf(stdin, "%d", &relev);
	fflush(stdin);
	char* link = fgets(link, 100, stdin);
	fflush(stdin);
	int i, j;
	/* FOR LOOP */
}
