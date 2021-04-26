#include<stdio.h>
#define LOW_A 97
#define LIMIT 26

int main(void){
char lower[LIMIT];
int i,j;
   for(i=0, j=LOW_A; i < LIMIT; i++){
      lower[i]=j++;
   }
   lower[i]='\0';
   printf("%s\n",lower);

   return 0;
}
