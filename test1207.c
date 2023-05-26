#include <stdio.h>

int main(void)
{
    char input[4];
    fgets(input, 4, stdin);
    printf("%s", input);
}