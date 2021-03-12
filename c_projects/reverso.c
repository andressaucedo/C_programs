#include<stdio.h>
#define MAX 1000

void reverso(char line[], char enil[]);
int getl(char line, int index);

int main(){
int length,index;
char line[MAX];
char enil[MAX];
  while((length = getl(line,index)) > 0){
    reverso(line,enil);
  printf("\n%s\n%s\n",line,enil);
  }

return 0;
}
//copy array1 in reverse into array2
void reverso(char line[], char enil[]){
int i; int x=0;int length=0;
  for(i=0; line[i] != '\0'; ++i)
  if(line[i] == '\0'){
    --i;
    i = length;
  }
  for(i=0, x=length; line[i] !='\0'; ++i, --x){
    enil[x]=line[i];
  }if(line[i]=='\0'){
    enil[i]='\0';
  }
}

//function get a line from input and end it after a newline
int getl(char line, int index){
int i, c;

  for(i=0; (c=getchar()) != EOF && c != '\n'; i++){
    line[i] = c;
  }if (c = '\n'){
    line[i] = c;
    i++;
    line[i] = '\0';
  }

return i;
}
