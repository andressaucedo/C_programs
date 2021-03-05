#include<stdio.h>
#define MAXLINE 300
#define HILINES 50


char test[MAXLINE];
char longest[MAXLINE];
char data[MAXLINE];
int i , c, cnt, x, z;

int main() {
cnt=x=0;


  for(i=0, x=0;(c = getchar()) != EOF ; i++, x++){
      if( c == '\n'){     //if input is '\n' replace with null char and exit
        test[i] = '\0';   // loop (x becomes character counter)
        goto LINEND;
      }else{
        test[i] = c;
      }
  }
  LINEND:
  for(z=0; z < (x+1); z++){
    longest[z] = test[z];
  }

  printf("%s %d\n", longest, x);
  return 0;
}
