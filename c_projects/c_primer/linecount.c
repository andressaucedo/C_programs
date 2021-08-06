
#include<stdio.h>

/*count lines in input*/
main()
{
  int c, nl, t, b;

  nl = 0;

printf("This program displays the newlines, tabs and blanks from input.\n");
printf("To exit type Ctrl+d\n" );
printf("***************************************************************\n");
  while ((c = getchar()) != EOF)
      if (c == '\n')
        ++nl;
      if (c == '\t')
        ++t;
      if (c == " ")
        ++b;
/*outputs the newlines, tabs and blanks */
    printf("%d\n", nl "newlines");
    printf("%d\n", t "tabs");
    printf("%d\n", b "blanks");
}
