#include <stdio.h>
#define MAX 500
  int input(char line[]);
  void copy(char to[], char from[]);


int input(char line[]) // gets input line, returns line count to main
{
  int c, count;
  for (count=0;(c=getchar()) != EOF && c != '\n';count++) {
        line[count] = c;
    }
  if (c == '\n'){
        line[count] = c;
        ++count;
  }
  line[count] = '\0';
return count;
}

void copy(char to[], char from[]) //copies one array to another
{
  int i = 0;
  while (from[i] != '\0'){
    to[i] = from[i];
    i++;
  }

}

int main() // this program compares line lengths and returns the longest
{
char currentline[MAX];
char longestline[MAX];
int length = 0; int hicount = 0; int a, b, c;

  while((length = input(currentline)) > 0){
    if(length > hicount){
      hicount = length;
      copy(longestline,currentline);
    }
  }


   printf("\n%d :",hicount);
for (a = 0, b =1; a < hicount; a++, b++){
  if (longestline[a] != '\t'&& longestline[a] != ' '){
    printf("%c", longestline[a]);
  }else if (longestline[a]==' ' && longestline[b]!=' ' && longestline[b]!='\t'){
    printf("%c", longestline[a]);
  }else if (longestline[a] == '\t'){
    longestline[a] = ' ';
    --a, --b;
  }
}
   return 0;
}
