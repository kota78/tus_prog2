#include <stdio.h>
#define MAX 15
int main(void)
{
    int Flag = 0;
    int array[MAX] = {};
    int i, Count = 0, tmp;
    FILE *file;
    file = fopen("int4sort.txt", "r");
    for (i = 0; i < MAX; i++)
    {
        if (file == NULL)
        {
            printf("The file cannot be opened!\n");
            return -1;
        }
        else
        {
            fscanf(file, "%d", &array[i]);
        }
    }
    printf("%d\n", i);
    do
    {
        Flag = 0;
        Count++;
        for (i = MAX - 1; i > 0; i--)
        {
            if (array[i - 1] < array[i])
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
    fclose(file);
    return 0;
}