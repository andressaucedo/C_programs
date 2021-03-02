#include<stdio.h>

int power(int m, int n);


//this is a sample program that calculates integers
//to the power of 10
main() {
  int i;
  int bs;
  bs = 0;
  printf("Please enter a base number:\n");
  bs = getchar();
  for (i= 1; i < 10; ++i)
    printf ("%d %d\n", i, power(bs,i));

  return 0;

}
int power(int base, int n){
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;
  return p;
}
