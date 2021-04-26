#include<stdio.h>
void starbar(void);
int min(int x, int y);
int menu(void);
void chline(char ch,int i, int j);
void chblock(char ch,int x, int y);
double harmonic_mean(double x, double y);
void sub_and_add(int *x, int *y);

int main()
{
   int x,y;
   double xd,yd;
   char a;

   switch(menu())
   {
      case 1:
         printf("Enter x: ");
         scanf("%d",&x);
         printf("Enter y: ");
         scanf("%d",&y);
         printf("The lower number is %d\n",min(x,y));
         break;

      case 2:
         printf("Enter a minimum: \n");
         scanf("%d",&x);
         printf("Enter a maximum: \n");
         scanf("%d",&y);
         while( x > y || x < 0){
            printf("Invalid input, try again.\n");
            printf("Enter a minimum: ");
            scanf("%d",&x);
            printf("Enter a maximum: ");
            scanf("%d",&y);
         }
      printf("Enter a character: \n");
      while(getchar() != '\n');
      scanf("%c",&a);
      chline(a,x,y);
         break;

      case 3:
         printf("Enter x: ");
         scanf("%d",&x);
         printf("Enter y: ");
         scanf("%d",&y);
         printf("Enter a character: \n");
         while(getchar() != '\n');
         scanf("%c",&a);
         chblock(a,x,y);
         break;

      case 4:
      printf("Enter a double: ");
      scanf("%lf",&xd);
      printf("Enter another double: ");
      scanf("%lf",&yd);
      printf("The harmonic mean is %lf\n",harmonic_mean(xd,yd));
      break;

      case 5:
      printf("Enter an integer: ");
      scanf("%d", &x);
      printf("Enter an integer: ");
      scanf("%d", &y);
      sub_and_add(&x,&y);
      printf("The sum of the two integers is: %d\n"
            "The difference of the two integers is: %d\n",x,y);
      }


   return 0;
}
//This function finds the smaller of two given values
int min(int x, int y)
{
   int answer;
   return (x<y)?x:y;
}

//This function prints a character from columns i-j
void chline(char ch, int i, int j)
{
   int count;
   for(count=0; count < i; count++)
      putchar(' ');
   for(count = i; count <= j; count++)
      printf("%c", ch);
   printf("\n");

}

// This function prints a block of characters for given columns and lines
void chblock(char ch,int x, int y)
{
   int count,count2;
   for(count2 = 0;count2<=y;count2++){
      for(count=0;count<=x;count++)
         printf("%c",ch);
   printf("\n");
   }
}

//This function displays a menu
int menu(void)
{
   int choice;
   starbar();
   do{
   printf("1) find minimum value\n"
         "2) print a character line\n"
         "3) print character lines and columns\n"
         "4) harmonic mean\n"
         "5) pointer add/subtract\n"
         "6) quit\n");
   starbar();
   printf("\nEnter a menu choice: ");
   }while(scanf("%d", &choice) != 1);

   return choice;
}

//This function prints a bar of stars
void starbar(void)
{
   int i;
   for(i=0; i < 41; i++)
      printf("*");
   printf("\n");
}

//This function finds the harmonic mean of two doubles
double harmonic_mean(double xd, double yd)
{
   xd = 1/xd;
   yd = 1/yd;
   double avg = xd + yd;
   avg /= 2;

   return 1/avg;
}


//This function gives the sum and difference of two integers
void sub_and_add(int *x, int *y)
{
   int temp;
   temp = *x;
   *x += *y; //sum of the two
   *y -= temp;
      if(*y < 0)
         *y *= -1;
}
