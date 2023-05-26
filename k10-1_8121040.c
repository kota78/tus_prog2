#include <stdio.h>
void init(int *data)
{
    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            *(data + 15 * i + j) = '+';
        }
        printf("\n");
    }

    return;
}
void dump(int *data)
{
    char RowIndex[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    int i, j;
    printf("  a b c d e f g h i j k l m n o\n");
    // 列(Column)のインデックスを表示
    // 先頭に空白2個，各インデックスの間は空白1個
    /* 各行の先頭に列(Row)の記号を表示。RowIndexを利用する。 */
    /* その後ろにBoard配列の対応する列の要素を表示する。 */
    for (i = 0; i < 15; i++)
    {
        printf("%c", RowIndex[i]);
        for (j = 0; j < 15; j++)
        {
            printf(" %c", *(data + 15 * i + j));
        }
        printf("\n");
    }
    return;
}
int main()
{
    char Board[15][15];
    init(Board); // Board配列を渡す
    dump(Board); // Board配列を渡す
    return 0;
}