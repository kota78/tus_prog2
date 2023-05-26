#include <stdio.h>
#include <unistd.h>
#define N 31
#define MAXGEN 7

static int cell[N], a[N];

int init(void)
{
    int i;
    for (i = 0; i <= N; i++)
    {
        cell[i] = 0;
        a[i] = 0;
    }
    cell[N / 2] = 1;
}

int dump(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (cell[i] == 0)
        {
            printf(".");
        }
        else
        {
            printf("@");
        }
    }
    printf("\n");

    return 0;
}

int update(void)
{
    int i, j;
    for (i = 1; i < N; i++)
    {
        if ((cell[i - 1] == 0) && (cell[i] == 0) && (cell[i + 1] = 0))
        {
            a[i] = 0;
        }
        if ((cell[i - 1] == 0) && (cell[i] == 0) && (cell[i + 1] = 1))
        {

            a[i] = 1;
        }
        if ((cell[i - 1] == 0) && (cell[i] == 1) && (cell[i + 1] = 0))
        {

            a[i] = 0;
        }
        if ((cell[i - 1] == 0) && (cell[i] == 1) && (cell[i + 1] = 1))
        {

            a[i] = 1;
        }
        if ((cell[i - 1] == 1) && (cell[i] == 0) && (cell[i + 1] = 0))
        {

            a[i] = 1;
        }
        if ((cell[i - 1] == 1) && (cell[i] == 0) && (cell[i + 1] = 1))
        {

            a[i] = 0;
        }
        if ((cell[i - 1] == 1) && (cell[i] == 1) && (cell[i + 1] = 0))
        {
            a[i] = 1;
        }
        if ((cell[i - 1] == 1) && (cell[i] == 1) && (cell[i + 1] = 1))
        {
            a[i] = 0;
        }
        if (i == 0 || i == N - 1)
        {
            a[i] = 0;
        }
    }
    for (j = 1; j <= N; j++)
    {
        cell[j] = a[j];
    }
}

int main(void)
{
    int i;
    init();
    dump();
    usleep(5000);
    for (i = 1; i < MAXGEN; i++)
    {
        update();
        dump();
        usleep(5000);
    }
}