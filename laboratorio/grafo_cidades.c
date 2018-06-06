#include <stdio.h>
#include <stdlib.h>

void free_matrix(int n, int **matrix){
 for(int i = 0; i<n; i++){
     free(matrix[i]);
 }   
 free(matrix);
}

void func_register(int x, int y, int *matrix_rows, int **matrix){
    matrix_rows[x]++;
    matrix_rows[y]++;
    int sizex = matrix_rows[x]; //vetores com o tamanho da matriz
    int sizey = matrix_rows[y];
    matrix[x] = realloc(matrix[x], matrix_rows[x] * sizeof(int)); //matriz dinamica
    matrix[y] = realloc(matrix[y], matrix_rows[y] * sizeof(int));
    
    matrix[x][sizex - 1] = y;
    matrix[y][sizey - 1] = x;
}

int func_verify(int x, int y, int *matrix_rows, int **matrix){
    for(int i = 0; i<matrix_rows[x]; i++){
        if(matrix[x][i] == y) return 1;
    } return 0;
}
    
int main(){
    int n, q, x, y; //x e y = cidades de 0 a n-1
    char c;
	scanf("%d %d", &n, &q);
    int i, j;
    
	int *matrix_rows = (int*)calloc(n, sizeof(int)); // linhas da matriz
    int **matrix = (int**)malloc(n*sizeof(int*));
	
    for(i = 0; i<n; i++){
         matrix[i] = NULL;    
    } 
    
    for(j = 0; j<q; j++){
        scanf(" %c %d %d", &c, &x, &y);
        if(c == 'c'){
            func_register(x, y, matrix_rows, matrix);
        }else if(func_verify(x, y, matrix_rows, matrix)){
            printf("Existe uma estrada entre %d e %d.\n", x, y);
        }else{
            printf("Nao existe uma estrada entre %d e %d.\n", x, y);
        }
    }
    
    free(matrix_rows);
    free_matrix(n, matrix);
    
    return 0;
}
