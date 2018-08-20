#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* jpg_recover(FILE* f, int count){
	char n[7];
	sprintf(n, "%3d.jpg", count);
	fopen(n, wb);
	fwrite
}

int main(void){
	
	int count = 0;
	FILE* fp = NULL;
	unsigned char dump, img[512];
	
	do{
		scanf("%c", &dump);
		if(dump == '0xff'){
			do{
				img[0] = dump;
				for(int i = 1; i<512; i++){
					scanf("%c", &img[i]);
				}
					jpg_recover(fp, count);
					count++;
				}while(scanf(stdin) != EOF);
			}
		}			
	}while(scanf(stdin) != EOF);		
	return EXIT_SUCCESS;
}
