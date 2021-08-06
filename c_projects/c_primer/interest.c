/*this program calculates how many years it takes to recoup an investment
  with annual simple and annual compound interest*/

#include<stdio.h>
#include<string.h>
#define S_INTEREST 0.10
#define C_INTEREST 0.05
float simple(float initial);
float compound(float initial);

int main()
{
   float initial;
   printf("Enter the amount of investment: ");
   scanf("%f",&initial);

   printf("Your initial investment of %.2f at %.2f simple interest takes %.1f years to recoup.\n",initial,S_INTEREST,simple(initial));
   printf("Your initial investment of %.2f at %.2f compound interest takes %.1f years to recoup.\n",initial,C_INTEREST,compound(initial));

return 0;
}
/*function to calculate simple interest*/
float simple(float initial)
{
float interest,intb,years;
int i;

   interest = S_INTEREST * initial; /* calculates the interest for 1 year*/
   intb = interest;
   for(years=1;interest < initial;years++) /* adds interest until >= investment*/
      interest += intb; /*recalculates interest*/

return years;
}
/*function to calculate compound interest*/
float compound(float initial)
{
float interest,intb,years,investment;
int i;
investment = initial;

   investment = (1 + C_INTEREST) * initial;
   for(years=1;interest < initial; years++){ /*adds compounded interest*/
      investment *= (C_INTEREST + 1);
      interest = investment - initial;''
   }
return years;
}
