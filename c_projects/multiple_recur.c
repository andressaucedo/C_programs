#include<stdio.h>
int recur(int base, int factor);
int *base_copy;
int main(void)
{
	int multiple, factor;

	printf("Enter number to find multiples of and the factor:\n");
	while(scanf("%d %d", &multiple,&factor) == 2 ){
		base_copy = &multiple;
	  printf("\n\n%d\n\n",recur(multiple,factor));
	}
	return 0;
}

int recur(int base, int factor)
{
	int num;
	if( factor >= 1)
	{
		
		printf("%d %d %d\n",base,factor,num);		
	num = 1 + recur(base + *base_copy, factor - 1);
		printf("%d %d %d\n",base,factor,num);		
		return num;
	}
	
}
