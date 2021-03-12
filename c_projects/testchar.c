#include<stdio.h>
#define MAXLINE 300
#define HILINES 50

int getline(char line[], int max);
void copy(char, char);

int main() {
//char test[MAXLINE];
char longest[MAXLINE];
char line[MAXLINE];
int len; // current line length
int max = 100; // max length so far
int i;

getline(line[i], max);
printf("%s\n", line);
printf("%i\n", i);
  return 0;
}

int getline( char test[], int limit){
int i, x, z, c;
    for(i=0, x=0;(c = getchar()) != EOF; i++, x++){
        if( c == '\n' || c >= limit){     //if input is '\n' replace with null char and exit
          test[i] = '\0';   // loop (x becomes character counter)
          goto LINEND;
        }else{
          test[i] = c;
        }
    }
    LINEND:
    //for(z=0; z < (x+1); z++){
    //  longest[z] = test[z];
    //}

return i;
}

// copy: copy 'from' into'to; assume 'to' is big enough
void copy(char to[], char from[]){
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
