// rphrase.c - exercise for printing and saving strings recursively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char *reverse( char *str1, char *str2, int count, int index);

int main(int argc, char *argv[])
{
int length = strlen(argv[1]);
(assert(argc == 2));
int i = 0;
char *string = argv[1];
char copy[128]; //copy needs allocated memory or it won't work
reverse(string,copy,length,i);
printf("original string is now: %s\n", string);
  return 0;
}

//Reverses str1 and copies it to str2 and back. Reversed string is
//returned to main()
char *reverse( char *str1, char *str2, int count,int index)
{
  if(count < 0){
    strcpy(str1,str2);
    return str1;
  }
  *(str2 + index) = *(str1 + (count-1));
    reverse(str1,str2,--count,++index);
}
//because each recursion uses its' own variables, we need to pass all
//the necessary information through the function header
