#include<stdio.h>
#define OUT 0                   //Defining variables
#define IN 1
#define HI 15
int c, i, cnt, state, ovrflo;
int wrdlng[HI];

int main()
{
printf("This program tallies the number of characters in words from input:\n");
c = i = cnt = ovrflo = 0; //Setting variables to 0
for (i = 0; i < HI ; i++) {
   wrdlng[i]=0;
}
state = OUT;

  while ((c = getchar()) != EOF) {

    if (c == ' ' || c == '\t' || c == '\n') {
          state = OUT;
          if (cnt > 0) {    //end of word
            if(cnt < HI){
              ++wrdlng[cnt];    //set array variable
            }
            else{
              ++ovrflo;
            }
          }
          cnt = 0;
    }
    else  //user types in characters that aren't blank
      if (state == OUT) {  //beginning of new word
        cnt = 1;    //reset count
        state = IN;
      }
      else{
          ++cnt;
      }
          state = IN;


  }

  printf("\n");
  for (i = 1; i < HI; i++) { //prints array, omitting 0th element
    printf("%2i ", wrdlng[i]);
  }
  printf("\n");
  for (i = 1; i < HI; i++) { //prints labels
    printf("%2i ", i);
  }

    printf("\n overflow = %i", ovrflo);
    printf("\n");

  return 0;
}
