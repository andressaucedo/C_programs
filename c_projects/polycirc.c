#include<stdio.h>
#include<math.h>
#define PI 3.14159

double circlecalc(int opt, float radius);
double polycalc(int opt, int sides, float length);
int main(void)
{
   float radius, length;
   int choice, circle, sides, polygon;

   printf("Are you calculating for a circle or an equilateral polygon?\n");
   printf("1: Circle\n");
   printf("2: Polygon\n");
   scanf("%i",&choice);
   choice = (choice > 1)? 2:1;

   if(choice == 1){
      printf("Are you calculating diameter, circumference or area?\n");
      printf("1: diameter\n");
      printf("2: circumference\n");
      printf("3: area\n");
      scanf("%i",&circle);
      printf("What is the length of the radius? : ");
      scanf("%f",&radius);
      printf("The result is : %lf\n", circlecalc(circle,radius));

   }else if(choice == 2){
      printf("Are you calculating perimeter or area?\n");
      printf("1: perimeter\n");
      printf("2: area\n");
      scanf("%i",&polygon);
      printf("How many sides does the polygon have? :");
      scanf("%i",&sides);
      printf("How long is one side (numbers only): ");
      scanf("%f",&length);
      printf("The result is : %lf\n", polycalc(polygon,sides,length));

   }

return 0;
}
//this function calculates variables for circles
double circlecalc(int opt, float radius)
{
   double result;
   switch(opt)
   {
      case 1:
         result = 2 * radius;
         break;
      case 2:
         result = 2*PI*radius;
         break;
      case 3:
         result = PI * (radius *= radius);
         break;
      default:
         result = 0;
         printf("Invalid option!\n");
         break;
   }
   return result;
}

// this function calculates variables for polygons
double polycalc(int opt, int sides, float length)
{
   double result;
   switch(opt)
   {
      case 1:
         result = length * sides;
         break;
      case 2:
        result = ((length *= length) * sides) / (4 * (tan(180/sides)));
         break;
      default:
         result = 0;
         printf("Invalid option!\n");
         break;
   }
   return result;
}
