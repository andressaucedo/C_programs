#include<stdio.h>
#define MAX 1000

void reverso(char line[], char enil[]);
int getl(char line[]);

//this program gets a line from input, reverses it and outputs on screen
int main(){
int length;
char line[MAX];
char enil[MAX];

  while(getl(line) > 0){
    reverso(line,enil);
    printf("%s\n",enil);
  }

return 0;
}
//copy array1 in reverse into array2
void reverso(char line[], char enil[]){
int i=0; int x=0; int length=0;

  while(line[i] != '\0'){ //this section finds the first string length
    i++;
  }
  if(line[i] == '\0'){
    --i;
    length = i;
  }
  for(i=0, x=length; line[i] !='\0'; ++i, --x){
    enil[x]=line[i]; //copies first element of line1 to end of line2 etc.
  }
  if(line[i]=='\0'){ //when line1 ends, adds null character to end of line2
    enil[i]='\0';
  }
}

//function get a line from input and end it after a newline
int getl(char line[]){
int i, c;

  for(i=0; (c=getchar()) != EOF && c != '\n'; i++){
    line[i] = c;
  }if (c == '\n'){
    line[i]='\0';
  }

return i;
}
