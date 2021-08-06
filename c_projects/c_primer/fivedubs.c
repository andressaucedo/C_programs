/* fivedubs.c - fill an array of 3x5 doubles and find set average, total
average and the maximum value in the array*/
#include<stdio.h>
#define ROWS 3
#define COLS 5
void getnums(double items[][COLS]);
void set_average(double items[][COLS], int rows, int cols);
double total_average(double items[][COLS], int rows, int cols);
double maxvalue(double *items, int rows, int cols);
void print_array(double items[][COLS], int rows, int cols);

int main(void)
{
   double my_array[ROWS][COLS];

   printf("We will be entering 3 sets of 5 numbers.\n");

   getnums(my_array);
   printf("\n");
   print_array(my_array,ROWS,COLS);
   printf("\n");
   set_average(my_array,ROWS,COLS);
   printf("\nTOTAL Average = %-.2lf\n", total_average(my_array,ROWS,COLS));
   printf("\nGreatest Value in list = %-.2lf\n", maxvalue(*my_array,ROWS,COLS));

return 0;
}

// This function retrieves the input
void getnums(double items[][COLS])
{
   for(int j=0; j < ROWS; j++){
      printf("Enter a set of 5 decimal numbers:\n");
      for(int i=0; i < COLS; i++)
            scanf("%lf", &items[j][i]);
   }
}

// This function gets the average for the individual sets(rows) of numbers
void set_average(double items[][COLS], int rows, int cols)
{
   double subtotal;
   double average;
   for(int i = 0; i < rows; i++){
      subtotal = 0.0;
      average= 0.0;
      for(int j=0; j < cols; j++){
         subtotal += items[i][j];
         average = (subtotal/(double)cols);
      }
      printf("SET %d Average = %-.2lf\n",i+1,average);
   }
}

// This function finds the average of all the values in the array
double total_average(double items[][COLS], int rows, int cols)
{
   double subtotal = 0.0;
   double average= 0.0;
   for(int i = 0; i < (rows * cols); i++){
      subtotal += *(*items + i);
      }

   average = (subtotal/(rows*cols));
return average;
}

// This function finds the largest value in the array
double maxvalue( double *items, int rows, int cols)
{
   double highest = *(items + 0);
   for(int i = 0; i < (rows*cols); i++){
      if( highest > *(items + i))
         continue;
      else
      highest = *(items + i);
   }

   return highest;
}

// This function prints an array of doubles
void print_array(double items[][COLS], int rows, int cols)
{
   for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++)
         printf("%7.2lf ", items[i][j]);
      printf("\n");
   }
}
