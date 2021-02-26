#include<stdio.h>

#define IN 1      // inside a word
#define OUT 0     // outside a word
#define MAXWORD 11  //the maximum word length
#define MAXHIST 15  //the maximum histogram length

//print a histogram for word lengths
main()
{

  int c, i, nc, state;
  int len;      //length of each bar
  int maxvalue; //maximum value for wl[]
  int ovflow; //number of words over the max word lengths
  int wl[MAXWORD]; //DEFINING THE ARRAY WITH MAXWORD AS THE ELEMENTS

  state = OUT; //set start to be "out of a word"
  nc=ovflow=0; //set variables to 0
  for (i = 0; i < MAXWORD; i++) //use for loop to set array elements
  {                              //to 0
       wl[i]=0;
  }

  while ((c=getchar()) != EOF) {

    if (c==' '||c=='\t'||c=='\n'){  //user inputs blank
        state = OUT;                //state is OUT of word
        if (nc > 0)
                       //if nc is greater than 0
              if (nc < MAXWORD)    //but less than the max word length
                ++wl[nc];         //add 1 to the element 'nc' in array
              else                 //if it is not more than 0 or more than
                ++ovflow;           //max word length, add 1 to overflow

        nc = 0;           //set 'nc' to 0
    }
    else if (state == OUT) {    //if inpt is not blank but state is out
        state = IN;             //make state IN or 1
        nc=1;                    // start word
    }else                       //if input is not blank and state is IN
        ++nc;                   //add one to character count inside word

  maxvalue = 0;
    for(i = 1; i < MAXWORD; ++i)  //set loop to add 1 to 'i' as long as
        if(wl[i] > maxvalue)     //value is less than max
          maxvalue = wl[i];
    for(i = 1; i < MAXWORD; ++i){
        printf("%5d - %5d :", i, wl[i]);
        if (wl[i] > 0) {
          if ((len = wl[i] * MAXHIST / maxvalue) < 0)
            len = 1;
          }else
          len = 0;
        while (len > 0) {
          putchar('*');
          --len;
        }
        putchar('\n');
    }
  if (ovflow > 0)
    printf("There are %d words greater than %d\n", ovflow, MAXWORD);
}
}
