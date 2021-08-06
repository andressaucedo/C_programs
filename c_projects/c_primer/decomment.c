#include<stdio.h>
#define HI 2000
int read(char block[]);

//this program eliminates /* */ type comments
//from C source code
int main(){
char srccode[HI];
int limit; //the length of the input
int i,c,pos;

   limit = read(srccode);
   for(i=0; i < limit-1 ;i++){
      if(srccode[i] == '/' && srccode[(i+1)] == '*'){
         pos=i;
         i += 2;
         while( srccode[i] != '*' && srccode[i+1] != '/'){
         i++;
         }
         ++i;
         for(;i > pos-1; --i){
            srccode[i] = '\b';
         }
      }
   }
printf("%s\n",srccode);
   return 0;
}

//function reads input, returns program length
int read(char block[])
{
int limit;
int i,c;

   for(i=0; (c=getchar()) != EOF; i++){
      block[i]=c;
   }
   limit = i+1;
   block[limit]='\0';

  return limit;
}
