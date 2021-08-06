#include<stdio.h>
void printarray(int (*foo)[3], int row, int col);

int main(void)
{
   int array[2][3] = {4,2,7,5,9,6};

   printarray(array,2,3);
   printf("\n");
return 0;
}

void printarray(int (*foo)[3], int row, int col)
{
   for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++)
         printf("%d ", *(*(foo + i) + j) ) ;
      printf("\n");
   }
}
