#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int count = 0;
    unsigned char img[512];
    char p_name[8];
    FILE* fp = NULL;

    while (fread(img, sizeof(unsigned char), 512, stdin)) {

        if (img[0] == 0xff && img[1] == 0xd8 && img[2] == 0xff && count == 0) {
            sprintf(p_name, "%03d.jpg", count);
            count++;
            fp = fopen(p_name, "wb");

            if (fp != NULL) {
                fwrite(img, 1, 512, fp);
            }
        }
        else if (img[0] == 0xff && img[1] == 0xd8 && img[2] == 0xff) {
            fclose(fp);
            sprintf(p_name, "%03d.jpg", count);
            count++;
            fp = fopen(p_name, "wb");
            fwrite(img, 1, 512, fp);
        }
        else if (count == 0) {
            printf("Could not find pictures\n");
            break;
        }
        else {
            fwrite(img, 1, 512, fp);
        }
    }

    return EXIT_SUCCESS;
}
