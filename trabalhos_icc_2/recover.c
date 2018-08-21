#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* jpg_recover(FILE* f, int count) {
  char n[7];
  sprintf(n, "%3d.jpg", count);
  fopen(n, wb);
  fwrite
}

int main(void) {
  int count = 0;
  FILE* fp = NULL;
  unsigned char dump, img[512];

  do {
    scanf("%c", &dump);
    if (dump == '0xff') {
      scanf("%c", &dump);
      if (dump == '0xd8') {
		img[0] = '0xff';
        img[1] = dump;

        do {
          while(){
            scanf("%c", &img[i]);
          }
          jpg_recover(fp, count);
          count++;
        } while (scanf(stdin) != EOF);
      }
    }
  } while (scanf(stdin) != EOF);
  return EXIT_SUCCESS;
}
