//wheat.c -exponential growth app
#include<stdio.h>
#define SQUARES 64  //squares on a checkerboard
#define CROP 9E14 //US wheat crop in grains

int main(void)
{
   double current, total;
   int count = 1;

   printf("square   grains added   total grains   ");
   printf("fraction of \n");
   printf("                                       ");
   printf("US total\n");
   total = current = 1.0;
   printf("%4d %15.2e %13.2e %13.2e\n", count,current,total,(total/CROP));
   while(count < SQUARES){
      count += 1;
      current *= 2.0;
      total += current; //update total
      printf("%4d %15.2e %13.2e %13.2e\n",count,current,total,(total/CROP));
   }
   return 0;
}
