#include <stdio.h>
#include <stdlib.h>

void recHanoi(int n, char orig, char mid, char dest){
	if(n == 1) printf("Move from %c to %c\n", orig, dest);
	else{
		recHanoi((n-1), orig, dest, mid);
		recHanoi(1, orig, mid, dest);
		recHanoi((n-1), mid, orig, dest);
	}
}

int main(int argc, char* argv[]){
	 
	char a = 'A', b = 'B', c = 'C';
	int n = atoi(argv[1]);
	
	recHanoi(n, a, b, c);
	
	return 0;
}
