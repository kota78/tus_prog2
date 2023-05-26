#include <stdio.h>
#include <stdlib.h>

#define GENERATIONS (7)
#define HEIGHT (40)
#define WIDTH (40)

#define DEAD (0)
#define ALIVE (1)

int cell[HEIGHT][WIDTH] = {DEAD};

void init()
{
    cell[15][WIDTH / 2] = ALIVE;
    cell[16][WIDTH / 2] = ALIVE;
    cell[17][WIDTH / 2] = ALIVE;
    cell[18][WIDTH / 2] = ALIVE;
    cell[19][WIDTH / 2] = ALIVE;
    cell[20][WIDTH / 2] = ALIVE;
    cell[21][WIDTH / 2] = ALIVE;
    cell[22][WIDTH / 2] = ALIVE;
    cell[23][WIDTH / 2] = ALIVE;
    cell[24][WIDTH / 2] = ALIVE;
}

void dump()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf(cell[y][x] == DEAD ? "." : "@");
        }
        printf("\n");
    }
}

void generate()
{
    int next[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int count = 0;
            if (y > 0 && cell[y - 1][x] == ALIVE)
                count++;
            if (y < HEIGHT - 1 && cell[y + 1][x] == ALIVE)
                count++;
            if (x > 0 && cell[y][x - 1] == ALIVE)
                count++;
            if (x < WIDTH - 1 && cell[y][x + 1] == ALIVE)
                count++;
            if (y > 0 && x > 0 && cell[y - 1][x - 1] == ALIVE)
                count++;
            if (y > 0 && x < WIDTH - 1 && cell[y - 1][x + 1] == ALIVE)
                count++;
            if (y < HEIGHT - 1 && x > 0 && cell[y + 1][x - 1] == ALIVE)
                count++;
            if (y < HEIGHT - 1 && x < WIDTH - 1 && cell[y + 1][x + 1] == ALIVE)
                count++;

            if (cell[y][x] == DEAD)
            {
                next[y][x] = count == 3 ? ALIVE : DEAD;
            }
            else
            {
                next[y][x] = count == 2 || count == 3 ? ALIVE : DEAD;
            }
        }
    }
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            cell[y][x] = next[y][x];
        }
    }
}

int main()
{
    system("clear");
    init();
    dump();
    system("sleep 0.1s");

    for (int generation = 1; generation <= GENERATIONS; generation++)
    {
        generate();
        system("clear");
        dump();
        system("sleep 0.1s");
    }
    return 0;
}