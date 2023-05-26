#include <stdio.h>
#include <string.h>
#define MAXCHAR_F 22
#define MAXCHAR_W 22
#define MAXLINE 16
int main(void)
{
    char filename[MAXCHAR_F];
    char wrd[MAXLINE][MAXCHAR_W];
    int i, j, Count = 0;
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
    int n;
    do
    {
        printf("1(ascending order) or 2(descending order): ");
        scanf("%d", &n);
        scanf("%*c"); /* 残った改行を読み飛ばす処理。*/
        /* この処理を行わないと、次の文字入力に影響が出る。 */
    } while (n != 1 && n != 2);
    printf("%d\n", n); /* n を画面表示 */
    printf("\n");
    int Flag = 0;
    char tmp[MAXCHAR_W];
    do
    {
        Flag = 0;
        if (n == 1)
        {
            for (i = MAXLINE - 1; i > 0; i--)
            {
                if (strcmp(wrd[i - 1], wrd[i]) > 0)
                {
                    strcpy(tmp, wrd[i - 1]);
                    strcpy(wrd[i - 1], wrd[i]);
                    strcpy(wrd[i], tmp);
                    Flag = 1;
                }
            }
        }
        if (n == 2)
        {
            for (i = MAXLINE - 1; i < 0; i--)
            {
                if (strcmp(wrd[i - 1], wrd[i]) > 0)
                {
                    strcpy(tmp, wrd[i - 1]);
                    strcpy(wrd[i - 1], wrd[i]);
                    strcpy(wrd[i], tmp);
                    Flag = 1;
                }
            }
        }
    } while (Flag);
    /* 整数のソートを参考に考える。 */
    /* ソートの途中経過を画面出力する必要はない。 */
    // Display strings after sort
    printf("Strings after sort: \n");
    /* ソートの結果を画面に表示する。 */
    for (i = 0; i < MAXLINE; i++)
    {
        fgets(wrd[i], MAXCHAR_W, fp);
        printf("%s\n", wrd[i]);
    }
    printf("\n");
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
