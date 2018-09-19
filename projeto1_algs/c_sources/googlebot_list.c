struct node_ {
	SITE* site; //TA EM OUTRO SEGMENTO, ACHO QUE PRECISA SER PONTEIRO (02)
	NODE* next; 
}node_;

struct list_ {
	NODE* first;
	NODE* last;
	int size;
}list_;

void SortList(LIST* l){ //TODO
}

int SearchCode(LIST* l){//TODO
	
}

int InsertSite(LIST* l){ //TODO
	
}
LIST CreateList(void){
	LIST l;
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
	return l;
}

int CheckEmptyList(NODE* first){
	return (first == NULL) ? 1 : 0;
}

int CheckInvalidSize(LIST* l){ // this functions as both maximum size check and invalid (negative) size check
	return (l->size > 9999 || l->size < 0) ? 1 : 0;
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

int UpdateRelevance(LIST* l, int code){ //acho que da prafazer sem passar o code (02)
	if (CheckEmptyList == 1) return ERROR;
	if (code < 0 || code > 1000) return ERROR;
	NODE* aux;
	aux = l->first;
	int newrel, check = 0;
	for (int i = 0; i < l->size; i++){
		if(aux->site->code == code){
			scanf("%d", &newrel);
			aux->site->code = newrel;
			check = 1;
		}
	}
	if (check != 1) return ERROR;
	else return 0;
}
