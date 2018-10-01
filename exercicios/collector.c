#include <stdlib.h>
#include <stddef.h>
#include "collector.h"

void** ptrs;

void start_collector(void){
	ptrs = (void**) malloc(500*sizeof(void*));
	for(int i = 0; i < 500; i++){
		ptrs[i] = NULL;
	}
}

void put_in_collector(void* p){
	static int i = 0;
	ptrs[i] = p;
	i++;
}

void free_collector(void){
	for(int i = 500; i > 0; i--){
		free(ptrs[i]);
	}
	free(ptrs);
}
