#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#define NUM1 10
#define MAX 256

int getinput( char strings[][MAX]);
int menu(void);
void printlist( char strings[][MAX], int count);
void alphasort( char strings[][MAX], int count);
void strlongsort(char strings[][MAX], int count);
void wordlongsort(char strings[][MAX], int count);


int main(void) {
  char arraycopy[NUM1][MAX];
  char array[NUM1][MAX];
  int count,menuchoice;
  int i;
  count = getinput(array);
  printf("%d\n", count);

  //copy input array to modifiable copy
  for(i=0; i < count; i++)
    strcpy(arraycopy[i],array[i]);

  do{
    menuchoice = menu();
    switch(menuchoice)
    {
      case 1:
      printlist(array,count);
      break;

      case 2:
      alphasort(arraycopy,count);
      putchar('\n');
      printlist(arraycopy,count);
      break;

      case 3:
      strlongsort(arraycopy,count);
      printlist(arraycopy,count);
      break;

      case 4:
      wordlongsort(arraycopy,count);
      printlist(arraycopy,count);
      break;

      case 5:
      break;

    }
  }while(menuchoice != 5 || isdigit(menuchoice) != 0);

return 0;
}

//gets up to 10 strings or til EOF, returns the number of strings
int getinput(char strings[][MAX])
{
  int i=0;
  int count = 0;
  char ch;
  puts("Enter 10 phrases.");
  while(i < NUM1 && fgets(strings[i], MAX, stdin) != NULL && strcmp(strings[i], "\n\0") != 0){
    count++;
    i++;
  }
// This commented out block was input by char but input by line is easier
/*
  for(i=0; i < NUM1 ; i++){
    for(j=0;(ch = getc(stdin)) != '\n' && j < MAX; j++)
      strings[i][j] = ch ;

    if(ch == EOF){
      for(; i < NUM1; i++)
        strings[i][0]= '\0';
        break;
    }
    if(ch == '\n'){
      strings[i][j] = '\0';
      count++;
    }
  }
*/
return count;
}

//prints a menu and returns the choice as int
int menu(void)
{
  int choice,ch;
  char ans[4];
  do{
    printf(    "***********************************************************\n"
    "* 1.) Print list          2.) Print Alphabetized List     *\n"
    "* 3.) List by Line length 4.) Sort by first word length   *\n"
    "* 5.) Quit                                                *\n"
    "***********************************************************\n"
    "Enter a menu item number: ");

    fgets(ans,sizeof ans,stdin);
    choice = atoi(ans);
  }while(isdigit(choice) != 0);
  return choice;
}

//prints out the normal list of strings by lines
void printlist( char strings[][MAX],int count)
{
  int i;
  for(i=0; strings[i] != NULL && i < count; i++)
  if(strings[i][0] != '\0')
    fputs(strings[i],stdout);
}

//sorts strings according to ASCII collating sequence
void alphasort( char strings[][MAX], int count)
{
  char temp[MAX];
  int i,j,val;

  for(i=0;i < count-1; i++)
    for(j=i+1;j < count; j++)
    {
    val = strcmp(strings[i],strings[j]);
    if(val > 0){
      strcpy(temp,strings[j]);
      strcpy(strings[j],strings[i]);
      strcpy(strings[i],temp);
    }
  }

}

//sort array by string length
void strlongsort(char strings[][MAX], int count)
{
  int i,j;
  char temp[MAX];
  for(i=0; i < (count -1); i++)
    for(j=i+1; j < count; j++)
      if( strlen(strings[i]) > strlen(strings[j]) )
      {
        strcpy(temp, strings[i]);
        strcpy(strings[i], strings[j]);
        strcpy(strings[j], temp);
      }
}

//sorts array of strings by length of first word in strings
void wordlongsort(char strings[][MAX], int count)
{
  int wordlength[NUM1];
  char tempstr[MAX];
  char stringscopy[NUM1][MAX];
  int tempint;
  int i,j;
  //this loop finds the length of the words and stores them in an
  //array named wordlength[]
  for(i=0; strings[i]!= NULL && i < count; i++)
    for(j=0; strings[i][j] != '\0' && strings[i][j] != ' ' && strings[i][j] != '\n' && strings[i][j] != '\t'; j++)
      wordlength[i] = j+1;
//!!! something wrong with this section
  for(i=0; i < (count - 1); i++)
    for(j=(i+1); j < count; j++){
      if(wordlength[i] > wordlength[j]){
        tempint = wordlength[i];
        wordlength[i] = wordlength[j];
        wordlength[j] = tempint;
        //worldength[] keeps count and any changes we do to it
        //must also be done to the strings[] array
        strcpy(tempstr,strings[i]);
        strcpy(strings[i],strings[j]);
        strcpy(strings[j], tempstr);
      }
    }
//print arrays
  for(i=0;i<count;i++)
    printf("%d\n", wordlength[i]);
  putchar('\n');

/*  for(i=0;i<count;i++)
    fputs(strings[i],stdout);
*/
}
