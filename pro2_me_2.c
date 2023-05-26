#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i, j, a, b, score, totalmean = 0;
    double mean, dev, totaldev = 0;
    printf("Number of random numbers?");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        b = rand() % 100;
        totalmean += b;
    }
    mean = (double)totalmean / a;
    for (j = 1; j <= a; j++)
    {
        totaldev += pow((double)b - mean, 2);
    }
    dev = sqrt(totaldev / a);
    printf("Mean = %lf", mean);
    printf("Standard deviation = %lf", dev);
    return 0;
}