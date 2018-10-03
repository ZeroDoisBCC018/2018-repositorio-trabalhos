/*Spellcheck:
Este programa serve como um corretor automatico baseado em livros
utilizados como 'dicionario' para corrigir tweets obtidos por arquivos .json
Trabalho 3 de ICC-II - Prof. Moacir Ponti - Entrega dia 02/10/2018
Joao Vitor Nascimento Villaca - ICMC/USP - NoUSP: 10724239*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
	Busca binaria recursiva para o vetor de strings
*/
bool bsearch_strings(char** str1, char* str2, int st, int end){
	
	if(st >= end) return false;
	
	int center = (int) (end+st)/2.0;
	
	if(strcasecmp(str1[center], str2) == 0) return true;
	
	if(strcasecmp(str1[center], str2) < 0) return bsearch_strings(str1, str2, center+1, end);
	
	if(strcasecmp(str1[center], str2) > 0) return bsearch_strings(str1, str2, st, center);
	
	return true;
}


/*
	Mergesort adaptado ao vetor de strings do programa
	size e passado por referencia para ser modificado fora do escopo
*/
void mergesort_strings(char** v, int* size, int st, int end){
	
	int center = (int) ((end+st)/2.0);
	
	mergesort_strings(v, size, st, center);
	mergesort_strings(v, size, center+1, end);
	
	int h = (end-st+1);
	char** aux = (char**) malloc(sizeof(char*) * h);
	int g = 0;
	for(g = 0; g < h; g++){
		aux[g] = (char*) malloc(46 * sizeof(char));
	}
	
	int i = st;
	int j = center+1;
	int k = 0;
	int a, dif;
	
	//a interpolacao e baseada no retorno da funcao strcasecmp()
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
	
	//size e modificado para servir de parametro da busca binaria posteriormente
	*size -= dif;
	
	for(i = st, k = 0; i <= (end-dif); i++, k++){
		strcpy(v[i], aux[k]);
	}
	
	//essa string e jogada nas ultimas posicoes do vetor
	char* last = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for(i = (end - dif); i < end; i++){
		strcpy(v[i], last);
	}
	
	for(g = 0; g < h; g++){
		free(aux[i]);
	}
	free(aux);
}

int main(int argc, const char * argv[]){
	
	char dc[64];
	char tw[64];
	
	scanf("%s", dc);
	scanf("%s", tw);
	
	FILE* dcp = fopen(dc, "r");
	FILE* twp = fopen(tw, "r");
	
	char** d = (char**) malloc(1000000 * sizeof(char*));
	int i = 0;
	for(i = 0; i < 1000000; i++){
		d[i] = (char*) malloc(46 * sizeof(char));
	}
	
	char** t = (char**) malloc(1000000 * sizeof(char*));
	for(i = 0; i < 1000000; i++){
		t[i] = (char*) malloc(46 * sizeof(char*));
	}
	
	/* sizes faz a contagem do numero
	de strings que sao ocupadas em d */
	i = 0;
	size_t sizes = 0;
	while(feof(dcp) == 0) {
		fscanf(dcp, "%[a-zA-Z]%*[^a-zA-Z]", d[i]);
		sizes += strlen(d[i]);
		i++;
	}
	
	mergesort_strings(d, &i, 0, sizes);
	
	char *dump, *ss;
	
	int w = 0;
	int z = 0;
	bool check = false;
	char c = 'q', x = 'q';
	
	do{
		fscanf(twp, "%ms", &dump); //le as linhas do tweet
	
		ss = strstr(dump, "\"text\":");
		if(ss != NULL){ //se tiver ao menos um tweet no json
			
			check = true;
			
			while(x != '\r' && x != '\n'){
				
				//enquanto o char for alfanumerico
				while(isalpha(c)){
					c = fgetc(twp);

					//ele e adicionado na string
					t[z][w] = c;
					w++;
				}
				
				//forcando o terminador \0
				t[z][w] = '\0';

				//variaveis reinicializadas para a proxima iteracao
				w = 0;
				c = 'q';
				
				//busca binaria da palavra em comum nos dois arquivos
				if(bsearch_strings(d, t[z], 0, i)){
					printf("%s ", t[z]);
				}
				
				z++;
			}
		}
		
		printf("\n");
		
	} while(feof(twp)==0);
	
	if(check == false) printf("No tweets to check\n");
	
	int y = 0;
	for(y = 0; y < 1000000; y++){
		free(d[y]);
	}
	free(d);
	
	for(y = 0; y < 1000000; y++){
		free(t[y]);
	}
	free(t);
	
	fcloseall();
	return EXIT_SUCCESS;
} 