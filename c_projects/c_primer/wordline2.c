#include<stdio.h>

#define IN 1      // inside a word
#define OUT 0     // outside a word

//print one word per line from input
main()
{

  int c, state;
  state = OUT;

  while ((c=getchar()) != EOF) {

    if (c==' '||c=='\t'||c=='\t'){  //user inputs blank marking the
          if (state=IN) {           //end of a word and printing /n
            putchar('\n');
            state=OUT;
            }
    }
    else if (state=OUT) {      //if it was the end of a word but now
            state=IN;         //input is not blank, print input
            putchar(c);       //not really necessary except it flags
                              //the state of the word as IN now
    }
  else
  putchar(c);                //if input is not blank print input

  }
}
