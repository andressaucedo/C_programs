// myatoi.h - command line implementation of atoi()
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int myatoi(char *str);

int main(int argc, char *argv[]) {
  if(argc != 2){
    fputs("Usage: myatoi string\n",stderr);
    return 1;
  }

  printf("%d\n",myatoi(argv[1]));
  return 0;
}

int myatoi(char *str)
{
  int i,x,flag;

  if(str[0] == '-')
    flag = -1;
  //find range of string
  for( i = 0 ; str[i] != '\0'; i++)
  ;
  i-= 1;
  int val;

  //turn string to int
  for(x=1;(isdigit(str[i]))!= 0 && i >= 0;(x *= 10), i--)
    val += (str[i] - 48) * x;

  //if str is a negative number
  if(flag == -1)
    val *= flag;

  return val;
}
