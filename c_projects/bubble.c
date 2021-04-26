//bubble.c - This program illustrates how a bubble sort works.
#include<stdio.h>
#define LENGTH 10

int main(void)
{
int a,b,c,sorted,i;
int sample[LENGTH] = {2,1,3,6,5,4,7,8,10,9};
sorted=0;
int counter = 0;
printf("     Unsorted array: ");
for(i=0;i < LENGTH;i++)
   printf("%3d", sample[i]);
putchar('\n');

   for(i=0; i < LENGTH && sorted == 0; i++){ //control loop for number of passes to sort
      a=0; //index
      b=1; //index + 1 (both reset after each pass)
      sorted = 1; //set to true,if it remains true then signals loop to end
      counter++; //count number of passes
      while(b < LENGTH){
         if(sample[a] < sample[b]){
            a++;b++;
         }
         else if(sample[a] > sample[b]){
            c = sample[a]; //placeholder copies first element
            sample[a] = sample[b]; //move second element to first place
            sample[b] = c; //copy former first element into second place
            a++;b++;
            sorted = 0; //mark as false after substitution
         }
      }
  }

printf("Bubble sorted array: ");
for(i=0;i<LENGTH;i++)
   printf("%3d", sample[i]);
printf("\nSorted in %d passes\n",counter);

   return 0;
}
