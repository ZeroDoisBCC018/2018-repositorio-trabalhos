#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct _node_{
	struct _node_ *next;
	struct _node_ *prev;
	char* title;
	char* url;
	int day, month;
	int hour, minute;
} node;

typedef struct _list_{
	node* first;
	node* last;
	int size;
} list;

list newlist(void){
	list nlist;
	nlist.first = NULL;
	nlist.last = NULL;
	nlist.size = 0;
	return nlist;
}

node* newnode(void){
	node* nn = (node*)malloc(sizeof(node));
	if(nn == NULL) return NULL;
	else{
		nn->next = NULL;
		nn->prev = NULL;
		return nn;
	}
}

void insertnode(list adt, node* n){
	if(adt.first == NULL){
		adt.first = n;
		adt.last = n;
		adt.size = 1;
	} else {
		n->prev = adt.last;
		adt.last->next = n;
		adt.last = n;
	}
}

node* searchtab(list adt, char* sitename){
	node* aux = l.first;
	while(aux->title != sitename){
		if(aux->next == NULL) return NULL;
		else aux = aux->next;
	}
	return aux;
}

//faltam varias coisas aqui
void movetab(list adt, node* tab, int pos){
	node* aux = NULL;
	int arrow;
	if(tab == NULL) return;
	if(pos == 1){
		
	} else if(pos == adt.size){
		
	} else if(pos > (adt.size)/2){
		arrow = pos;
		aux = l.last;
		while(pos !=)
	} else {
		
	}
}

void printlist(list adt){
	node* aux = adt.first;
	do{
		printf("%s %s %d/%d %d:%d\n", aux->title, aux->url, aux->day, aux->month, aux->hour, aux->minute);
	} while(aux->next != NULL);
	printf("\n");
}

void endlist(list adt){
	node* aux;
	aux = adt.last;
	while(aux->prev != NULL){
		aux = aux->prev;
		free(aux->next);
	}
	free(adt.first);
}

int main(void){
	
	int option;
	list tablist = newlist();
	node* newtab = NULL;
	char* sitename;
	int newpos;
	
	do{
		scanf("%d", &option);
		
		switch(option){
			case 1:
				newtab = newnode();
				scanf("%30s[^\n]", newtab->title);
				scanf("%1024s[^\n]", newtab->url);
				scanf("%2d %2d", &newtab->day, &newtab->month);
				scanf("%2d %2d", &newtab->hour, &newtab->minute);
				insertnode(tablist, newtab);
				newtab = NULL;
				continue;
			case 2:
				scanf("%1024s[^\n]", sitename);
				scanf("%d", &newpos);
				movetab(l, searchtab(l, sitename), pos);
				continue;
			case 3: //ordenacao
				continue;
			case 4:
				printlist(l);
				continue;
			case 5:
				endlist(l);
				break;
			default:
				printf("Invalid option.\n");
				continue;
		}
	} while(option != 5);
	return EXIT_SUCCESS;
}


/*
 * 
	while(arrow != pos-1){
		aux = aux->next;
		arrow++;
	}
	tab->next = aux->next;
	aux->next = tab;
 */
