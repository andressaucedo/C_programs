#include<stdio.h>
#define ROW 3
#define COL 5


void print_array( int a[][COL], int x, int y);
void double_value(int *a, int x, int y);

int main(void)
{
   int foo[ROW][COL] = {
      {2,4,2,1,5},
      {3,32,5,2,5},
      {3,5,32,5,6}
   };

   print_array(foo,ROW,COL);
   double_value(*foo,ROW,COL);
   printf("\n");
   print_array(foo,ROW,COL);

return 0;
}

void print_array( int a[][COL], int x, int y)
{
   for(int i=0;i < x; i ++){
      for(int j = 0; j < y; j++)
         printf("%d ",a[i][j]);
      printf("\n");
   }
}

void double_value(int *a, int x, int y)
{
   for(int i = 0; i < (x*y); i++)
      *(a + i) *= 2;
}
