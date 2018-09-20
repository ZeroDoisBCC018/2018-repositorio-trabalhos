#define ERROR -32000
#define SUCCESS 1

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

int EraseList (LIST* l)
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

int InsertFirstPos (LIST* l, NODE* n)
{
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

int InsertLastPos (LIST* l, NODE* n) // TODO: FAZER TODAS AS ALOCAÇÕES!!!!1!!1!1!!
{
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
//Insert@Pos
//Remove@Pos
int CountList (LIST* l, NODE* f) // especificar que deve receber o list->first
{
	 static int i = 0;
	 l->size = i;
	 if (l->next == NULL)
	 {
		 l->size++;
		 return 1;
	 }
	 
	 else return (CountList (l, f->next);
}

int CheckEmptyList(NODE* first){
	return (first == NULL) ? 1 : 0;
}

int CheckInvalidSize(LIST l){ // this functions as both maximum size check and invalid (negative) size check
	return (l->size > 9999 || l->size < 0) ? 1 : 0;
}
