#include<stdio.h>
#define ROW 4
#define COL 5
#define RANGE 3
#define INDEX 3


void array_notation(int a[][COL],int b[][COL], int rows, int cols);
void pointer_notation(int * a,int * b,int element);

int main(void)
{
   int foo[ROW][COL] = {
      {2,4,2,1,5},
      {3,32,5,2,5},
      {3,5,32,5,6},
      {6,7,4,2,6}
   };
   int one[RANGE];
   pointer_notation(*foo + (INDEX-1),one,RANGE);

   for(int i=0; i < RANGE; i++)
      printf("%d ", one[i]);
   printf("\n");

/*
   int bar[ROW][COL];
   array_notation(foo,bar,ROW,COL);
   for(int i= 0; i < ROW; i++){
      for(int j=0; j < COL; j++)
      printf("%d ", bar[i][j]);
   printf("\n");
   }
*/
}
void pointer_notation(int * a,int * b,int element)
{

   for(int i = 0; i < element ;i++)
      *(b + i) = *(a + i);

}

void array_notation(int a[][COL],int b[][COL], int rows, int cols)
{
   for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
         b[i][j] = a[i][j];
}
