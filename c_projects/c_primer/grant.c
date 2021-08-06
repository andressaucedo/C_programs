#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 40
#define NUMANSWERS 3
int main()
{

   int flag = 1;
   char try[MAX];
   char tryup[MAX];
   char trylo[MAX];
   char answer[NUMANSWERS][MAX] = {
      {"Grant"},
      {"GRANT"},
      {"grant"}
   };

   puts("At any time, type \"quit\" to end program.\n");
   puts("Who is buried in Grant's tomb?");
   fgets(try,MAX,stdin);
   try[strcspn(try,"\n")] = '\0';

      for(int i = 0; i < NUMANSWERS; i++)
      {
      flag = strcmp(try, answer[i]);
      if(flag == 0)
         break;
      }

         while(flag != 0 && strcmp(try,"quit") != 0)
         {
            puts("No, that's wrong. Try Again.");
            fgets(try,MAX,stdin);
            try[strcspn(try,"\n")] = '\0';

            for(int i = 0; i < NUMANSWERS; i++)
            {
              flag = strcmp(try, answer[i]);
              if(flag == 0)
                 break;
            }
         }
   if(strcmp(try,"quit") == 0)
      return 0;
   else
   puts("That's right!");

   return 0;
}
