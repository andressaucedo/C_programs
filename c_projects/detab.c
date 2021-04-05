#include<stdio.h>
#define TAB 5

int main()
{
  char replacer = 'x'; //replacement char for tab
  int pos = 1; //array position
  int c, tc;

while((c=getchar()) != EOF){
    if (c == '\t'){
      tc = TAB - pos % TAB;
      while(tc > 0){
        putchar(replacer);
        --tc;
        ++pos;
      }
    }else if (c == '\n'){
      putchar(c);
        pos = 1;
    }else{
      putchar(c);
      ++pos;
    }

  }
  return 0;
}
