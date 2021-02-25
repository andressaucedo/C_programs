#include<stdio.h>
#define IN 1        /*inside a word*/
#define OUT 0       /*outside a word*/

/*outputs input one word per line*/
int main() {
  int c;
/*set variables to 0 at start*/
  c = 0;

while ((c = getchar()) != EOF )
  {
    /*if user types blank space it will start a new line*/
    if (c == ' ' || c == '\n' || c == '\t')
    {
     printf("\n");
    }
    /*if user types characters they will output to screen*/
    else
    {
      putchar(c);
    }
  }

}
