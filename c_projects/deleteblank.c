#include<stdio.h>
#define MAX 1000
int getl(char line[]);
void delete(char line1[], char line2[]);

int main()
{
char input[MAX];
char output[MAX];

  while(getl(input) > 0){
      delete(input,output);
      printf("%s", output);
  }

return 0;
}


//function get a line from input and end it after a newline
int getl(char line[]){
int i, c;

  for(i=0; (c=getchar()) != EOF && c != '\n'; i++){
    line[i] = c;
  }if (c == '\n'){
    line[i] = c;
    ++i;
  }
  line[i]='\0';

return i;
}

//function to delete blanks and tabs from input
void delete(char line1[], char line2[]){
int i=0; int x=0;

  while(line1[i] != '\n'){
    if(line1[i] != '\t' && line1[i] != ' '){
      line2[x] = line1[i];
      ++i; ++x;
    }else{
      ++i;
    }
  }
  if(line1[i] == '\n'){
    line2[x] = '\n';
    ++x;
    line2[x] = '\0';
  }

}
