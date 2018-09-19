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
	l->fist = NULL;
	l->last = NULL;
	l->size = 0;
	return l;
}

//EraseList
//InsertFistPos
//InsertLastPos
//InsertAtPos
//RemoveAtPos
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

