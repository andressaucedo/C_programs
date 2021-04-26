//
#include<stdio.h>
#define LOWER_A 97
#define LOWER_Z 122
#define UPPER_A 65
#define UPPER_Z 90
int is_letter(int input);
int alpha_place(int input);

int main()
{
      int c;
      printf("Please enter character(s) to asess:\n");

      while((c=getchar()) != EOF){
         if(is_letter(c) == 1)
            printf("The input character \'%c\' IS a letter.\n"
            "It is the number %d letter in the alphabet."
            "\n\n", c,alpha_place(c));
         else if( c == '\n'){
            printf("The Newline character is NOT a letter\n");
            continue;
         }
         else
            printf("The character \'%c\' is NOT a letter"
            " of the alphabet.\n\n", c);
      }
return 0;
}

//is_letter - checks wether input is part of the alphabet
int is_letter(int input)
{
      if(input >= UPPER_A && input <= UPPER_Z)
         return 1;
      else if (input >= LOWER_A && input <= LOWER_Z)
         return 1;
      else
         return 0;
}

//alpha_place - returns the place of the letter in the alphabet
int alpha_place(int input)
{
   int place;

   if(input >= UPPER_A && input <= UPPER_Z)
      place -= (UPPER_A - 1);
   else if (input >= LOWER_A && input <= LOWER_Z)
      place -= (LOWER_A - 1);

      return place;
}
