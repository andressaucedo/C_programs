#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 81
#define LIM 20
//#define HALT "quit\n"
#define ZERO "\n"
void stringsort(char *strings[], int num);

int main(void)
{
   static char input[LIM][SIZE]; //input array
   char *pointersort[LIM]; //pointer array to point to input lines
   int ct = 0;
   int k;

   printf("Input up to %d lines and I will sort them.\n", LIM);
   printf("To stop, just press Enter.\n");

   while(ct < LIM && fgets(input[ct], SIZE, stdin) != NULL && strcmp(input[ct],ZERO) != 0)
   {
      input[ct][strcspn(input[ct],"\n")] = '\0';
      pointersort[ct] = input[ct];
      ct++;
   }
   input[ct][strcspn(input[ct],"\n")] = '\0';

   //stringsort uses pointers to sort lines without affecting input
   //the limit is set to the last number of lines count
   stringsort(pointersort, ct);

   puts("Here's the sorted list:");
   for(k = 0; k < ct; k++)
      puts(pointersort[k]); //sorted pointers
   return 0;
}

//string sorting function using pointers
void stringsort(char *strings[], int num)
{
   char *temp;
   int top, seek;
/*if strcmp(top,seek) returns a positive integer it means that top comes after seek in the machine collating sequence (ASCII) so we swap the two values in the pointer array */
   for(top = 0 ; top < num -1; top++)
      for(seek = top + 1; seek < num; seek++)
         if(strcmp(strings[top], strings[seek]) > 0)
         {
            temp = strings[top];
            strings[top] = strings[seek];
            strings[seek]=temp;
         }
}
