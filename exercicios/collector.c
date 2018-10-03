#include "collector.h"

void** public_storage;
unsigned int public_size;

int collector_start(unsigned int size1){
	public_size = size1;
	public_storage = (void**) malloc(size1*sizeof(void*));
	for (int i = 0; i < size1; i++){
		public_storage[i] = NULL;
	}
	if (public_storage != NULL) return 1;
	return 0;
}

void collect(void* p){
	static int i = 0;
	public_storage[i] = p;
	i++;
}

void freeall(void){
	for (int i = public_size-1; i > 0; i--){
		free(public_storage[i]);
	}
	free(public_storage);
}
