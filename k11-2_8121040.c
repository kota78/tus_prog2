#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NMAX 10000

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

int main(){
    int i, j;
    double x[NMAX] = {0}, y[NMAX] = {0}, mpx=0, mpy=0, msd=0;
    printf("%d, %f, %f, %f\n", 0, 0.0, 0.0, 0.0);
    for(j=0; j<1000; j++){
        for(i=0; i<NMAX; i++){
            x[i] += grand();
            y[i] += grand();
        }

        mpx = 0.0;
        mpy = 0.0;
        msd = 0.0;

        for(i=1; i<=NMAX; i++){
            mpx += x[i];
            mpy += y[i];
            msd += pow(x[i], 2.0) + pow(y[i], 2.0);
        }
        mpx /= NMAX;
        mpy /= NMAX;
        msd /= NMAX;
        printf("%d, %f, %f, %f\n", j, mpx, mpy, msd);
    }
    return 0;
}