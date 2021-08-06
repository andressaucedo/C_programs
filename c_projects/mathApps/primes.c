//primes.c - lists all prime numbers up to our input number.
#include<stdio.h>
#define NOT_PRIME 0
#define PRIME 1

int main(void)
{
   int input,count,test;
   int flag; //boolean variable to help us find primes
   printf("Enter an integer, or q to quit.\n"
   "I will find all primes up to this number: ");
   //loop will continue while scanf returns a value of 1
   while((scanf("%d",&input))){

         //this loop counts up to our input number (1 by definition isn't prime)
         for(count=2; count <= input; count++){
            flag = PRIME; //assume flag is true (count is PRIME) before test
            //this loop tests each number from count and returns PRIME/NOT_PRIME
            for (test=2;test < count; test++){
               if(count % test == 0)
                  flag = NOT_PRIME;
            }
            if(flag == PRIME)
               printf("%d ",count);
         }
         printf("\n\nEnter an integer, or q to quit.\n"
         "I will find all primes up to this number: ");
   }

return 0;
}
