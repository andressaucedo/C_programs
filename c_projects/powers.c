#include<stdio.h>

int power(int,int);

int main()
{
  int i, b, e;
  b=e=0;
printf("enter base: \n");
scanf("%3i", &b);
printf("enter exponent: \n");
scanf("%3i", &e);
putchar('\n');
  for (i = 1; i <= e; i++) {
    printf("%d\n", power(b,i));
  }
return 0;
}

//power: raise base to the n-th power
int power (int base, int n)
{
int i, answr;
answr=1;
  for (i=1; i<=n ; ++i){
    answr = answr * base;
  }
return answr;
}
