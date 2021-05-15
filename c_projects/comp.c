#include<stdio.h>
#include<string.h>
#define STOP "quit"
#define SIZE 81

int main(void)
{
   static char input [SIZE];

   puts("What's the password?");
   fgets(input,SIZE,stdin);
   input[strcspn(input,"\n")] = '\0';
   while(strcmp(input, "banana") == 0 ||strcmp(input, "BANANA") == 0  || strcmp(input, "Banana") == 0 )
   {
      puts("That's right! Welcome to the party!");
      input[0] = '\0';
      puts("What's the password?");
      fgets(input,SIZE,stdin);
      input[strcspn(input,"\n")] = '\0';
   }
   if(strcmp(input,STOP) == 0)
      puts("Ok, bye then.");
   else
      puts("Begone, foul wretch!");
   return 0;
}
