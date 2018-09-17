#include <stdio.h>
#include <stdlib.h>

void recHanoi(int n, char orig, char meio, char dest){
	if(n == 1) fprintf(stdout, "Mova de %c para %c\n", orig, dest);
	else{
		recHanoi((n-1), orig, dest, meio);
		recHanoi(1, orig, meio, dest);
		recHanoi((n-1), meio, orig, dest);
	}
}

int main(){
	fprintf(stdout, "Algoritmo recursivo de Hanoi para 3 torres\n");
	fprintf(stdout, "Digite o numero de discos (nao recomendado para mais de 10 discos):");
	 
	char a = 'A', b = 'B', c = 'C';
	int n = fscanf(stdin, "%d", &n);
	 
	recHanoi(n, a, b, c);
	exit(EXIT_SUCCESS);
}
