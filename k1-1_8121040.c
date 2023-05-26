#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double x, y, r2, pi, d;
    int i, j, n, count;
    for (i = 1; i < 8; i++){
        count = 0;
        n=pow(10.0, (double)i);
        printf("%d,", n);
        for (j = 0; j < n; j++)
            {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            r2 = pow(x, 2.0) + pow(y, 2.0);
            if (r2 <= 1)
            {
                count++;
            }
        }
        pi = (double)count / n * 4;
        printf("%f,", pi);
        printf("%f,\n", fabs(pi-M_PI));
    }
    return 0;
}