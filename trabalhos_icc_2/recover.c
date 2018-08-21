#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int count = 0, r;
  FILE* fp = NULL;
  char p_name[8], img[512];

  do {
    r = scanf("%512c", img);

    if (r == EOF) break;

    if (img[0] == 0xff && img[1] == 0xd8 && img[2] == 0xff) {
      if (fp != NULL) fclose(fp);

      sprintf(p_name, "%03d.jpg", count);
      count++;
      fp = fopen(p_name, "wb");

      if (fp != NULL) {
        fwrite(img, 512, sizeof(char), fp);
      }
    }
  } while (r != EOF);

  if (fp == NULL) {
    printf("Could not find pictures\n");
  }

  if (fp != NULL) {
    fclose(fp);
  }

  return EXIT_SUCCESS;
}
