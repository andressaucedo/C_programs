#include<stdio.h>
#define MAX 1000
void squeeze(char string[], char test[]);
//this program checks string one against string two and deletes any
//characters in string one that appear in string two
int main()
{
   int i,c,j;
   char one[MAX], two[MAX];
   printf("Enter line: \n");
   for(i=0; (c=getchar()) != EOF && c != '\n'; i++){
      one[i] = c;
   }
   one[++i] ='\0';
   printf("Enter exclusion characters: \n");
   for(j=0; (c=getchar()) != EOF && c != '\n'; j++){
      two[j] = c;
   }
   two[++j] ='\0';

   squeeze(one,two);
   printf("%s\n", one);


return 0;
}

void squeeze(char string[], char test[])
{
   int i, j, x;

      //starts loop and increments string until end of string
      for(i=0; string[i] != '\0'; i++){
         //checks element in string against each test element
         for(j=0; test[j] != '\0'; j++){
            //test string element against test, shift and test again
            while(string[i] == test[j]){
               for(x=i; string[x] != '\0' ;x++){
               string[x] = string[x+1];
               }
            }
         }
      }



}
