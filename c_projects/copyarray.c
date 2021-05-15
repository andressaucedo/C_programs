#include<stdio.h>
#define ROW 3
#define COL 4
void array_notation(int a[][COL],int b[][COL], int rows, int cols);
void pointer_notation(int *a,int *b, int rows, int cols);
void print_array(int a[ROW][COL]);

int main(void)
{
int foo[ROW][COL] = {
   {3,2,3,2},
   {1,5,3,2},
   {5,5,6,6}
};
int bar[ROW][COL];
int baz[ROW][COL];


   array_notation(foo,bar,ROW,COL);
   pointer_notation(*foo,*baz,ROW,COL);
   print_array(foo);
   print_array(bar);
   print_array(baz);


return 0;
}
//copy array 'a' to array 'b' using array notation
void array_notation(int a[][COL],int b[][COL], int rows, int cols)
{
   for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
         b[i][j] = a[i][j];
}
//copy array 'a' to array 'b' using pointer notation
void pointer_notation(int *a,int *b, int rows, int cols)
{
      for(int j=0;j<(rows * cols);j++)
         *(b + j) = *(a + j);
}

void print_array(int a[ROW][COL])
{
   for(int i = 0; i < ROW; i++){
      for(int j = 0; j < COL; j++)
         printf("%d ",a[i][j]);
      printf("\n");
   }
   printf("\n");
}
