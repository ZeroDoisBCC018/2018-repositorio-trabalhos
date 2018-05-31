#include <stdio.h>
#include <stdlib.h>
int** alloc(int n, int m){
    int i;
    int** mat;
    mat = (int**)malloc(n * sizeof(int*));
    for(i = 0; i<n; i++){
        mat[i] = (int*)malloc(m * sizeof(int));
        
    }
    return mat;
}
void free_matrix(int **mat, int n){
    int i;
    for(i = 0; i<n; i++){
        free(mat[i]);
    }
    free(mat);
}
void update(int **mat, int n, int m, int i, int j){
	if(i>=0 && i<n && j>= 0 && j<m){
		mat[i][j] += 1;
	}
}
int main(){
    int n, m, q;
    int** mat;
    int i, j, k;
    scanf("%d %d %d", &n, &m, &q);
    mat = alloc(n, m);
	for(i = 0; i<n; i++){
		for(j = 0; j<m; j++){
			mat[i][j] = 0;
		}
	}	
    for(k = 0; k<q; k++){
		scanf("%d %d", &i, &j);
		update(mat, n, m, i, j);
	}
    
    for(i = 0; i<n; i++){
        for(j = 0; j<m; j++){
            printf("%d ", mat[i][j]);
        }
		printf("\n");
    }
    free_matrix(mat, n);
	return 0;
}
