#include <stdio.h>

int main(void)
{
    int i, j, a, score, credit, total_credit = 0, numer = 0;
    double gpa;
    printf("Number of courses?");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        printf("Score (course %d)?", i);
        scanf("%d", &score);
        printf("Credit (course %d)?", i);
        scanf("%d", &credit);
        numer += score * credit;
        total_credit += credit;
    }
    printf("GPA%lf", (double)numer / total_credit);
    return 0;
}