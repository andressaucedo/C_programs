//power.c - raises numbers to integer powers
#include<stdio.h>
double power(double a ,int b);

int main(void)
{
	double x, xpow;
	int n;

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
	double pow =1;
	int i;
	int limit;
	if(a == 0)
		pow = 0;
	else if(b == 0)
		pow = 1;
	else if(b < 0)
		for(i = 1; i <= (b * -1); i++)
			pow /= a;
	else	
		for(i = 1; i <= b; i++)
			pow *= a;
	
	return pow;
}
