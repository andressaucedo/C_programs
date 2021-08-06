//basenum.c -- this program converts a decimal base integer to a given base (2-10) and displays it
#include<stdio.h>
void to_base(int n, int base);

int main(void)
{
	int number,base;
	printf("This program converts regular decimal base integers to another base.\n");
	printf("Enter a whole number and base (2-10) please:\n");
	while(scanf("%d %d", &number,&base) == 2)
	{
		to_base(number,base);
		putchar('\n');
	}
return 0;
}

void to_base(int n, int base)
{
	int r;

	r = n % base; //finds remainder of n / base
	if (n >= base)
		to_base(n/base,base); //recursive call: n goes to the next value when divided by base
	//each number place to the left is equal to base *= base
	putchar('0' + r);
	return;
}
