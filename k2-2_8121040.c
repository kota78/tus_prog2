#include <stdio.h>
#define N 100000
int main(void)
{
    int i, j;
    int flag[N + 1] = {0};
    for (i = 2; i <= N; i++)
    {
        if (flag[i] == 0)
        {
            for (j = i + 1; j <= N; j++)
            {
                if (j % i == 0)
                {
                    flag[j] = 1;
                }
            }
        }
    }
    for (i = 2; i <= N; i++)
    {
        if (flag[i] == 0)
            printf("%d,", i);
    }
    return 0;
}