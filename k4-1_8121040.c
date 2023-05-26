#include <stdio.h>
#include <unistd.h>

int is_fizz(int n)
{
    if (n % 3 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_buzz(int n)
{
    if (n % 5 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, i, fizz, buzz;
    printf("Input number:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sleep(1);
        fizz = is_fizz(i);
        buzz = is_buzz(i);
        if (fizz == 1 && buzz == 1)
        {
            printf("FIzz Buzz\n");
        }
        else if (fizz == 1)
        {
            printf("Fizz\n");
        }
        else if (buzz == 1)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }
    return 0;
}