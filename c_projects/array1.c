#include<stdio.h>
/*create a histogram of word lengths*/

int main()
{
  int c, i, nc;
  int ndigit[10];


  for ( i = 0; i < 10; i++)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c != ' ' || c != '\n' || c != '\t')
      ++nc;
      ++ndigit[nc-'0'];
      else if (c == ' ' || c == '\n' || c == '\t')





  for (i = 0; i < 10; i++)
    printf(" %d\n",ndigit[i]);
  return 0;

}
