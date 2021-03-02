#include<stdio.h>
int sample[6]={1,2,3,4,5,6};
int i;


main() {
  for (i = 0; i < 7 ; i++) {

    while (sample[i] >= i) {
      printf("#");
      i++;
    }
    printf("\n");

  }
return 0;
}
