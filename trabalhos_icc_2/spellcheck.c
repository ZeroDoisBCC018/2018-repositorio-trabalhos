#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool bsearch_strings(char** str1, char* str2, int st, int end){
	
	if(st >= end) return false;
	
	int center = (int) (end+st)/2.0;
	
	if(strcasecmp(str1[center], str2) == 0) return true;
	
	if(strcasecmp(str1[center], str2) < 0) return bsearch_strings(str1, str2, center+1, end);
	
	if(strcasecmp(str1[center], str2) > 0) return bsearch_strings(str1, str2, st, center);
	
	return true;
}

void mergesort_strings(char** v, int* size, int st, int end){
	
	int center = (int) ((end+st)/2.0);
	
	mergesort_strings(v, size, st, center);
	mergesort_strings(v, size, center+1, end);
	
	int h = (end-st+1);
	char** aux = (char**) malloc(sizeof(char*) * h);
	int g = 0;
	for(g = 0; g < h; g++){
		aux[g] = (char*) malloc(46*sizeof(char));
	}
	
	int i = st;
	int j = center+1;
	int k = 0;
	int a, dif;
	
	while(i <= center && j <= end){
		
		a = strcasecmp(v[i], v[j]);
		
		if(a < 0){
			
			strcpy(aux[k], v[i]);
			i++;
			
		} else if(a > 0){
			
			strcpy(aux[k], v[j]);
			j++;
			
		} else {
			
			strcpy(aux[k], v[i]);
			i++;
			j++;
			dif++;
		}
		k++;
	}
	
	*size -= dif;
	
	for(i = st, k = 0; i <= (end-dif); i++, k++){
		strcpy(v[i], aux[k]);
	}
	
	char* last = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for(i = (end - dif); i < end; i++){
		strcpy(v[i], last);
	}
	
	for(g = 0; g < h; g++){
		free(aux[i]);
	}
	free(aux);
}

int main(){
	
	char dc[64];
	char tw[64];
	
	scanf("%s", dc);
	scanf("%s", tw);
	
	FILE* dcp = fopen(dc, "r");
	FILE* twp = fopen(tw, "r");
	
	char** d = (char**) malloc(5000*sizeof(char*));
	int i = 0;
	for(i = 0; i < 5000; i++){
		d[i] = (char*) malloc(46*sizeof(char));
	}
	
	char** t = (char**) malloc(5000*sizeof(char*));
	for(i = 0; i < 5000; i++){
		t[i] = (char*) malloc(46*sizeof(char*));
	}
	
	i = 0;
	do{
		fscanf(dcp, "%[a-zA-Z]%*[^a-zA-Z]", d[i]);
		i++;
	} while(!feof(dcp));
	
	mergesort_strings(d, &i, 0, 5000);
	
	char *dump, *ss;
	
	int w = 0;
	int z = 0;
	bool check = false;
	char c = 'q', x = 'q';
	
	do{
		fscanf(twp, "%ms", &dump);
	
		ss = strstr(dump, "\"text\":");
		if(ss != NULL){
			
			check = true;
			
			while(x != '\r' && x != '\n'){
				
				while(isalpha(c)){
					c = fgetc(twp);
					t[z][w] = c;
					w++;
				}
				
				t[z][w] = '\0';
				w = 0;
				c = 'q';
				
				if(bsearch_strings(d, t[z], 0, i)){
					printf("%s ", t[z]);
				}
				
				z++;
			}
		}
		
		printf("\n");
		
	} while(!feof(twp));
	
	if(check == false) printf("No tweets to check\n");
	
	int y = 0;
	for(y = 0; y < 5000; y++){
		free(d[y]);
	}
	free(d);
	
	for(y = 0; y < 5000; y++){
		free(t[y]);
	}
	free(t);
	
	fcloseall();
	return EXIT_SUCCESS;
} 
