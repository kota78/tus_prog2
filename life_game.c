#include <stdio.h>
#include <stdlib.h>

struct Cell
{
    int status;
    int surroundstatus;
    int generation;
    int nextstatus;
};

void initCells(struct Cell *c, int w, int h);
void showCells(struct Cell *c, int w, int h);
void updateGeneration(struct Cell *c, int w, int h);
int countsurround(struct Cell *c, int w, int h, int locx, int locy);
int getStatus(struct Cell *c, int w, int h, int locx, int locy);

int main(int argc, char *argv[])
{
    int matx, maty;
    int n;
    int gen;
    struct Cell *cells;

    matx = atoi(argv[1]);
    maty = atoi(argv[2]);
    n = matx * maty;
    srand(atoi(argv[4]));

    cells = (struct Cell *)malloc(n * sizeof(struct Cell));

    initCells(cells, matx, maty);
    showCells(cells, matx, maty);

    for (gen = 0; gen < atoi(argv[3]); gen++)
    {
        updateGeneration(cells, matx, maty);
        showCells(cells, matx, maty);
        getchar();
    }
}

void updateGeneration(struct Cell *c, int w, int h)
{
    int i, j;
    int status;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            c[i * w + j].surroundstatus = countSurround(c, w, h, j, i);
        }
    }
    for (i = 0; i < w * h; i++)
    {
        switch (c[i].surroundstatus)
        {
        case 2:
            status = 1;
            break;
        case 3:
            status = 2;
            break;
        default:
            status = 0;
            break;
        }
        c[i].nextstatus = status;
    }

    for (i = 0; i < w * h; i++)
    {
        c[i].generation++;
        if (c[i].nextstatus == 0)
        {
            c[i].status = 0;
        }
        if (c[i].nextstatus == 2)
        {
            c[i].status = 1;
        }
    }
}

int countSurround(struct Cell *c, int w, int h, int locx, int locy)
{
    int cnt = 0;

    cnt += getStatus(c, w, h, locx - 1, locy);
    cnt += getStatus(c, w, h, locx + 1, locy);
    cnt += getStatus(c, w, h, locx, locy - 1);
    cnt += getStatus(c, w, h, locx, locy + 1);

    cnt += getStatus(c, w, h, locx - 1, locy - 1);
    cnt += getStatus(c, w, h, locx - 1, locy + 1);
    cnt += getStatus(c, w, h, locx + 1, locy - 1);
    cnt += getStatus(c, w, h, locx + 1, locy + 1);

    return cnt;
}

int getStatus(struct Cell *c, int w, int h, int locx, int locy)

{
    if (locx < 0 || locx >= w || locy < 0 || locy >= h)
    {
        return 0;
    }
    else
    {
        return c[locy * w + locx].status;
    }
}

void showCells(struct Cell *c, int w, int h)
{
    int i, j;
    printf("====The generation: %d ====\n", c[0].generation);
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (c[i * w + j].status == 0)
            {
                printf("-");
            }
            if (c[i * w + j].status == 1)
            {
                printf("o");
            }
        }
        printf("\n");
    }
}

void initCells(struct Cell *c, int w, int h)
{
    int i, j;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            c[i * w + j].status = rand() % 2;
            c[i * w + j].surroundstatus = 0;
            c[i * w + j].generation = 0;
            c[i * w + j].nextstatus = -1;
        }
    }
}