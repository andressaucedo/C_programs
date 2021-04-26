#include<stdio.h>

int main()
{
	float weight,value;
	char beep;

	beep='\7';

	printf("Are you worth your weight in gold?\n");
	printf("Please enter your weight in pounds, ");
	printf("and we'll see.\n");
	scanf("%f", &weight);

	value = 400.0 * weight * 14.5833;
	printf("%cYour weight in gold is worth $%.2f%c. \n",beep, value,beep );
	printf("You are easily worth that, if gold prices drop, ");
	printf("eat more\nto maintain your value.\n");

return 0;
}
