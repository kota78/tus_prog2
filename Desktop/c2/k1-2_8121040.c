#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double x, y, y2, s, d;
    int i, j, n, count;
    for (i = 0; i < 8; i++){
        count = 0;
        n=pow(10.0, (double)i);
        printf("%d,", n);
        for (j = 0; j < n; j++)
            {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            y2 = pow(y, 2.0);
            if (y2 <= x)
            {
                count++;
            }
        }
        s = (double)count / n;
        printf("%f\n,", s);
    }
    return 0;
}