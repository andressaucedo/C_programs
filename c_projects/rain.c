// rain.c - finds yearly tots, yearly average and monthly average
//for several years of rainfall data.
#include<stdio.h>
#define MONTHS 12
#define YRS 5
float maxfind(float *a, int element);
float *indexfind(float *a, int element);
void yearly_rain(float array[][MONTHS], int months, int years);
void monthly_rain(float array[][MONTHS], int months, int years);

int main(void)
{
   //initializing rainfall data for 1990-1994
   float rain[YRS][MONTHS] = {
      {10.2,8.1,6.8,4.2,2.1,1.8,0.2,0.3,1.1,2.3,6.1,7.4},
      {9.2,9.8,4.4,3.3,2.2,0.8,0.4,0.0,0.6,1.7,4.3,5.2},
      {6.6,5.5,3.8,2.8,1.6,0.2,0.0,0.0,0.0,1.3,2.6,4.2},
      {4.3,4.3,4.3,3.0,2.0,1.0,0.2,0.2,0.4,2.4,3.5,6.6},
      {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.2}
   };
   float var;
   yearly_rain(rain,MONTHS,YRS);
   monthly_rain(rain,MONTHS,YRS);

   printf("\n");
   printf("The most rain in one month was %.1lf inches.\n",maxfind(*rain,(MONTHS*YRS)));

   // because array pointer in indexfind is a *float, the size for the address
   // should be %lx instead of %x and we cast the return as a long int
   printf("The address of value is: %lx \n",(long)indexfind(*rain,(MONTHS*YRS)));

   return 0;
}

//finds the greatest value in the array
float maxfind(float *a, int element)
{
   float maxval = *(a+0);

   for(int i = 0; i < element; i++){
      if(maxval >= *(a+i))
         i++;
      else
         maxval = *(a+i);
         i++;
   }
return maxval;
}

//finds the address where the greatest value is stored, returns address to float
float *indexfind(float *a, int element)
{
   float maxval = *a;
   float *address = a;
   for(int i = 0; i < element; i++){
      if(maxval >= *(a+i)){
         i++;
      }
      else{
         maxval = *(a + i);
         address = a + i;
         i++;
      }
   }
return address;
}

//finds average yearly rainfall
void yearly_rain(float array[][MONTHS], int months , int years)
{
   int i,j;
   float subtotal,total;

   printf("YEAR    RAINFALL (inches)\n");
   for(j = 0, total = 0; j < years; j++)
   {
      for(i= 0, subtotal = 0;i< months; i++)
         subtotal += array[j][i];
      printf("%5d %15.1f\n", 1990 + j, subtotal);
      total += subtotal;
   }
   printf("\nThe yearly average is %.1f inches.\n\n",total/years);

}

// calculates monthly rainfall averages
void monthly_rain(float array[][MONTHS], int months, int years)
{
   float subtotal,total;
   int i,j;

      printf("MONTHLY AVERAGES:\n\n");
      printf(" JAN  FEB  MAR  APR  MAY  JUN  JUL  AUG  SEP  OCT  NOV  DEC\n");
      for ( i = 0; i < months; i++)
      {
         for ( j = 0, subtotal = 0; j < years; j++){
            subtotal += array[j][i] ;
         }
         printf("%4.1f ",(subtotal/years));
      }
}
