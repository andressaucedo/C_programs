// worktime.c - simple calculation for weekly income after taxes.
#include<stdio.h>
#define TAX_1 0.15
#define TAX_2 0.20
#define TAX_3 0.25
#define OVERTIME 40
#define PAY1 10.00
#define PAY2 15.00
#define PAY3 20.00
#define PAY4 25.00


int main(void)
{
	float gross_income, net_income, taxes_due;
	float hourly_pay, adjusted_pay;
	float hours, regular_hours, overtime_hours;
	float overtime_income = 0;
	int menuchoice;

	do{
	printf("Enter the amount of hours worked for the week:\n");
	scanf("%f",&hours);
//	printf("Enter the hourly pay rate in dollars and cents:\n");
//	scanf("%f",&hourly_pay);

	printf("Please choose the hourly rate:\n"
	"*************************************\n"
	"*1. $10.00/hr           3. $20.00/hr*\n"
	"*2. $15.00/hr           4. $25.00/hr*\n"
	"*                       5. QUIT     *\n"
	"*************************************\n");
	printf("Type the number of your choice from the list and press Enter: ");
	scanf("%d",&menuchoice);

	switch(menuchoice)
	{
		case 1:
			hourly_pay = PAY1;
			break;
		case 2: 
			hourly_pay = PAY2;
			break;
		case 3:
			hourly_pay = PAY3;
			break;
		case 4:
			hourly_pay = PAY4;
			break;
		case 5:
			goto END;
		default:
			printf("Error: incorrect value.\n");
			printf("Type 1 to continue, q to quit.\n");
			continue;
	}


	if(hours > OVERTIME){	//this block adjusts the payrate for overtime
		overtime_hours = hours - OVERTIME;
		adjusted_pay = hourly_pay * 1.5;
		overtime_income = overtime_hours * adjusted_pay;
		regular_hours = hours - overtime_hours;
	}
	else{
		regular_hours = hours;
		overtime_income = overtime_hours = 0;
	}

	gross_income = overtime_income + (hourly_pay * regular_hours); //calculated weekly income before tax
	
	if(gross_income <= 300.00) //calculate taxes due with the appropriate tax bracket
		taxes_due = gross_income * TAX_1;
	else if(gross_income > 300.00 && gross_income <= 450.00)
		taxes_due = gross_income * TAX_2;
	else
		taxes_due = gross_income * TAX_3;
	
	net_income = gross_income - taxes_due; //final calculation for net income

	printf("\nYour net income after taxes for %.2f hours \n"
		"at an hourly rate of $%.2f/hr. with %.1f hours"
		" overtime is: $%.2f\n\n", hours, hourly_pay,overtime_hours, net_income);
	printf("Type 1 to continue, q to quit.\n");
	}while((scanf("%f",&hours)) > 0);
END:	
return 0;
}
