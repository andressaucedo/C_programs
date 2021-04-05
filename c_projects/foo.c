#include<stdio.h>
float cuber(float value);

int main()
{
   float value;

   printf("Enter a value: ");
   scanf("%f",&value);
   printf("%.3f cubed is %.3lf\n",value,cuber(value));


return 0;
}

float cuber(float value)
{
   value = value * value * value;
   return value;
}
