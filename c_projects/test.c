#include<stdio.h>
#define ASCII 97

int main(void)
{
char a,b,c;
int x=1;
   while(x > 0){
      x=0;
      printf("Enter: \n");
      x += scanf("%c",&a);
      x += scanf("%c",&b);
      x += scanf("%c",&c);
      if( c == '\n' && a == '-')
      {
         c=b;
         if(b >= ASCII)
            a='a';
         else
            a='A';
      }else if( c=='\n' && b =='-'){
         if(a >= ASCII)
            c = 'z';
         else
            c = 'Z';
      }
      for(;a <= c; a++)
         printf("%c",a);
      printf("\n");
   }
return 0;
}
