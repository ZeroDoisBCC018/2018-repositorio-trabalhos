#define ERROR -404
#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include "googlebot_ds.h"

struct node_ {
    SITE* site;
    NODE* next;
};

struct list_ {
    NODE* first;
    NODE* last;
    int size;
};

LIST* GB_CreateList(void) {
    LIST* l = (LIST*) malloc(sizeof(LIST));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

int GB_CheckEmptyList(LIST* l) {
    return (l->size == 0 ? TRUE : FALSE);
}

int GB_CheckInvalidList(LIST* l) {
    return ((l->size > 9999 || l-> size < 0) ? TRUE : FALSE);
}

int GB_EraseList(LIST* l) {
    NODE* aux1, aux2;
    aux1 = l->first;
    while (aux1 != NULL) {
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
    aux1 = NULL;
    aux2 = NULL;
    free(l);
    return SUCCESS;
}

int GB_InsertNode@First(LIST* l) {
    if (GB_CheckInvalidList(l)) return ERROR;
    if (GB_CheckEmptyList(l)) {
        NODE* new = (NODE*) malloc(sizeof(NODE));
        l->first = new;
        return SUCCESS;
    } else {
        NODE* aux;
        aux = l->first;
        l->first = n;
        n->next = aux;
        aux = NULL;
        free(aux);
        (l->size)++;
    }
    if (GB_CheckEmptyList(l)) return ERROR;
    else if (GB_CheckInvalidList(l)) return ERROR;
    return SUCCESS;
}

int GB_InsertNode@Last(LIST* l, NODE* n) {
    if (GB_CheckInvalidList(l)) return ERROR;
    else if (GB_CheckEmptyList(l)) {
        l->first = n;
        l->last = n;
        (l->size)++;
    } else {
        l->last->next = n;
        l->last = n;
        n->next = NULL;
        (l->size)++;
        if (GB_CheckEmptyList(l)) return ERROR;
        else if (GB_CheckInvalidList(l)) return ERROR;
        return SUCCESS;
    }
}

int GB_CountListSize(LIST* l) { /*TODO, a versao anterior nao fazia sentido algum (02)*/
}

int GB_SearchCode(LIST* l, int code) {
	if (GB_CheckEmptyList(l)) return ERROR;
	else if (GB_CheckInvalidList(l)) return ERROR;
	else {
		NODE* aux = l->first;
		int c = aux->site->code;
		while (c != code || aux != l->last) {
			aux = aux->next;
			c = aux->site->code;
		}
	}
	if (aux == l->last) return ERROR;
	else return c;
}

void GB_SortList(LIST * l) { /*TODO*/ }

/* REVER */
int GB_UpdateRelevance(LIST * l, int code, int newrel) {
	if (GB_CheckEmptyList(l)) return ERROR;
	else if (GB_CheckInvalidList(l)) return ERROR;
	else if (code < 0 || code > 1000) return ERROR;
	NODE* aux;
	aux = l->first;
	int check = 0;
	int i = 0;
	for (i = 0; i < l->size; i++) {
		if (aux->site->code == code) {
			aux->site->code = newrel;
			check = 1;
		}
	}
	if (check != 1) return ERROR;
	else return 0;
}

/*
int InsertNode@Position(LIST* l, int code){
	if (GB_CheckEmptyList(l) == 1) return ERROR;
	if (GB_CheckInvalidList(l) == 1) return ERROR;
	NODE* aux;
	aux = l->first;
	int count = 0;
	while (count < code){
		aux = aux->next;
		count++;
	}
	return count;
}
*/
