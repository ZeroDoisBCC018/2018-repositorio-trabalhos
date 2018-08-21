#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int r, count = 0;
  char img[512], p_name[8];
  FILE* fp = NULL;

  do {
    r = scanf("%512c", img);

    if (img[0] == 0xff && img[1] == 0xd8 && img[2] == 0xff) {
      sprintf(p_name, "%03d.jpg", count);
      count += 1;
      fp = fopen(p_name, "wb");

      if (fp != NULL) {
        fwrite(img, 512, sizeof(char), fp);
      }
    }
  } while (r != EOF);

  if (fp != NULL) {
    fclose(fp);
  } else {
    printf("Could not find pictures\n");
  }

  return EXIT_SUCCESS;
}
