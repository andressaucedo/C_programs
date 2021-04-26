//power.c - raises numbers to integer powers
#include<stdio.h>
double power(double a ,int b);

int main(void)
{
	double x, xpow, p;
	int n;
	p =1;

	printf("Enter a number and the integer power"
		"\nto which the number will be raised."
		"\nEnter q to quit.\n");
	while(scanf("%lf%d", &x, &n) == 2)
	{

		xpow = power(x,n);

		printf("%.3e to the power %d is %.3e\n",x,n,xpow);
	}
return 0;
}

double power(double a, int b)
{
	
	int i;
	
	if(a == 0)
		return 0;
	if(b == 0)
		return 1;
	if(b < 0)
		return 1 / power(a,-b);
	else
		return a * power(a,b-1);
}
