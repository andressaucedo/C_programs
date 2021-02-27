#include<stdio.h>
#define OUT 0                   //Defining variables
#define IN 1
#define HI 21
int c, i, cnt, state, ovrflo;
int wrdlng[HI];

int main()
{
c = i = cnt = ovrflo = 0;                  //Setting variables to 0
for (i = 0; i < HI ; i++) {
   wrdlng[i]=0;
}
state = OUT;

  while ((c = getchar()) != EOF) {

    if (c != ' ' || c != '\t' || c != '\n') {
      if (state = OUT){  //beginning of new word
        cnt = 1;    //reset count
        state = IN;
      }else if (state = IN){
        if (cnt >= HI) { //put characters over HI in overflow
          ++ovrflo;
          state = IN;
        }else if (cnt < HI) { //if character count is less than HI add 1
          ++cnt;
          state = IN;
        }
      }
    }else if (c == ' ' || c == '\t' || c == '\n') {

          if (state == IN) {    //end of word
            ++wrdlng[cnt];    //set array variable
            state = OUT;
          }
          else {state = OUT;}
    }
  }

  for (i = 0; i < HI; i++) {
    printf("%i", wrdlng[i]);
  }
    printf("\n overflow = %i", ovrflo);
    printf("\n");

  return 0;
}
