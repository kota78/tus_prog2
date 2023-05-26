#include <stdio.h>
#define MAX 46

int main(void) {
 int i, fibo[MAX]={0,1,1};
 for(i=1; i<=MAX; i++) {
  if(i>2) fibo[i]=fibo[i-1]+fibo[i-2];
  printf("%d\n", fibo[i]);
  }
  return 0;
 }