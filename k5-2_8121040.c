#include <stdio.h>
#define MAX 46

int fibo(int n)
{
    static int memo[MAX] = {0, 1, 1};
    if (memo[n] != 0)
        return memo[n];
    memo[n] = fibo(n - 1) + fibo(n - 2);
    return memo[n];
}

int main(void)
{
    int a, i;
    for (i = 1; i <= MAX; i++)
    {
        a = fibo(i);
        printf("%d\n", a);
    }
    return 0;
}