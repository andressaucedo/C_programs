#include<stdio.h>
#define TAB 5

int main()
{
  int c, i;
  int position=1;
  int spacecount=0;
  int tabcount=0;

  for(i=0;(c=getchar()) != EOF;i++){
    if(c != ' ' && c!= '\t' && c != '\n'){
      putchar(c);
      position++;

    }else if(c == ' '){
      position++;
      spacecount++;
        if(spacecount > 1){
          while(TAB - position % TAB > 1){
          putchar('\t');
          }
          if(TAB - position % TAB == 1){
          putchar(' ');
          }

        }
    }else if(c == '\t'){
      tabcount++;
      putchar('\t');
    }else if(c == '\n'){
      putchar(c);
      position = 1;

    }
  }


  return 0;
}
