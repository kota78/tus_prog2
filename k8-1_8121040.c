#include <stdio.h>
#define MAX 10
int main(void)
{
    int Flag = 0;
    int array[MAX] = {17, 95, 59, 72, 6, 38, 11, 45, 68, 29};
    int i, Count = 0, tmp;
    do
    {
        Flag = 0;
        Count++;
        for (i = MAX - 1; i > 0; i--)
        {
            if (array[i - 1] > array[i])
            {
                tmp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = tmp;
                Flag = 1;
            }
        }
        printf("\n%d, ", Count);
        for (i = 0; i < MAX; i++)
        {
            printf("%d ", array[i]);
        }
    } while (Flag);
    return 0;
}