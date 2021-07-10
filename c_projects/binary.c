//binary.c -- prints integer in binary forms
#include<stdio.h>
void to_binary(int n);

int main(void)
{
	int number;

	while(scanf("%d", &number) == 1)
	{
		to_binary(number);
		putchar('\n');
	}
return 0;
}

void to_binary(int n)
{
	int r;

	r = n % 2; //odd numbers will return 1, even numbers return 0
	if (n >= 2)
		to_binary(n/2); //recursive call:n goes to the next value when divided by 2
	// so the recursive function would be n1=input; n2= (n1/2) % 2
	putchar('0' + r);
	return;
}
