//this program squares and cubes the range of user inputs
#include<stdio.h>

int main()
{
   int i,j,k;    //control variables
   int upper,lower; //user input variables
   int multiple;

   printf("Enter lower limit:");
   scanf("%d",&lower);
   printf("Enter upper limit:");
   scanf("%d",&upper);



      for(j=0; lower <= upper; j++, lower++){
         printf("%d ",lower);
         printf("%d ",multiple = lower*lower);
         printf("%d\n",multiple = lower*lower*lower);
      }

   printf("\n");

return 0;
}
