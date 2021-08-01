/* getint.c -- gets and int for getarray() */
#include<stdio.h>
#include "getint.h"
int getint(int * ptint)
{
  int status;
  char skip;
  status = scanf("%d",ptint);

//  To check the input and return status, decomment the line below.
//  printf("%d status: %d\n",*ptint,status);

if(status == NONUM) // if input is not an integer
{
    scanf("%c",&skip); // then scan for a character
    if (skip == '#')  // define the exit character
    {
      status = EXIT;
    }
    while(getchar() != '\n'); // clean up trailing input characters
}
return status;
}
