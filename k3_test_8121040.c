#include <stdio.h>
#include <string.h>

int main()
{
    char text[] = "PGPCJMZOJ SLD ELWPYE, MFE LMTWTEJ ELVPD SLCO HZCV.\n";
    int n, i, j;
    n = strlen(text);
    char a[n];
    for (i = 1; i < 26; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (text[j] >= 65 && text[j] <= 90)
            {
                if (text[j] + i > 90)
                {
                    a[j] = text[j] + i - 26;
                }
                else
                {
                    a[j] = text[j] + i;
                }
            }
            else
            {
                a[j] = text[j];
            }
        }
        printf("%s\n", a);
    }
    return 0;
}