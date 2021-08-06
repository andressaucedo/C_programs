#include<stdio.h>
#define OUT 0   //out of a word
#define IN 1    //inside a word
#define HI 15   //max word length
#define BAR 20  //max graph bar size (occurrences of word size)

int c, i, cnt, state, ovrflo;
int wrdlng[HI]; //word length array
int wrdtotl;  //word count total

int main()
{
printf("This program counts and graphs the number of characters in words from input (Press ctrl-d to exit input and output results)\n");
printf("The maximum word length is set at %d characters: \n",(HI - 1));

c = i = cnt = ovrflo = 0;             //Setting variables to 0
for (i = 0; i < HI ; i++) {
   wrdlng[i]=0;
}
state = OUT;

  while ((c = getchar()) != EOF) {

    if ((c != '\n') && (c != '\t') && (c != ' ')) { //if input is not blank

        if (state == OUT){  //beginning of new word
          cnt = 1;
          state = IN;
        }else { //in middle of a word
            ++cnt;
        }

    }else {  //if input is blank
      state = OUT;

            if( cnt < HI) {    //end of word
            ++wrdlng[cnt];    //set array variable
           }
            else {
              ++ovrflo;
            }

       cnt = 0;
    }

  }
/////////////////////////start word count/////////////////////
wrdtotl = 0;
for (i = 1; i < HI; i++) {
  wrdtotl = (wrdlng[i] + wrdtotl);
}
wrdtotl = (wrdtotl + ovrflo);
/////////////////////////start histogram /////////////////////
  printf("\n");
  int x;
  for(x = BAR; x > 0; x--){ // vertical loop
    printf("%2d ",x);    //print graph labels
    for (i = 1; i < HI; i++) { //horizontal loop
      if (wrdlng[i] >= x) {
        printf(" | ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("   ");
    for (i = 1; i < HI; i++) { //prints array, omitting 0th element
      printf("%2i ", wrdlng[i]);
    }
    printf(" Ocurrences");
    printf("\n");

    printf("   ");
    for (i = 1; i < HI; i++) { //prints labels
      printf("%2i ", i);
    }
    printf(" Word Length");
    printf("\n");

    printf("\n overflow = %i", ovrflo);
    printf("        word total =%d\n", wrdtotl);



  return 0;
}
