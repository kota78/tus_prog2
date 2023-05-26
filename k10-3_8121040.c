#include <stdio.h>
void init(char *data)
{
    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            *(data + 15 * i + j) = '+';
        }
    }
    printf("\n");
    return;
}

void dump(char *data)
{
    char RowIndex[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    int i, j;
    printf("  a b c d e f g h i j k l m n o\n");
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

int input_stone(int Turn, int *pRow, int *pColumn)
{
    char input[4];
    if (Turn == 0)
    {
        printf("sente(@)>");
    }
    if (Turn == 1)
    {
        printf("gote(O)>");
    }
    fgets(input, 4, stdin);
    if (input[0] <= 'A' && input[0] >= 'O')
    {
        return 1;
    }
    if (input[1] <= 'a' && input[1] >= 'o')
    {
        return 1;
    }
    *pRow = input[0] - 65;
    // キー入力の 1 文字目を 0 ~14 に変換。 *pRow に代入。
    *pColumn = input[1] - 97;
    // キー入力の２文字目を 0 ~14 に変換。 *pColumn に代入。
    return 0;
}
int place_stone(int Turn, int Row, int Column, char Board[15][15])
{
    if (Board[Row][Column] == '+')
    {
        if (Turn == 0)
        // Board[Row][Column]が’+’であれば、先手・後手(Turn)に応じて、
        {
            Board[Row][Column] = '@';
            return 0;
        }
        else
        {
            Board[Row][Column] = '0';
            return 0;
        }
        // Board[Row][Column]を'@'、もしくは'O'で書き換え、0 を返す。
    }
    else
    {
        return 1;
    }
    // Board[Row][Column]が’+’でなく、既に石が置かれているのであれば、1 を返す。
}

int judge(int Row, int Column, char Board[15][15])
{
    int i, LineLen = 0;
    char c = Board[Row][Column]; // 最後に置かれた石。
    // 縦方向の判定（ここからスタート）
    LineLen = 0; // LineLen で連続した石の数をカウントする。
    /* 最後に置いた石よりも碁盤の上側をチェックする。*/
    i = 1;
    while (Row - i >= 0)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row - i][Column] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    /* 最後に置いた石よりも碁盤の下側をチェックする。 */
    i = 1;
    while (Row + i <= 14)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row + i][Column] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    if (LineLen >= 4)
    {
        return 1;
    }
    // 横
    LineLen = 0;
    i = 1;
    while (Column - i >= 0)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row][Column - i] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    /* 最後に置いた石よりも碁盤の下側をチェックする。 */
    i = 1;
    while (Column + i <= 14)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row][Column + i] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    if (LineLen >= 4)
    {
        return 1;
    }

    LineLen = 0;
    i = 1;
    while (Column - i >= 0 && Row - i >= 0)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row - i][Column - i] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    /* 最後に置いた石よりも碁盤の下側をチェックする。 */
    i = 1;
    while (Column + i <= 14 && Row + i <= 14)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row + i][Column + i] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    if (LineLen >= 4)
    {
        return 1;
    }

    // 右斜め
    LineLen = 0;
    i = 1;
    while (Column - i >= 0 && Row + i <= 14)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row + i][Column - i] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    /* 最後に置いた石よりも碁盤の下側をチェックする。 */
    i = 1;
    while (Column + i <= 14 && Row - i >= 0)
    { // 碁盤をはみ出ないようにループを回す。
        if (Board[Row - i][Column + i] == c)
        {
            LineLen++;
            i++;
        }
        else
        {
            break;
        }
    }
    if (LineLen >= 4)
    {
        return 1;
    }

    /* 上記の「縦方向」の判定を参考に */
    /*「横方向」、「斜め右方向」、「斜め左方向」の判定も追加する */
    return 0;
}

int main()
{
    int Input, Place, Turn = 0, Row, Column;
    int Judgement;
    char Board[15][15];
    printf("1-%d", Turn);
    init(Board);
    dump(Board);

    while (1)
    {
        Input = input_stone(Turn, &Row, &Column);
        if (Input == 0)
        {
            Place = place_stone(Turn, Row, Column, Board);
            if (Place == 0)
            {
                dump(Board);
                Judgement = judge(Row, Column, Board);
                if (Judgement == 1)
                {
                    if (Turn == 0)
                    {
                        printf(">Winner: sente(@) ");
                        return 0;
                    }
                    else
                    {
                        printf(">Winner: gote(O)");
                        return 0;
                    }
                }
                Turn = 1 - Turn;
            }
        }
    }
    return 0;
}