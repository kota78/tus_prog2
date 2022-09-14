#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 100000000

int main(void)
{
    double x, y, y2, s, d;
    int i, j=10, count=0;
        for (i = 0; i < NMAX; i++)
            {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            if (y*y <= x)
            {
                count++;
            }
            if (i%j == 0) {
                s = (double)count / j;
                printf("%d, %f,\n",j, s);
                j=j*10;
            }
        }
    return 0;
}