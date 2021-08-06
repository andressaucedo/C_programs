#include<stdio.h>
#define MAX 10
#define COUNT 63
void expand(char s1[],char s2[]);
//int compare(char input[], char refer[]);


int main(void)
{
   char input[MAX];
   char output[COUNT];
   /*char characters[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};*/
   int i,c;

   while(c != EOF){
      printf("Enter characters to search:\n");
      for(i=0;(c=getchar()) != '\n'; i++)
         input[i]=c;
      i++;
      input[i] = '\0';
      expand(input,output);
      printf("%s\n",output);
   }



   return 0;
}

void expand(char s1[],char s2[])
{
   char c;
   int i,j;

   i=j=0;
   while((c=s1[i++]) != '\0') //fetch a char from s[1]
      if(s1[i] == '-' && s1[i+1] >= c){
         i++;
         while(c < s1[i]) //expand shorthand
            s2[j++] = c++;
      }else
         s2[j++] = c; //copy the character
   s2[j] = '\0';
}

/*int compare(char input[], char refer[])
{
char begin, ending;
int i,j,pos;
int a,b,c;

   for(i=0; input[i] != '\0';i++){ //control loop to read entire input
      a=i;b=i+1;c=i+2; //creating easy to read variables for i, i+1, i+2

      if(input[a] == '-'){ //if first character is a dash
          begin=refer[0];

         if(input[b] == '\n'){ //if second character is newline
            ending=refer[COUNT-1];
            i=b;
         }if(input[b] == '-'){ //if second character is a dash
            i=b;
         }else{ //if second character is some other character
            ending=input[b];
            i=b;
         }
      }else if(input[a] != '-'){ //if first character is not a dash
         begin=input[a];

         if(input[b] == '\n'){ //if second character is newline
            i=b;
         }if(input[b] == '-'){ //if second character is dash
            //if third character is not newline or dash
            if(input[c] != '-' && input[c] != '\n'){
               ending=input[c];
               i=c;
            }else if(input[c] == '\n'){ //if third character is newline
               ending=refer[COUNT-1];
               i=c;
            }
         }
      }

         for(j=0; refer[j] != begin; j++)
            ;
         for(;refer[j] != ending;j++)
            printf("%c",refer[j]);
         printf("%c\n",refer[j]);

   }
   return 1;
}
*/
