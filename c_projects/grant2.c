#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 40
int main()
{

   int i = 0;
   char try[MAX];
   static char answer[] = "grant";

   puts("At any time, type \"quit\" to end program.\n");
   puts("Who is buried in Grant's tomb?");
   fgets(try,MAX,stdin);
   try[strcspn(try,"\n")] = '\0';

      while(try[i] != '\0')
      {
         try[i] = tolower(try[i]);
         i++;
      }
      while(strcmp(try,answer) != 0 && strcmp(try,"quit") != 0)
      {
         puts("No, that's wrong. Try Again.");
         fgets(try,MAX,stdin);
         try[strcspn(try,"\n")] = '\0';
         i = 0;
         while(try[i] != '\0')
         {
            try[i] = tolower(try[i]);
            i++;
         }
      }

   if(strcmp(try,"quit") == 0)
      return 0;

   else
      puts("That's right!");

   return 0;
}
