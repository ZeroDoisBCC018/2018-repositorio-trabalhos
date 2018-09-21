#define ERROR -32000
#define SUCCESS 1

struct node_ {
	SITE* site;
	NODE* next; 
};

struct list_ {
	NODE* first;
	NODE* last;
	int size;
};

LIST* GB_CreateList(void){
	LIST* l;
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
	return l;
}

void GB_EraseList (LIST* l){
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

int GB_CheckEmptyList(LIST* l){
	return ((l->first == NULL) ? 1 : 0);
}

int GB_CheckInvalidList(LIST* l){
	return ((l->size > 9999 || l->size < 0) ? 1 : 0);
}

int InsertFirstPos (LIST* l, NODE* n){
		if (CheckInvalidSize(l) == 1) return ERROR;
		else if (l->size == 0) {
			l->first = n;
			l->last = n;
			size++;
		} else {
		
		NODE* aux;
		
		aux = l->first;
		l->first = n;
		n->next = aux;
		aux = NULL;
		free(aux);
		
		l->size++;
		if (CheckInvalidSize(l) == 1) return ERROR;
		}
		return SUCCESS;
}

int InsertLastPos (LIST* l, NODE* n){
		if (CheckEmptyList == 1) return ERROR;
		else if (l->size == 0) {
			l->first = n;
			l->last = n;
			size++;
		} else {
		
		l->last->next = n;
		l->last = n;
		n->next = NULL;
		size++;
		if (CheckInvalidSize(l) == 1) return ERROR;
		return SUCCESS;
}

int CountList (LIST* l){
	 static int i = 0;
	 l->size = i;
	 if (l->next == NULL){
		 l->size++;
		 return 1;
	 }
	 else return (CountList (l, f->next);
}

int GB_SearchCode(LIST* l, int code){
	int aux = l->first;
	int c = aux->site->code;
	while(c != code || aux = l->last){
		aux = aux->next;
		c = aux->site->code; 
	}
	if(aux = l->last) return ERROR;
	else return c;
}

void GB_SortList(LIST* l){ TODO
}

/* REVER */
int GB_UpdateRelevance(LIST* l, int code){
	if (CheckEmptyList == 1) return ERROR;
	if (code < 0 || code > 1000) return ERROR;
	NODE* aux;
	aux = l->first;
	int newrel, check = 0, i;
	for (i = 0; i < l->size; i++){
		if(aux->site->code == code){
			scanf("%d", &newrel);
			aux->site->code = newrel;
			check = 1;
		}
	}
	if (check != 1) return ERROR;
	else return 0;
}

//Insert@Pos
//Remove@Pos
