#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXT 7
#define N 31

int cell[N] = {0};
void init()
{
    int i;
    cell[N / 2] = 1;
}

void dump()
{
    int j;
    for (j = 0; j < N; j++)
    {
        if (cell[j] == 0)
        {
            printf(".");
        }
        else
        {
            printf("@");
        }
    }
    printf("\n");
}

void update()
{
    int c[N], i, j;
    for (j = 0; j <= N; j++)
    {
        c[j] = cell[j];
    }
    for (i = 0; i <= N; i++)
    {
        if (c[i - 1] == 0 && c[i] == 0 && c[i + 1] == 0)
        {
            cell[i] = 0;
        }
        if (c[i - 1] == 0 && c[i] == 0 && c[i + 1] == 1)
        {
            cell[i] = 1;
        }
        if (c[i - 1] == 0 && c[i] == 1 && c[i + 1] == 0)
        {
            cell[i] = 0;
        }
        if (c[i - 1] == 0 && c[i] == 1 && c[i + 1] == 1)
        {
            cell[i] = 1;
        }
        if (c[i - 1] == 1 && c[i] == 0 && c[i + 1] == 0)
        {
            cell[i] = 1;
        }
        if (c[i - 1] == 1 && c[i] == 0 && c[i + 1] == 1)
        {
            cell[i] = 0;
        }
        if (c[i - 1] == 1 && c[i] == 1 && c[i + 1] == 0)
        {
            cell[i] = 1;
        }
        if (c[i - 1] == 1 && c[i] == 1 && c[i + 1] == 1)
        {
            cell[i] = 0;
        }
    }
    return;
}

int main()
{
    int t;

    system("clear");
    init();
    dump();
    usleep(1000);
    for (t = 1; t <= MAXT; t++)
    {
        update();
        dump();
        usleep(1000);
    }
    return 0;
}