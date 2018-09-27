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
	const char keyw[500];
}

NODE* GB_GetSiteStdin(void) {
	if (l == NULL) return ERROR;
	if (GB_CheckInvalidList(l)) return ERROR;
	NODE* new = GB_NewNode(void);
	
	int code = fscanf(stdin, "%d", &code);
	new->code = code;
	fflush(stdin);
	
	char* name = fgets(name, 50, stdin);
	new->name = name;
	fflush(stdin);
	
	int relev = fscanf(stdin, "%d", &relev);
	new->relev = relev;
	fflush(stdin);
	
	char* link = fgets(link, 100, stdin);
	new->link = link;
	fflush(stdin);
	return new;
}

int GB_InsertSite(LIST* l, int pos){
	if (GB_CheckInvalidList(l)) return ERROR; 
	NODE* new = GB_GetSiteStdin(void);
	InsertNodeAtPos(l, new, pos);
	return SUCCESS;
}
