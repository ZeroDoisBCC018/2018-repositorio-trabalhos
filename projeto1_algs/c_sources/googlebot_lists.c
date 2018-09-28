#define ERROR -404
#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include "googlebot_ds.h"
typedef int boolean;

struct node_ {
    SITE* site;
    NODE* next;
};

struct list_ {
    NODE* first;
    NODE* last;
    int size;
};

NODE* GB_NewNode (void) {
	NODE* new = (NODE*) malloc(sizeof (NODE));
	new->next = NULL;
	new->site = NULL;
	return new;
}

LIST* GB_NewList (void) {
    LIST* l = (LIST*) malloc(sizeof (LIST));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

boolean GB_CheckEmptyList (LIST* l) {
    return (l->size == 0 ? TRUE : FALSE);
}

boolean GB_CheckInvalidList (LIST* l) {
    return ((l->size > 9999 || l-> size < 0) ? TRUE : FALSE);
}

int GB_CountListSize (LIST* l) { 
	if (l == NULL) return ERROR;
	NODE* aux = l->first;
	int count = 0;
	while (aux != NULL){
		count++;
	}
	l->size = count;
	if (GB_CheckInvalidList(l)) return ERROR;
	return count;
}

void GB_SortList (LIST* l) { /*TODO*/ 
}

int GB_InsertNodeFirstPos (LIST* l, NODE* n) {
    if (GB_CheckInvalidList(l)) return ERROR;
    if (GB_CheckEmptyList(l)) {
        l->first = n;
        return SUCCESS;
    } else {
        NODE* aux;
        aux = l->first;
        l->first = n;
        n->next = aux;
        aux = NULL;
        (l->size)++;
    }
    if (GB_CheckEmptyList(l)) return ERROR;
    else if (GB_CheckInvalidList(l)) return ERROR;
    return SUCCESS;
}

int GB_InsertNodeLastPos (LIST* l, NODE* n) {
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

int InsertNodeAtPosition (LIST* l, NODE* n, int code){
	if (GB_CheckInvalidList(l)) return ERROR;
	if (n == NULL) n = GB_NewNode;
	if (GB_CheckEmptyList(l)) {
		l->first = n;
		l->last = n;
		l->size = 1;
		return SUCCESS;
	}
	GB_SortList(l);
	NODE* aux1, aux2;
	aux1 = l->first;
	aux2 = l->first;
	int i, count = 0;
	while (aux1->next != NULL || aux1->next->site->code < code) {
		aux1 = aux1->next;
		count++;
	}
	for(i = 0; i < (count-1); i++){
		aux2 = aux2->next;
	}
	aux2->next = n;
	n->next = aux1;
	aux1 = NULL;
	aux2 = NULL;
	if (GB_CheckInvalidList(l)) return ERROR;
	return SUCCESS;
}

int GB_SearchCode (LIST* l, int code) {
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

/* REVER */
int GB_UpdateRelevance (LIST* l, int code, int newrel) {
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

int GB_EraseList (LIST* l) {
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

void GB_Sort(LIST* l)
{
	static int listsize = GB_CountListSize(l);
	if (listsize == 0 || listsize == 1) return;
	
	else
	{
		LIST* auxfirst == NULL;
		LIST* auxsecond == NULL;
		NODE* auxnode == l->first;
		int i = 0;
		
		auxfirst = GB_NewList;
		auxsecond = GB_NewList;
		
		while (i < (listsize/2))
		{
			GB_InsertNodeLastPos (auxfirst, auxnode);
			auxnode = auxnode->next;
			
			i++;
		}
		
		while (i <= listsize)
		{
			GB_InsertNodeLastPos (auxsecond, auxnode);
			auxnode = auxnode->next;
			
			i++;
		}
		
		GB_sort(auxfirst);
		GB_sort(auxsecond);
		GB_merge(auxfirst, auxsecond);
	}
		
}

void GB_Merge (LIST* lfirst, LIST* lsecond)
{
	LIST* aux == GB_NewList;
	
	
	int lfirst_size = GB_CountListSize(lfirst);
	int lsecond_size = GB_CountListSize(lsecond);
	NODE* auxnode1 == lfirst->first;
	NODE* auxnode2 == lsecond->second;
	
	while (lfirst_size != 0 && lsecond_size != 0)
	{
		if (auxnode1->code < auxnode2->code)
		{
			GB_InsertNodeLastPos (aux, auxnode1);
			auxnode1 = auxnode1->next;
			
		}
		
		else
		{
			GB_InsertNodeLastPos (aux, auxnode2);
			auxnode2 = auxnode2->next;
		}
	}
	
	while (i > lsecond_size)
	{
		GB_InsertNodeLastPos (aux, auxnode2);
		auxnode2 = auxnode2->next;
	}	
	
}
