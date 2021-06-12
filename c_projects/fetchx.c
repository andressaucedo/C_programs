/*fetchx.c - reads as many characters dictated by the user or until the first
blank space*/
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 128
#define TRUE 1
#define FALSE 0

int fetchlimit(void); //get a number variable to use as a limit
void getinput(char *input, int num); //get string, use num from fetchlimit
char *findc(char *str); //returns pointer to found character in string or NULL
int iswithin(char *str, char *a); //returns 1 if char is in string, 0 if not.
char *stringcopy(char *s1,char *s2, int n);
char *sreverse( char *str, char *reverse);
char *stringin( char *subject, char *search);

int main(void)
{
   char input[MAX]; //array for input string
   char copy[MAX];
   char reverse[MAX];
   char search[MAX];
   char *result;
   char *found;   //pointer for lookup variable
   int fetchnum = fetchlimit();

   puts("Got it, go ahead and enter your input:");
   getinput(input,fetchnum);
   found = (findc(input)); //returns pointer to character if in string

   if(found == NULL){
    puts("Not found. Invalid character.");
    printf("%d",iswithin(input,found));
    putchar('\n');
  }
  else{
   puts(found);
   printf("%d",iswithin(input,found));
   putchar('\n');
  }
    stringcopy(copy, input, fetchnum); //my own version of strcpy()
    puts(copy);
    strcat(copy,input);
    puts(copy);
    puts(sreverse(input,reverse));

    puts("Enter a search string:");
    while(getchar() != '\n'); //clear buffer
    fgets(search,MAX,stdin);

    result = stringin(input, search);
    if(result != NULL)
      puts(result);
    else
      puts("String not found.");

   return 0;
}

//function that prompts user for a character limit
int fetchlimit(void)
{
   int  fetchnum; //variable for the number of chars to read

   puts("How many characters should I fetch?");
   scanf("%d",&fetchnum);
   while(getchar()!= '\n'); //scanf leaves a dangling newline character, this solves it
   assert(fetchnum < MAX);

   return fetchnum;
}

//function for grabbing input
void getinput(char *input, int num)
{
   int i = 0, c;
   while( i < num /*&&
   (c = getchar()) != ' ' && c != '\n' && c != '\t'*/)
   {
      c=getchar();
      input[i] = c;
      i++;
   }
   input[i] = '\0';
   for(;i <= num; i++)
      input[i] = '\0';
   puts(input);
}

// this function finds a character in a string using pointers
// if the character does not exist, a NULL pointer is returned
char *findc(char *str)
{
   char var;
   char *pos;
   int i = 0;

   puts("Enter a character to search for.");
   while(getchar() != '\n'); //empty loop to clear buffer
   (var = getchar());

   while(str[i] != var && str[i] != '\0')
   {
      i++;
   }
  if(str[i] == '\0')
      return NULL;
  else
  pos = &str[i];
return pos;
}

// this function returns 1 if a char variable exists in a string
int iswithin(char *str, char *a)
{
  int i;
  char b;
  //if pointer to char a is NULL, we want it to return a zero value
  if(a == NULL)
    return 0;
  else
    b = *a;
  //all other valid characters will return 1 if present in string
  for(i = 0; str[i] != '\0'; i++)
  {
    if(str[i] == b)
      return 1;
  }
//any other characters not null AND not present in string also return 0
return 0;
}

// my version of strncpy()
char *stringcopy(char *s1,char *s2, int n)
{
 int count = strlen(s2);
 int i;
 assert(s2 != NULL);
 for(i = 0; i < count && i <= n; i++){
   s1[i] = s2[i];
 }
return s1;
}

// function to reverse a string
char *sreverse( char *str, char *reverse)
{
char temp[MAX];
int count = strlen(str);
int i;

for(i = 0; i < count; i++)
  *(reverse + i) = str[count - (i+1)];
for(i= 0; i < count; i++)
  *(str + i) = *(reverse + i);

    return str;
}

char *stringin( char *subject, char *search)
{
  int i,j,flag,count;
  char *pos;
  flag = FALSE;
  count = strlen(search);
  //for(i=0; *(search+i) != '\0'; i++){
    for(j=0;*(subject+j) != '\0' ;j++)
      if(*(subject+j) == *search){
        *pos = *(subject+j);
        flag = TRUE;
      }


    for(i=0;*(search + i) != '\0' && flag != FALSE; i++)
      if(*(search+i) != *(pos +i))
        flag = FALSE;

    if(flag == TRUE)
      return pos;
    else
      return NULL;
  }
