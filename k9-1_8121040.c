#include <stdio.h>
#include <string.h>
#define MAXCHAR_F 22
#define MAXCHAR_W 22
#define MAXLINE 16
int main(void)
{
    char filename[MAXCHAR_F];
    char wrd[MAXLINE][MAXCHAR_W];
    int i, j;
    FILE *fp;
    printf("Input file name:");
    fgets(filename, MAXCHAR_F, stdin);
    filename[strlen(filename) - 1] = '\0';
    printf("%s\n", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("The input file cannot be opened!\n");
        return -1;
    }
    else
    {
        for (i = 0; i < MAXLINE; i++)
        {
            fgets(wrd[i], MAXCHAR_W, fp);
            wrd[i][strlen(wrd[i]) - 1] = '\0';
            printf("%s\n", wrd[i]);
                }
    }
    fclose(fp);
    printf("Strings before sort:\n");
    printf("Output file name: words4sort1.txt");
    fp = fopen("words4sort1.txt", "w");
    for (i = 0; i < MAXLINE; i++)
    {
        fprintf(fp, "%s\n", wrd[i]);
    }
    fclose(fp);
    printf("\n");
    printf("Finish!\n");
    return 0;
}