#include <stdio.h>
#include <stdlib.h>

int equal(char *a, char *b){
	if(a == b){
		return 1;
	} else {
		return 0;
	}
}
int length(char *str){
	int i = 0;
	int count = 0;
	while(str[i] != '\n'){
		i++;
		count++;
	}
	return count;
}

void read_recursiva(char *str, int i){
	str = (char*)realloc(str,(i+1)*sizeof(char));
	scanf(" %c", &str[i]);
	
	if(str[i] == '\n'){
		str[i] = '\0';
		return;
	} 
	i++;
	read_recursiva(str, i);
}

char *read_line(){
	char *str = NULL;
	read_recursiva(str, 0);
	return str;
}

int main(int argc, char const *args[]){
	char *str1 = read_line();
	length(str1);
	
	char *str2 = read_line();
	length(str2);
	
	int r = equal(str1, str2);
		if(r == 1){
			printf("Linhas 1 e 2: %s", str1);
		} else {
		printf("Linha 1: %s\n", str1);
		printf("Linha 2: %s\n", str2);
		}
	free(str1);
	free(str2);
	return 0;
}
