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

NODE* GB_GetSiteStdin(void) {
	if (l == NULL) return ERROR;
	if (GB_CheckInvalidList(l)) return ERROR;
	NODE* new = GB_NewNode(void);		  /*a new node is created*/
	
	int code = fscanf(stdin, "%d", &code);	  /*we read from stdin the code and allocate it in the new node's site position*/	
	new->code = code;
	fflush(stdin);
	
	char* name = fgets(name, 50, stdin);	  /*we read from stdin the name and allocate it in the new node's site position*/
	new->name = name;
	fflush(stdin);
	
	int relev = fscanf(stdin, "%d", &relev);  /*we read from stdin the relevance and allocate it in the new node's site position*/
	new->relev = relev;
	fflush(stdin);
	
	char* link = fgets(link, 100, stdin);     /*we read from stdin the link and allocate it in the new node's site position*/
	new->link = link;
	fflush(stdin);
	
	char dump = ' ';
	int i = 0, j = 0;
	while (dump != '\n'){
		dump = getchar();
		new->keyw[j][k] = dump;
		k++;
		if(dump == ','){
			j++;
			k = 0;
		}
	}
	return new;
}

int GB_InsertSite(LIST* l, int pos){	          
	if (GB_CheckInvalidList(l)) return ERROR; 
	NODE* new = GB_GetSiteStdin(void);        /*the function that updates all the site's infos is called to the new node*/
	InsertNodeAtPos(l, new, pos);	          /*then we insert the new node at the given position 'pos'*/
	return SUCCESS;
}

int GB_RemoveSite(LIST* l, int code){
	if (GB_CheckInvalidList(l)) return ERROR; 
	if (GB_CheckEmptyList(l)) return ERROR;
	NODE* aux1 = l->first; 
	NODE* aux2 = aux1->next;	
	if (aux1->code == code){ 		  /*checks if the first node is to be erased, which will have 2 different cases*/
		int size = GB_CountListSize(l);
		if (size == 1) free(aux1);        /*1: the list only has this node, so we only need to free it*/
		else{				  /*2: the list has more elements*/
			l->first = aux2;
			aux1->next = NULL;
			free(aux1);
			return SUCCESS;
		}
	}
	while (aux2->code != pos && aux2 != NULL){ /*runs through the list until it ends or until the code is found*/
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	if (aux2 == NULL) return ERROR;            /*if the code was not found, error is returned*/
	if (aux2->code == code){		   /*if the code was found, we start removing the node, but only after*/
		aux1->next = aux2->next;           /*linking correctly the nodes after and before the one to be removed*/
		aux2->next = NULL;
		free(aux2);
		return SUCCESS;
	}
	return ERROR;				   /*if the function hasn't returned success yet, it has failed somewhere, so */
}					           /*we return error*/

int GB_InsertKeyword(LIST* l, int code){
	if (GB_CheckInvalidList(l)) return ERROR; 
	if (GB_CheckEmptyList(l)) return ERROR;
	NODE* n = GB_SearchCode(l, code);
	char dump = ' ';
	int count = 0;
	int i = 0, j = 0, k = 0;
	while (n->keyw[count][0] != NULL || count > 10){
		count++;
	}
	if (count > 10){
		printf("No more space for keywords\n");
		return ERROR;
	}
	dump = ' '; /*resets the dump character*/
	while (dump != '\n'){
		printf("Insert here your new keyword\n");
		dump = getchar();
		n->keyw[count][k] = dump;
		k++;
		}
	}
	return SUCCESS;
}
