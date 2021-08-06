#include<stdio.h>

#define LOWER 0     /*lower limit*/
#define UPPER 300   /*upper limit*/
#define STEP 20     /*increment*/

float cnvrt(float f, float c);

/* print Fahrenheit-Celsius table*/
int main()
{
  float fahr;
  float celsius;
  fahr = celsius = 0;
printf("Fahr  Celsius\n");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP){
    printf("%3.0f = %3.2f\n",fahr, cnvrt(fahr,celsius));
  }

return 0;
}

float cnvrt(float f, float c)
{

//for (f = UPPER; f >= LOWER; f= f - STEP){
  c = (5.0/9.0)* (f-32);
//}

return c;
}
