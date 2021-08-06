//simple_recursion.c - shows a simple loop done recursively
#include<stdio.h>
int addnum( int a);

int main(void)
{
	int a;
	printf("a is %d\n",addnum(a));
return 0;
}

int addnum(int a)
{
	if(a == 10)
	return a;

	printf("%d\n",a);
	addnum(a+=1);
}
