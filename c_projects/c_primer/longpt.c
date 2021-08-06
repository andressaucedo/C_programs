#include<stdio.h>
#define MAX 1000
#define LNG 80
int yankline(char line[]);


int main(){
char mainline[MAX];
int length = 0;

  while((length = yankline(mainline)) > 0 ){
    if(length > LNG){
      printf("\n%s\n", mainline);
    }else{
      length = 0;
    }
  }

return 0;
}

// This function grabs a line from input and ends it after a newline
int yankline(char line[]){
int c, i;

  for(i=0; (c=getchar()) != EOF && c != '\n'; i++){
    line[i]=c;
  }
  if (c == '\n'){
      line[i]=c;
      i++;
      line[i]='\0';
  }


return i;
}
