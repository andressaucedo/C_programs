#include<stdio.h>
#define OUT 0                   //Defining variables
#define IN 1
#define HI 21
int c, i, cnt, state, ovrflo;

int wrdlng[HI];
int main()
{
printf("This program tallies the number of characters in words from input:\n");
c = i = cnt = ovrflo = 0;                  //Setting variables to 0
for (i = 0; i < HI ; i++) {
   wrdlng[i]=0;
}
state = OUT;

  while ((c = getchar()) != EOF) {

    if (c != ' ' || c != '\t' || c != '\n') {

        state = IN;
        if (state = OUT){  //beginning of new word
          ++cnt;
        }else if (state = IN){
          if (cnt >= HI) { //put characters over HI in overflow
            ++ovrflo;
          }else if (cnt < HI) { //if character count is less than HI add 1
            ++cnt;
          }
        }

    }else if (c == ' ' || c == '\t' || c == '\n') {

          if (state == IN) {    //end of word
            ++wrdlng[cnt];    //set array variable
            state = OUT;
          }
          else {
            state = OUT;
            cnt = 0;
          }
    }

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
