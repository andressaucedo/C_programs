#include<stdio.h>
#define MAX 10
#define COUNT 63
int compare(char input[], char refer[]);


int main(void)
{
   char input[MAX];
   char characters[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
   int i,c,index;

   while(c != EOF){
      printf("Enter characters to search:\n");
      fflush(stdin);
      for(i=0;(c=getchar()) != '\n'; i++)
         input[i]=c;
      i++;
      input[i] = '\0';
      compare(input,characters);
   }


   return 0;
}

int compare(char input[], char refer[])
{
int i,j,pos; //variables for beginning and ending of string in input
char begin, ending;
   for(i=0; input[i] != '\0';){ //control loop to read entire input

         //if case is "num-num"
      if(input[i] != '-' && input[i+1] == '-' && input[i+2] != '\n' && input[i+2] != '-'){
            begin=input[i];
            ending=input[i+2];
            i+=3;
         //if case is "-num"
      }else if(input[i] == '-' && input[i+1] != '\n' && input[i+1] != '-'){
            begin=refer[0];
            ending=input[i+1];
            i+=2;
         // if case is "num-"
      }else if(input[i] != '-' && input[i+1] == '-' && input[i+2] == '\n'){
            begin=input[i];
            ending=refer[COUNT];
            i+=2;
      }else if(input[i] != '-' && input[i+1] == '-' && input[i+2] == '-'){
            begin=input[i];
            ending=refer[COUNT];
            i+=2;
         // if case is simply '-'
      }else if(input[i] == '-' && input[i+1] == '\n'){
            begin=refer[0];
            ending=refer[COUNT];
            i+=2;
      }


         for(j=0; refer[j] != begin; j++)
            ;
         for(;refer[j] != ending;j++)
            printf("%c",refer[j]);
         printf("%c\n",refer[j]);

   }
   return 1;
}
