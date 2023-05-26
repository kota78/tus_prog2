#include<stdio.h>
#include <stdlib.h>

double grand() {
    double a=0;
    int i;
    for(i=0;i<12;i++)
    {
        a+=(double)rand()/RAND_MAX;
    }
    a -=6;
    return a;
}

int main(void) {
    int i;
    double x, y;
    for(i=0;i<1000;i++) {
        x+=grand();
        y+=grand();
        printf("%f,", x);
        printf("%f\n", y);
    }
}