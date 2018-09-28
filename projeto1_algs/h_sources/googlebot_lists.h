#ifndef GOOGLEBOTLIST_H
#define GOOGLEBOTLIST_H
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include "googlebot_ds.h"
typedef int boolean;

/*A NODE struct contains a SITE* and a NODE* for the next node in the list.*/
typedef struct node_ NODE;

/*A LIST struct contains an int for the size, one NODE* for the first node 
 *and one for the last node on the list*/
typedef struct list_ LIST;

NODE* GB_NewNode(void);

LIST* GB_NewList(void);

boolean GB_CheckEmptyList(LIST* l);

/* Invalid size: less than 0 or greater than 9999. */
boolean GB_CheckInvalidList(LIST* l);

int GB_EraseList(LIST* l);

/*Insert node at the first position of the list.*/
int GB_InsertNodeFirstPos(LIST* l, NODE* n);

/*Insert node at the last position of the list.*/
int GB_InsertNodeLastPos(LIST* l, NODE* n);

int GB_CountListSize(LIST* l);

/*Search a site on the list by its code.*/
int GB_SearchCode(LIST* l, int code);

/*Sort the list by site codes using a merge sort algorithm. This is the sort function.*/
void GB_Sort(LIST* l);

/*Merge function for the merge sort algorithm.*/
void GB_Merge(LIST* lfirst, LIST* lsecond);

/*Update the relevance of a choosen site.*/
int GB_UpdateRelevance(LIST* l, int code, int newrel);

/*Insert node at an X specific position of the list.*/
int InsertNodeAtPos(LIST* l, int position); 

#endif
