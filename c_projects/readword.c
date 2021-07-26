/*readword.c -- read a word from a file without the space, tab or newline after*/
#include<stdio.h>
int readword(FILE *file);

int main(void)
{
  FILE *file;
  file=fopen("tester.txt","r");

  readword(file);
return 0;
}
int readword(FILE *file)
{
  char ch;
  int count=0;
  while( (ch = fgetc(file)) != ' ' && ch != '\t' && ch != '\n'){
    putc(ch,stdout);
    count++;
  }
  ungetc(ch,file);

return count;
}
