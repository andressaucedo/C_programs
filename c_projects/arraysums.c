#include<stdio.h>
#define ROW 5
void arraysum(int *a,int *b, int *c, int size);
int main(void)
{
   int foo[ROW];
   int bar[ROW] = {1,2,3,4,5};
   int baz[ROW] = {2,3,4,5,6};

      arraysum(foo,bar,baz,ROW);

      for(int i = 0; i < ROW; i++)
         printf("%d ", *(foo + i));
      printf("\n");

return 0;
}

void arraysum(int *a,int *b, int *c, int size)
{
   for(int i=0; i < size;i++)
   *(a + i) = (*(b + i) + *(c + i));
}
