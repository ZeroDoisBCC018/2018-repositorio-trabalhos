struct node_ {
	SITE site;
	NODE* next; 
}

struct list_ {
	NODE* first;
	NODE* last;
	int size;
}

void SortList(LIST l){
}

LIST CreateList(void){
	LIST l;
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
	return l;
}

void EraseList (LIST* l)
{
	if (CheckEmptyList == 1) return ERROR;
	NODE* aux1, aux2;
	aux1 = l->first;
	while (aux1 != NULL){
		aux2 = aux1->next;
		free(aux1);
		aux1 = aux2;
	}
	l->first = NULL;
	if (CheckEmptyList == 1) return 0;
	else return ERROR;
}

//InsertFistPos
//InsertLastPos
//Insert@Pos
//Remove@Pos
//CountList

/*void PrintList (int size, LIST l)
{
	int i;
	NODE* aux;	
	aux = l->first;
	
	for (i = 0; i < size; i++)
	{
		printf("
	}
}*/

int CheckEmptyList(NODE* first){
	return (first == NULL) ? 1 : 0;
}

int CheckInvalidSize(LIST l){ // this functions as both maximum size check and invalid (negative) size check
	return (l->size > 9999 || l->size < 0) ? 1 : 0;
}

