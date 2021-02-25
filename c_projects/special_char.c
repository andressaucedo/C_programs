
#include<stdio.h>

/*count lines in input */
int main()
{
  int c, nl, t, b, ch;
/* defining baseline for variables newline, tab and blanks */
    nl = 0;
    t = 0;
    b = 0;
    ch = 0;
printf("This program displays the newlines, tabs and blanks and characters from input.\n");
printf("To exit press Ctrl+d\n" );
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
else
      {
        ++ch;
      }

      printf("%i tabs\n", t);
      printf("%d newlines\n", nl);
      printf("%i blanks\n", b);
      printf("%i characters\n", ch);
return 0;
}
