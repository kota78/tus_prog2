#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i, j, a, c, score, credit, total = 0;
    double mean, dev, totaldev = 0;
    double gpa;
    int b[100];
    printf("Number of random numbers?");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        c = rand() % 100;
        total += c;
    }
    mean = (double)total / a;
    for (j = 1; j <= a; j++)
    {
        totaldev += pow((double)c - mean, 2);
    }
    dev = sqrt(totaldev / a);
    printf("Mean = %lf", mean);
    printf("Standard deviation = %lf", dev);
    return 0;
}