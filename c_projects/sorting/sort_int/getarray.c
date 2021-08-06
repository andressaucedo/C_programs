/* getarray.c -- reads in an array*/
#include <stdio.h>
#include "getint.h" //declares getint() constants

int getarray(int array[], int limit)
{
  int num, status;
  int index = 0;    //array index

  printf( "This program stops reading numbers after %d \n"
          "Enter # to quit entering numbers.\n" ,limit);
  while (index < limit && (status = getint(&num)) != EOF && status != EXIT)
  {
    if (status == YESNUM)
    {
      array[index++] = num;
      printf("The number %d has been accepted.\n",num);
    }
    else if (status == NONUM)
    {
      printf("That is not an integer. Try again.\n");
    }
    else
    {
      printf("This can't happen! Something is very wrong.\n");
    }
  }
    if (index == limit) //report if array gets filled
      printf("All %d elements of the array were filled.\n",limit);

return(index);
}
