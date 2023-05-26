#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXGEN 100
#define MAXH 40
#define MAXW 40

static int cell[MAXH + 2][MAXW + 2] = {0};
static int stashCell[MAXH + 2][MAXW + 2] = {0};

void init(void)
{
    cell[17][21] = 1;
    cell[18][21] = 1;
    cell[19][21] = 1;
    cell[20][21] = 1;
    cell[21][21] = 1;
    cell[22][21] = 1;
    cell[23][21] = 1;
    cell[24][21] = 1;
    cell[25][21] = 1;
    cell[26][21] = 1;
}

void dump(void)
{
    int i, j;
    for (i = 1; i <= MAXH; i++)
    {
        for (j = 1; j <= MAXW; j++)
        {
            if (cell[i][j] == 0)
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
}

void update(void)
{
    int i, j;
    int c[MAXH + 2][MAXW + 2] = {0};

    for (i = 1; i <= MAXH; i++)
    {
        for (j = 1; j <= MAXW; j++)
        {
            c[i][j] = cell[i - 1][j - 1] + cell[i - 1][j] + cell[i - 1][j + 1] + cell[i][j - 1] + cell[i][j + 1] + cell[i + 1][j - 1] + cell[i + 1][j] + cell[i + 1][j + 1];
        }
    }
    for (i = 1; i <= MAXH; i++)
    {
        for (j = 1; j <= MAXW; j++)
        {
            if (cell[i][j] == 0 && c[i][j] == 3 || (cell[i][j] == 1 && (c[i][j] == 2 || c[i][j] == 3)))
            {
                stashCell[i][j] = 1;
            }
            else if (cell[i][j] == 1 && (c[i][j] <= 1 || c[i][j] >= 4))
            {
                stashCell[i][j] = 0;
            }
        }
    }
    for (i = 1; i <= MAXH; i++)
    {
        for (j = 1; j <= MAXW; j++)
        {
            cell[i][j] = stashCell[i][j];
        }
    }
}

int main(void)
{
    int k;
    system("clear");
    init();
    dump();
    usleep(100000);
    for (k = 1; k <= MAXGEN; k++)
    {
        update();
        system("clear");
        dump();
        usleep(100000);
    }
    return 0;
}