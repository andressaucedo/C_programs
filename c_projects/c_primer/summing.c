//summing.c- adds up integers until the program is escaped and returns sum
#include<stdio.h>

int main()
{
int c;
long num;
long sum = 0;
printf("Enter an integer value (q to quit): \n    ");
   while(scanf("%ld",&num) != 0)
   {
      printf("+ %ld = ",sum);
      sum += num;
      printf("%ld \n",sum);
   }

   return 0;
}
