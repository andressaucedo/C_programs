#include<stdio.h>
#define HI 1000
#define WRAP 60
int getlines(char line[], int limit);
int stringlong(char line[]);


//this program wraps lines at a preset marker
int main(){
int pos; //position in line
int length; //length of string
char string[HI]; //array holding line
int i;

  getlines(string,HI);
  length=stringlong(string);
  printf("%d\n",length);
  pos=length;

  //decrement position to WRAP or multiple of WRAP
  while(pos < HI && (pos % WRAP) > 0){
    pos--;
//if the wrapping point lands on a space, make newline
  }if((pos % WRAP) == 0 && string[pos] == ' '){
    string[pos]= '\n';
//if not, make newline at first space available before wrap
  }else{
    while(string[pos] != ' '){
      pos--;
          //if no spaces by halfway, hyphenate the line
          if(pos == (WRAP/2)){
            for(i=length; i >= (WRAP-1);i--){
              string[i+2]=string[i];
            }
          string[(WRAP-1)]='-';
          string[WRAP]='\n';
          }
    }
  }
  string[pos]='\n';

  printf("%s\n",string);
  return 0;
}

// function to get a line of input
int getlines(char line[],int limit)
{
  int i,c;

  for(i=0; i < limit && (c=getchar()) != EOF && c != '\n'; i++){
  line[i]=c;
  }
  if(c == '\n'){
    line[i]=c;
    ++i;
    line[i]='\0';
  }else if(i > limit){
    printf("*Maximum line length exceeded.\n");
  }
  return i;
}

//function to find the length of a string and number of spaces
int stringlong(char line[])
{
  int i=0;

  while(line[i] != '\n'){
    i++;
  }
  return i;
}
