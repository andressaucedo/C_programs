// stringplayin.c - shows how fgets,puts and strcat work by taking
// input and concatenating two strings.
#include<stdio.h>
#include<string.h>
#define MAXLENGTH 80
char *input(char *a);

char main(void)
{
   char input1[MAXLENGTH];
   char input2[MAXLENGTH];

   puts("This program concatenates two strings, let's begin.\n\n"
   "Please enter the first string:");

   //collect input and print onscreen for string 1
   *input(input1);
   puts(input1);
   puts("\n");


   puts("Please enter the second string:");

   //collect input and print onscreen for string 2
   *input(input2);
   puts(input2);

   //concatenize string 2 to string 1
   strcat(input1,input2);
   puts("\n");

   //output the concatenated string
   puts(input1);
   printf("string length: %ld\n",strlen(input1));
   return 0;
}

char *input(char *a)
{
//we use fgets() instead of gets() because the latter does not check
//for buffer overflow and can overwrite or corrupt adjoining memory
fgets(a,MAXLENGTH,stdin);
a[strcspn(a,"\n")] = '\0'; /*calculates up to newline and replaces with a null character*/

return a;
}
