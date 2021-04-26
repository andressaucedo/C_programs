/* repoint.c - This program illustrates how pointers and recursion work.*/
#include<stdio.h>
void convert(int *lorem, int *ipsum, int *dolor);
int increment(int count);

int main()
{
	//variable names are just labels to help us reference the values at that memory location
	int a, b ,c;
	a=1;
	b=2;
	c=3;

	printf("The values before conversion are a=%d, b=%d, c=%d\n",a,b,c);
	convert(&a,&b,&c); //We send the addresses of the values to the function
	printf("\nThe values after conversion are a=%d, b=%d, c=%d\n",a,b,c);

return 0;
}

void convert( int *lorem, int *ipsum, int *dolor)
{
	int num = 1;

   /* The unary * operator makes lorem,ipsum and dolor indirect or dereferencing variables that point back to the memory address which contains the true value we are manipulating. The variables a,b,c in main() are just abstractions or labels we attach to the value in that memory address so we don't have to remember the actual name of that address in hexadecimal.*/

   printf("\nfor *lorem += num which points to &a\n");
   *lorem += increment(num);
   printf("\nfor *ipsum += num which points to &b\n");
   *ipsum += increment(num);
   printf("\nfor *dolor += num which points to &c\n");
   *dolor += increment(num);

}

int increment(int count)
{
   /*statements before the recursive call stack on to each other,
   while statements after the recursive call work their way back through the stack until it reaches the original call*/
	if(count < 4){
      printf("recursion pass #%d num equals: %d\n",count, count);
     return increment(count + 1); //recursive call
  }
   else
   printf("recursion pass #%d num equals: %d\n",count, count);
   return count;

}
