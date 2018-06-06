// Balanceamento de Recursos:
// Este programa implementa um algoritmo de "flood-fill" para simular
//um jogo de real-time strategy entre 2 jogadores.
//OBS: os comentarios estao na ordem disposta na funcao main.
// Trabalho 3 de ICC 1 - Prof. Moacir Ponti - Entrega dia 28/05/2018
// Joao Vitor Nascimento Villaca - ICMC/USP - NoUSP: 10724239
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void floodfill(int x, int y, int *nosteps, int map[9][9], int nores, int **posres, int *count){
//checagem se o local ja foi acessado, representado por valores "booleanos" (0 ou 1)
	if(map[x][y] == 0){
	//apos acessado, o local e preenchido com 1
		map[x][y] = 1;
	//o numero de passos cresce de acordo
		(*nosteps)++;
		//a contagem total dos passos cresce, somando os passos dados
		//ate chegar em cada recurso existente no mapa
		for(int i=0; i<nores; i++){
			if(x == posres[0][i] && y == posres[1][i])
				*count += *nosteps;
		}		
		//recursao do flood-fill, para cada direcao do mapa
		//sul
		if(x+1<9)
			floodfill(x+1, y, nosteps, map, nores, posres, count);
		//norte
		if(x-1>=0)
			floodfill(x-1, y, nosteps, map, nores, posres, count);
		//oeste
		if(y-1>=0)
			floodfill(x, y-1, nosteps, map, nores, posres, count);
		//leste
		if(y+1<9)
			floodfill(x, y+1, nosteps, map, nores, posres, count);
		//o numero de passos aumenta em 1 por chamada da funcao
		nosteps++;
	}else{
		return;
	}
}
//na funcao "freematrix" a matriz na memoria heap e desalocada
//ha a liberacao de cada vetor e depois do vetor de ponteiros
void freematrix(int **posres){
    for(int i = 0; i<2; i++){
        free(posres[i]);
    }
    free(posres);
}

int main(int argc, char* argv[]){
//variaveis, o mapa e uma copia para o jogador 2 ("pam")
	int map[9][9];
	int pam[9][9];
	int i, j;
	int nores, pos1r, pos1c, pos2r, pos2c;
	int nozero = 0;
	int nosteps = 0;
	int count = 0;
//leitura do mapa
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			scanf("%d", &map[i][j]);
			pam[i][j] = map[i][j];
			//contagem do numero de zeros
			if(map[i][j] == 0)
				nozero++;
			
		}
	}
//leitura das coordenadas dos jogadores
	scanf("%d %d", &pos1r, &pos1c);
	scanf("%d %d", &pos2r, &pos2c);
	scanf("%d", &nores);

//alocacao dinamica de uma matriz com a posicao dos recursos (x, y)
	int** posres;
	posres = (int**)malloc(2*sizeof(int*));
	posres[0] = (int*)malloc(sizeof(int));
	posres[1] = (int*)malloc(sizeof(int));

	for(i=0;i<nores;i++){
		scanf("%d %d", &posres[0][i], &posres[1][i]);
	}

	double e1, e2, module;
//chamada da funcao recursiva de flood-fill
//a contagem e o numero de passos sao zerados para cada chamada	
	nosteps = 0;	
	floodfill(pos1r, pos1c, &nosteps, map, nores, posres, &count);
//calculo do E1
	e1 = (1/(double)nores)*((double)count/nozero);
	
	count = 0;
	nosteps = 0;
	floodfill(pos2r, pos2c, &nosteps, pam, nores, posres, &count);
//calculo do E2
	e2 = (1/(double)nores)*((double)count/nozero);
	
	printf("%lf\n%lf\n", e1, e2);

	module = fabs(e1-e2);
	if(module<=0.001)
		printf("O mapa eh balanceado\n");
	else if(e1>e2)
		printf("O jogador 2 possui vantagem\n");
		else{
			printf("O jogador 1 possui vantagem\n");
		}
	
//chamada de uma funcao que desaloca a matriz na memoria heap
	freematrix(posres);
	return 0;
}
