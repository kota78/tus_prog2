#include <stdio.h>

int main()
{
    char text[] = "MCI AWGG 100% CT HVS GVCHG MCI RCB'H HOYS.\n";
    char a[43];
    int n, i, j;
    n = 43;
    for (i = 1; i <= 26; ++i) //キーとなる数字を指定（1~26で全パターン試す）
    {
        for (j = 0; j < n; j++) // textを文頭から１文字ずつ調べていく
        {
            if (text[j] >= 65 && text[j] <= 90) // textのj番目がアルファベット大文字だったら
            {
                a[j] = ((text[j] - 65) + i) % 26 + 65;
                // textのj番目の文字がアルファベットの何番目か+(1~26の数字i)、
                //
            }
            else
            {
                a[j] = text[j]; // textのj番目がアルファベット大文字じゃなかったらそのまま
            }
        }
        printf("%s\n", a); //キーがiの場合の解読結果を出力
    }
    return 0;
}