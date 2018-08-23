/*Recover:
Este programa recupera fotos .jpg recebido num dump
de blocos de 512 bytes cada lidos via entrada padrao.
Trabalho 1 de ICC-II - Prof. Moacir Ponti - Entrega dia 22/08/2018
Joao Vitor Nascimento Villaca - ICMC/USP - NoUSP: 10724239*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int img_count = 0;
    unsigned char img_dump[512];
    char p_name[8];
    FILE* fp = NULL;

    //O loop continuara ate que a funcao fread() retorne EOF
    while (fread(img_dump, sizeof(unsigned char), 512, stdin)) {

        //Este if checa exclusivamente a chegada da primeira imagem no dump
        if (img_dump[0] == 0xff && img_dump[1] == 0xd8 && img_dump[2] == 0xff && img_count == 0) {
            sprintf(p_name, "%03d.jpg", img_count);
            img_count++;
            fp = fopen(p_name, "wb");

            if (fp != NULL) {
                fwrite(img_dump, 1, 512, fp);
            }
        }

        //Este else/if checa se a leitura detectou uma nova imagem (outro header jpg)
        else if (img_dump[0] == 0xff && img_dump[1] == 0xd8 && img_dump[2] == 0xff) {
            fclose(fp);
            sprintf(p_name, "%03d.jpg", img_count);
            img_count++;
            fp = fopen(p_name, "wb");
            fwrite(img_dump, 1, 512, fp);
        }

        //Se nenhum header foi detectado no dump, a conclusao final e' de que nao ha imagens
        else if (img_count == 0) {
            printf("Could not find pictures\n");
            break;
        }

        //Por fim, se o proximo bloco e' uma continuacao da imagem anterior
        //ele e' gravado no mesmo arquivo, completando a imagem
        else {
            fwrite(img_dump, 1, 512, fp);
        }
    }

    return EXIT_SUCCESS;
}
