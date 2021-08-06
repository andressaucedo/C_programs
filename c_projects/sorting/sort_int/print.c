/* print.c -- prints an array */
#include <stdio.h>
void print(int array[], int limit)
{
  int index;

  for (index = 0; index < limit; index++){
    printf("%d\n",array[index]);
  }
}
