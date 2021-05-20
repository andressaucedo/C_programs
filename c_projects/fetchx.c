/*fetchx.c - reads as many characters dictated by the user or until the first
blank space*/
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 128
void getinput(char *input, int num);
int fetchlimit(void);
char *findc(char *str);

int main(void)
{
   char input[MAX]; //array for input string
   char *found;
   int fetchnum = fetchlimit();

   puts("Got it, go ahead and enter your input:");
   getinput(input,fetchnum);

   found = (findc(input));
   puts(found);
   putchar('\n');

   return 0;
}

//function for grabbing input
void getinput(char *input, int num)
{
   int i = 0, c;
   while( i < num &&
   (c = getchar()) != ' ' && c != '\n' && c != '\t')
   {
      input[i] = c;
      i++;
   }
   input[++i] = '\0';
   putchar('\n');

   puts(input);
      getchar();
}

//function that prompts user for a character limit
int fetchlimit(void)
{
   int  fetchnum; //variable for the number of chars to read

   puts("How many characters should I fetch?");
   scanf("%d",&fetchnum);
   getchar(); //scanf leaves a dangling newline character, this solves it
   assert(fetchnum < MAX);

   return fetchnum;
}

char *findc(char *str)
{
   char var;
   char *pos;
   int i = 0;

   getchar();
   puts("Enter a character to search for.");
   while(getchar() != '\n') //empty loop to clear buffer
   ;
   (var = getchar());

   while(str[i] != var)
   {
      i++;
   }
   pos = &str[i];
return pos;
}
