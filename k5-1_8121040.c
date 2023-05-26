#include <stdio.h>
#define MAX 46

int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
    int a, i;
    for (i = 1; i <= MAX; i++)
    {
        a = fibo(i);
        printf("%d\n", a);
    }
}