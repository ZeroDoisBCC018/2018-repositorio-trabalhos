#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main()
{

    int n, i = 0, j;
    double xc, yc, xr, yr, d1, d2;
    double b[2];
    bool flag;

    scanf("%d %lf %lf %lf %lf", &n, &xc, &yc, &xr, &yr);

    while (i < n) {

        for (j = 0; j < 2; j++) {
            scanf("%lf", &b[j]);
        }

        d1 = sqrt(pow((b[0] - xc), 2) + pow((b[1] - yc), 2));
        d2 = sqrt(pow((b[0] - xr), 2) + pow((b[1] - yr), 2));

        if (d1 <= (d2 / (double)2.00)) {
            printf("O coelho pode escapar pelo buraco (%.3lf,%.3lf).\n", b[0], b[1]);
            flag = 1;
            break;
        }
        else {
            flag = 0;
        }
        i++;
    }

    if (flag == 0) {
        printf("O coelho nao pode escapar.\n");
    }

    return EXIT_SUCCESS;
}
