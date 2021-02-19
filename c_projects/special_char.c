
#include<stdio.h>

/*count lines in input */
int main()
{
  int c, nl, t, b;
/* defining baseline for variables newline, tab and blanks */
    nl = 0;
    t = 0;
    b = 0;

printf("This program displays the newlines, tabs and blanks from input.\n");
printf("To exit type Ctrl+d\n" );
printf("***************************************************************\n");

  while ((c = getchar()) != EOF)
      if (c == '\n')
        {
          ++nl;
        }
else
      if (c == '\t')
        {
          ++t;
        }
else
      if (c == ' ')
        {
          ++b;
        }

      printf("%i tabs\n", t);
      printf("%d newlines\n", nl);
      printf("%i blanks\n", b);
return 0;
}
