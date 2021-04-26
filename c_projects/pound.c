#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pound(int n);

int main(void)
{
      int times = 5;
      char ch ='!';  //ASCII code 33
      float f = 6.0;

      pound(times); //int argument
      pound(ch);
      pound((int) f);
   return 0;
}

void pound(int n)
{
   while(n-- > 0){
      printf("#");
   }printf("\n");
}
