#include<stdio.h>
#define COL 4
void array_notation(int a[],int b[],int element);
void pointer_notation(int * a,int * b,int element);
void print_array(int *a, int element);

int main(void)
{
int foo[COL]={3,5,7,8};
int bar[COL];
int baz[COL];

   array_notation(foo,bar,COL);
   pointer_notation(foo,baz,COL);
   print_array(foo,COL);
   print_array(bar,COL);
   print_array(baz,COL);

return 0;
}

void array_notation(int a[],int b[],int element)
{
   for(int i = 0; i < element;i++)
      b[i]=a[i];
}

void pointer_notation(int * a,int * b,int element)
{

   for(int i = 0; i < element ;i++)
      *(b + i) = *(a + i);

}

void print_array(int *a, int element)
{
   for(int i=0; i<element; i++)
      printf("%d ",*(a + i));
   printf("\n");
}
